#ifndef SEARCH_ALOGS_H
#define SEARCH_ALOGS_H

#include <stddef.h>
#include <stdio.h>

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
void print_array(int *array, size_t left, size_t right);

#endif
