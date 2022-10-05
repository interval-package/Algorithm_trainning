//
// Created by Zza on 2022/9/23.
//

#include "stdlib.h"

typedef struct MyLinkedList{
    union {
        int val;
        int size;
    };
    struct MyLinkedList* next;
    struct MyLinkedList* prev;
} MyLinkedList;

// 我们使用头结点操作

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* ptr = malloc(sizeof(MyLinkedList));
    ptr->next = ptr;
    ptr->prev = ptr;
    ptr->size = 0;
    return ptr;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size) return -1;
    index++;
    while (index--){
        obj = obj->next;
    }
    return obj->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* temp = malloc(sizeof(MyLinkedList));
    temp->val = val;
    obj->size++;

    temp->prev = obj;

    temp->next = obj->next;
    obj->next = temp;

    temp->next->prev = temp;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* temp = malloc(sizeof(MyLinkedList));
    temp->val = val;
    obj->size++;

    temp->next = obj;

    temp->prev = obj->prev;
    obj->prev = temp;

    temp->prev->next = temp;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index < 0) myLinkedListAddAtHead(obj, val);
    if(index > obj->size)return;

    MyLinkedList* temp = malloc(sizeof(MyLinkedList));
    temp->val = val;
    obj->size++;

//    index++;
    while (index--){
        obj = obj->next;
    }

    temp->prev = obj;

    temp->next = obj->next;
    obj->next = temp;

    temp->next->prev = temp;
//    myLinkedListAddAtHead(obj,val);
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size) return;
    obj->size--;
//    index++;
    while (index--){
        obj = obj->next;
    }
    MyLinkedList *temp = obj->next;
    temp->next->prev = obj;
    obj->next = temp->next;
    free(temp);
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *temp, *cur=obj->next;
    while (cur != obj){
        temp = cur->next;
        free(cur);
        cur = temp;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/

int main(){
    MyLinkedList* obj = myLinkedListCreate();
    myLinkedListAddAtHead(obj,1);
    myLinkedListAddAtTail(obj,3);
    myLinkedListAddAtIndex(obj,1,2);
    myLinkedListFree(obj);
}