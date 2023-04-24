#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 1.
 * @true: Equals 0.
 */
typedef enum bool
{
	true = 0,
	false
} bool;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void swap_values(int *array, int i, int j, int size);
int lomuto_partition(int *array, int low, int high, int size);
void recursive_partition(int *array, int low, int high, int size);
void quick_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
int len_list(listint_t *);
void swap_nodes(listint_t **, listint_t **, listint_t *);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_node_front(listint_t **, listint_t **, listint_t **);
void swap_node_behind(listint_t **, listint_t **, listint_t **);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void array_split_recursive(int *, int *, size_t, size_t);
void merge_subarr(int *, int *, size_t, size_t, size_t);
void swap_ints(int *, int *);
void bitonic_merge(int *, size_t, size_t, size_t, char);
void bitonic_sort(int *array, size_t size);
void bitonic_seq(int *, long unsigned int, size_t, long unsigned int, char);
void swap_ints(int *, int *);
int hoare_partition(int *, size_t, int, int);
void hoare_sort(int *, size_t, int, int);
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */
