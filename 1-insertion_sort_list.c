#include "sort.h"

/**
 * swp - function that sorts a doubly linked list of integers.
 * @list: double pointer to the list.
 * @min: pointers with the minimum value.
 * @max: Doubly Pointers the value.
 */
void swp(listint_t **list, listint_t *min, listint_t **max)
{
	(*max)->next = min->next;
	if (min->next)
		min->next->prev = *max;
	min->prev = (*max)->prev;
	min->next = *max;
	if ((*max)->prev)
		(*max)->prev->next = min;
	else
		*list = min;
	(*max)->prev = min;
	*max = min->prev;
	print_list(*list);
}

/**
 * insertion_sort_list - function that sorts a doubly linked list.
 * @list: double pointer for the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *min, *max, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	for (min = (*list)->next; min; min = temp)
	{
		temp = min->next;
		max = min->prev;

		while (max && min->n < max->n)
		{
			swp(list, min, &max);
		}
	}
}
