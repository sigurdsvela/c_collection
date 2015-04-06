#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "arraylist.h"

arraylist* arraylist_new(int initSize) {
	initSize = arraylist_required_size(initSize); //Make size a valid size

	arraylist* list = (arraylist*)malloc(sizeof(arraylist));

	list->stkpnt = 0;
	list->size   = initSize;
	list->array  = (void**)malloc(sizeof(void*)*initSize);

	return list;
}

void arraylist_free(arraylist *list) {
	free(list->array);
}

int arraylist_push(arraylist *list, void* value) {
	//Resize underlying array if needed
	if (list->stkpnt == list->size) arraylist_resize_to_fit(list, list->size+1);

	//Push value, then incriment stack pnt
	list->array[list->stkpnt++] = value;
	return ARRAYLIST_OK;
}

void* arraylist_pop(arraylist *list) {
	if (list->stkpnt == 0) return NULL;
	//If one forth or less of array is occupied, then we can resize the size of the array
	if (list->stkpnt <= list->size/4) arraylist_resize_to_fit(list, list->stkpnt);
	//Decrease the stack pnt, and return value
	return list->array[--(list->stkpnt)];
}

int arraylist_set(arraylist *list, int index, void *value) {
	if (!(index >= 0 && index < list->stkpnt)) return ARRAYLIST_OUT_OF_BOUNDS;
	list->array[index] = value;
	return ARRAYLIST_OK;
}

void* arraylist_get(arraylist *list, int index) {
	if (!(index >= 0 && index < list->stkpnt)) return NULL;
	return (list->array)[index];
}

int arraylist_length(arraylist *list) {
	return list->stkpnt;//return the stack pointer
}

static void arraylist_resize_to_fit(arraylist *list, int size) {
	size = arraylist_required_size(size);
	list->size  = size;
	list->array = (void**)realloc(list->array, sizeof(void*)*size);
}

static int arraylist_required_size(int size) {
	return (int)pow(2, ceil(log2(size)));
}
