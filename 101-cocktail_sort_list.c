#include "sort.h"

/**
 * len_list -   returns the length of a doubly linked list
 * @head:       pointer to the list
 *
 * Return: length of list
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
* swap_node_front - Swap node in Double Linked List with node
*                   in front of it
* @list:            A pointer to head of the doubly linked list
* @endptr:          Pointer to the 2nd last node of list.
* @iptr:            Pointer to the current node of the cocktail
*                   cocktail shaker alogrithm.
*/
void swap_node_front(listint_t **list, listint_t **endptr, listint_t **iptr)
{
	listint_t *tmp = (*iptr)->next;

	if ((*iptr)->prev != NULL)
		(*iptr)->prev->next = tmp;
	else
		*list = tmp;

	tmp->prev = (*iptr)->prev;
	(*iptr)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *iptr;
	else
		*endptr = *iptr;

	(*iptr)->prev = tmp;
	tmp->next = *iptr;
	*iptr = tmp;
}

/**
* swap_node_behind -    Swap node in the list with node behind it
* @list:                Pointer to the head of the doubly Linked List
* @endptr:              Pointer to 2nd last node of the Linked List
* @iptr:                Pointer to the current swapping node of the
*                       Cocktail Shaker Algorithm
*/
void swap_node_behind(listint_t **list, listint_t **endptr, listint_t **iptr)
{
	listint_t *tmp = (*iptr)->prev;

	if ((*iptr)->next != NULL)
		(*iptr)->next->prev = tmp;
	else
		*endptr = tmp;

	tmp->next = (*iptr)->next;
	(*iptr)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *iptr;
	else
		*list = *iptr;

	(*iptr)->next = tmp;
	tmp->prev = *iptr;
	*iptr = tmp;
}

/**
* cocktail_sort_list -  Sorts Doubly Linked List using
*                       Cocktail Shaker
* @list:                Pointer to head of the Doubly
*                       Linked List
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *endptr, *iptr;
	bool swapped_flag = true;

	if (list == NULL || *list == NULL || len_list(*list) < 2)
		return;

	/* Set endptr */
	for (endptr = *list; endptr->next != NULL;)
		endptr = endptr->next;

	while (swapped_flag == true)
	{
		swapped_flag = false;
		for (iptr = *list; iptr != endptr; iptr = iptr->next)
		{
			if (iptr->n > iptr->next->n)
			{
				swap_node_front(list, &endptr, &iptr);
				print_list((const listint_t *)*list);
				swapped_flag = true;
			}
		}
		for (iptr = iptr->prev; iptr != *list; iptr = iptr->prev)
		{
			if (iptr->n < iptr->prev->n)
			{
				swap_node_behind(list, &endptr, &iptr);
				print_list((const listint_t *)*list);
				swapped_flag = true;
			}
		}
	}

}
