/**
 * @file cDuLinkedList.c
 * @brief
 * @author ZhuHongyu
 * @version 0.0.1
 * @date 2020-11-06
 *
 * @copyright Copyright (c) 2020 Shanghai AURE Fluidics Development Team
 *
 * @par Change Logs:
 * <table>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2020-11-06 <td>0.0.1     <td>ZhuHongyu     <td>the first version
 * </table>
 */

#include "cDuLinkedList.h"

#include <stdlib.h>

list_t *cdll_list_new(void) {
    list_t *list = (list_t *)cdll_malloc(sizeof(list_t));
    if (NULL == list) {
        return NULL;
    }

    list->next = list->prev = list;

    return list;
}

void cdll_list_delete(list_t *list) {
    if (list) {
        cdll_free(list);
    }
}

void cdll_node_insert_after(list_t *l, list_t *n) {
    l->next->prev = n;
    n->next = l->next;
    l->next = n;
    n->prev = l;
}

void cdll_node_insert_before(list_t *l, list_t *n) {
    l->prev->next = n;
    n->prev = l->prev;
    l->prev = n;
    n->next = l;
}
void cdll_node_remove(list_t *n) {
    n->next->prev = n->prev;
    n->prev->next = n->next;
    n->next = n->prev = n;
}

int cdll_node_isempty(const list_t *l) { return (l->next == l); }

unsigned int cdll_list_length(const list_t *l) {
    unsigned int len = 0;
    const list_t *p = l;
    while (p->next != l) {
        p = p->next;
        len++;
    }

    return len;
}
