#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./cDuLinkedList.h"

typedef struct {
    char name[16];
    uint32_t flag;
    list_t list;
} dataStruct_t;

void test1_init() {
    list_t *handle = cdll_list_new();
    if (NULL == handle) {
        return;
    }

    dataStruct_t *payLoad_1 = (dataStruct_t *)malloc(sizeof(dataStruct_t));
    strcpy(payLoad_1->name, "the first node");
    payLoad_1->flag = 1;
    cdll_node_insert_before(handle, &(payLoad_1->list));

    dataStruct_t *payLoad_2 = (dataStruct_t *)malloc(sizeof(dataStruct_t));
    strcpy(payLoad_2->name, "the second node");
    payLoad_2->flag = 2;
    cdll_node_insert_before(handle, &(payLoad_2->list));

    dataStruct_t *policeMan;
    struct list_node *node = handle->next;
    printf("============== test1 =============\n");
    for (; node != handle; node = node->next) {
        policeMan = cdll_list_entry(node, dataStruct_t, list);
        printf("name=%s,\tflag=%d\n", policeMan->name, policeMan->flag);
    }

    free(payLoad_1);
    free(payLoad_2);
    cdll_list_delete(handle);
}

int main() {
    test1_init();

    return 0;
}