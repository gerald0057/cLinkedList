/**
 * @file cDuLinkedList.h
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

#ifndef __CDULINKEDLIST_H
#define __CDULINKEDLIST_H

#ifdef __cplusplus
extern "C" {
#endif

#define cdll_malloc malloc
#define cdll_free free

typedef struct list_node {
    struct list_node *next;
    struct list_node *prev;
} list_t;

list_t *cdll_list_new(void);
void cdll_list_delete(list_t *list);
void cdll_node_insert_after(list_t *l, list_t *n);
void cdll_node_insert_before(list_t *l, list_t *n);
void cdll_node_remove(list_t *n);
int cdll_node_isempty(const list_t *l);
unsigned int cdll_list_length(const list_t *l);

#define cdll_list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - (unsigned long)(&((type *)0)->member)))

#ifdef __cplusplus
}
#endif

#endif /* __CDULINKEDLIST_H */
