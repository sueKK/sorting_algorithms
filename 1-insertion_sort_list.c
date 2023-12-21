#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list -This function Sorts a doubly linked list
 * of integers in ascending  order
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;

	while (current)
	{
		temp = current->next;

		while
		(current->prev && current->n < current->prev->n)
		{
			current->prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = current->prev;

			current->next = current->prev;
			current->prev = current->prev->prev;

			if (current->prev != NULL)
				current->prev->next = current;

			current->next->prev = current;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);
		}
		current = temp;
	}
}
