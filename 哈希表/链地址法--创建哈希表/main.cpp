#include<iostream>
#include<cstdlib>
#include<cstdio>

#define base 11
using namespace std;

struct Link {
    int val;
    struct Link *next;
};

typedef struct HASH {
    struct Link *link;
};

int hashFunction(int key){
    /**
     * ��ϣ����
     */
    if(key < 0){
        printf("the value must >= 0!");
        exit(-1);
    }
    return key % base;
}

HASH *createHash() {
    /**
     * ������ϣ������ֵ��ʼ��Ϊ-1
     */
    HASH *obj = (HASH *) (malloc(sizeof(HASH)));
    obj->link = (struct Link *) (malloc(sizeof(struct Link) * base));
    // ��ʼ��
    for(int i = 0;i < base; i++){
        obj->link[i].val = -1;
        obj->link[i].next = NULL;
    }
    return obj;
}

bool exists(HASH* obj, int key){
    /**
     * �жϹ�ϣ�����Ƿ���ڼ�key
     */
    struct Link* p = &obj->link[hashFunction(key)];
    for(;p != NULL; p = p->next){
        if(p->val == key) return true;
    }
    return false;
}
void add(HASH* obj, int key){
    /**
     * �����ǰ��ϣ�����м�ֵkey�������в�����û�����
     */
     if(!exists(obj, key)){
         struct Link* p = &obj->link[hashFunction(key)];
         for(;p->next != NULL;p = p->next);
         p->next = (struct Link* ) malloc(sizeof(struct Link));
         p->next->val = key;
         p->next->next = NULL;
     }
}
void del(HASH* obj, int key){
    /**
     * �����ǰ��ϣ�����м�ֵkey��ɾ��
     */
     if(exists(obj, key)){
         struct Link* p = &obj->link[hashFunction(key)];
         for(;p->next->val != key; p = p->next);
         struct Link* temp = p->next;
         p->next = p->next->next;
         free(temp);
     }
}
void freeHash(HASH* obj){
    /**
     * �ͷ�����Ķ�ջ�ռ�
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
}

void display(HASH* obj){
    /**
     * ��ʽ�������ϣ���е�����
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
    del(obj, -1);
    display(obj);
    freeHash(obj);
    return 0;
}
