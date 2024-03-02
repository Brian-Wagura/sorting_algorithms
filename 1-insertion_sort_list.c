#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: The list to be sorted
 * @node1: The first node to be swapped
 * @node2: The second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node2->prev = node1->prev;
	node2->next = node1->next;

	if (node1->next == node2)
	{
		node1->prev = node2;
		node1->next = NULL;
	}
	else
	{
		node1->prev = node2;
		node1->next = node2->next;
	}

	if (node2->prev)
		node2->prev->next = node1;
	else
		*list = node1;

	node2->next = node1;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using insertion sort algrithm
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			swap_nodes(list, temp->prev, temp);
			print_list(*list);
		}
	}
}
