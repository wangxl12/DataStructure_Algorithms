/**
 * 哈希表的开放地址法创建
 * 当发现哈希值处于冲突的时候，根据某种策略，从h出发找到下一个不冲突的位置
 */
#include<cstdio>
#include<cstdlib>

#define base 13
using namespace std;

typedef struct {
    int *arr;
} HASH;

HASH *initHash() {
    HASH *map = (HASH *) malloc(sizeof(HASH));
    map->arr = (int *) malloc(sizeof(int) * base);
    for (int i = 0; i < base; i++) {
        map->arr[i] = -1;
    }
    return map;
}

int exists(HASH *map, int key) {
    if (key < 0) {
        printf("the value of key must >= 0!");
        exit(-1);
    }
    for (int i = 0; i < base; i++) {
        if (map->arr[i] == key) return i;
    }
    return -1;
}

int hashFunction(int key) {
    return key % base;
}

HASH *add(HASH *map, int key) {
    if (exists(map, key) == -1) {  // 如果不存在，就添加
        int p = hashFunction(key);
        if (map->arr[p % base] != -1) { // 如果待插入的位置已有元素，则往后移动
            int count = 0;
            while (map->arr[p % base] != -1) {
                p++;
                count++;
                if (count > base) {
                    printf("the hash list is full now!Can not insert the value of %d!\n", key);
                    return map;
                }
            }
        }
        map->arr[p % base] = key;
    }
    return map;
}

HASH *remove(HASH *map, int key) {
    int index = exists(map, key);
    if (index != -1) {
        map->arr[index] = -1;
    }
    return map;
}

void freeHash(HASH *map) {
    free(map->arr);
    free(map);
}

void display(HASH *map) {
    for (int i = 0; i < base; i++) {
        printf("%d ", map->arr[i]);
    }
    printf("\n");
}

int main() {
    HASH *obj = initHash();
    add(obj, 4);
    add(obj, 12);
    add(obj, 17);
    add(obj, 23);
    add(obj, 23);
    add(obj, 28);
    for (int i = 0; i < 8; i++) {
        add(obj, 17 + 13 * (i + 1));
    }
    add(obj, 17 + 13 * (8 + 1));
    display(obj);
    remove(obj, 121);
    display(obj);
    add(obj, 17 + 13 * (8 + 1));
    display(obj);
    freeHash(obj);
    return 0;
}




