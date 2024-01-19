#include "sort.h"

/**
 *insertion_sort_list - insertion sort using doubly linked list
 *@list: list of an items to be sorted
 *
 *Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur_node, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	cur_node = (*list)->next;

	while (cur_node)
	{
		temp = cur_node->next;

		while (cur_node->prev != NULL && cur_node->n < cur_node->prev->n)
		{
			cur_node->prev->next = cur_node->next;

			if (cur_node->next != NULL)
				cur_node->next->prev = cur_node->prev;

			cur_node->next = cur_node->prev;
			cur_node->prev = cur_node->prev->prev;

			if (cur_node->prev != NULL)
				cur_node->prev->next = cur_node;
			else
				*list = cur_node;
			if (cur_node->next != NULL)
				cur_node->next->prev = cur_node;

			print_list(*list);
		}
		cur_node = temp;
	}
}
