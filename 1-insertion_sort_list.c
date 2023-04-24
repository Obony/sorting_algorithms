#include "sort.h"

/**
*len_list -	Returns the length of a doubly linked list
*@head:     Pointer to the Doubly Linked List
*
* Return:	Length of Doubly Linked List
*/
int len_list(listint_t *head)
{
	int len = 0;

	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}

/**
* swap_nodes - Swap two adjusent nodes in list
* @head:    A pointer to the head of the double-linked list
* @nodeP1:  A pointer to the first node to swap
* @nodeP2:  A pointer to the second node to swap
*/
void swap_nodes(listint_t **head, listint_t **nodeP1, listint_t *nodeP2)
{
	(*nodeP1)->next = nodeP2->next;
	if (nodeP2->next != NULL)
		nodeP2->next->prev = *nodeP1;
	nodeP2->prev = (*nodeP1)->prev;
	nodeP2->next = *nodeP1;
	if ((*nodeP1)->prev != NULL)
		(*nodeP1)->prev->next = nodeP2;
	else
		*head = nodeP2;
	(*nodeP1)->prev = nodeP2;
	*nodeP1 = nodeP2->prev;
}


/**
* insertion_sort_list -   sorts a Doubly Linked List
*                           using the Insertion Sort Algorithm
* @list:    A pointer to the head of doubly linked list of integers
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, *tmp;

	if (list == NULL || *list == NULL || len_list(*list) < 2)
		return;

	for (i = (*list)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		j = i->prev;
		while (j != NULL && j->n > i->n)
		{
			swap_nodes(list, &j, i);
			print_list((const listint_t *)*list);
		}
	}
}
