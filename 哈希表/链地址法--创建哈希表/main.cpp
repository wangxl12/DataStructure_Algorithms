#include<iostream>
#include<cstdlib>
#include<cstdio>

#define base 11
using namespace std;

struct Link {
    int val;
    struct Link *next;
};

typedef struct {
    struct Link *link;
}HASH;

int hashFunction(int key){
    /**
     * 哈希函数
     */
    if(key < 0){
        printf("the value must >= 0!");
        exit(-1);
    }
    return key % base;
}

HASH *createHash() {
    /**
     * 创建哈希表，并将值初始化为-1
     */
    HASH *obj = (HASH *) (malloc(sizeof(HASH)));
    obj->link = (struct Link *) (malloc(sizeof(struct Link) * base));  // link数组中每一个值存放的是相应的链表长度
    // 初始化
    for(int i = 0;i < base; i++){
        obj->link[i].val = 0;
        obj->link[i].next = NULL;
    }
    return obj;
}

bool exists(HASH* obj, int key){
    /**
     * 判断哈希表中是否存在键key
     */
    struct Link* p = &obj->link[hashFunction(key)];
    if(p->val == 0) return false;  // 如果该链表长度为0，则肯定不存在key
    for(;p != NULL; p = p->next){
        if(p->val == key) return true;
    }
    return false;
}
void add(HASH* obj, int key){
    /**
     * 如果当前哈希表中有键值key，不进行操作，没就添加
     */
    if(!exists(obj, key)){
        struct Link* p = &obj->link[hashFunction(key)];
        p->val++;
        for(;p->next != NULL;p = p->next);
        p->next = (struct Link* ) malloc(sizeof(struct Link));
        p->next->val = key;
        p->next->next = NULL;
    }
}
void del(HASH* obj, int key){
    /**
     * 如果当前哈希表中有键值key，删除
     */
    if(exists(obj, key)){
        struct Link* p = &obj->link[hashFunction(key)];
        p->val--;
        for(;p->next->val != key; p = p->next);
        struct Link* temp = p->next;
        p->next = p->next->next;
        free(temp);
    }
}
void freeHash(HASH* obj){
    /**
     * 释放申请的堆栈空间
     */
    for(int i = 0;i < base; i++){
        struct Link* temp = NULL;
        for(struct Link *p = obj->link[i].next; p != NULL;){
            temp = p;
            p = p->next;
            free(temp);
        }
    }
    free(obj->link);
    free(obj);
}

void display(HASH* obj){
    /**
     * 格式化输出哈希表中的内容
     */
    struct Link* p = &obj->link[0];
    for(int i = 0; i < base; i++){
        struct Link* p = &obj->link[i];
        while(p != NULL){
            printf("%d -> ", p->val);
            p = p->next;
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    HASH* obj = createHash();
//    display(obj);
    add(obj, 4);
    add(obj, 12);
    add(obj, 17);
    add(obj, 23);
    add(obj, 23);
    add(obj, 28);
    display(obj);
    del(obj, 12);
    display(obj);
    freeHash(obj);
    return 0;
}
