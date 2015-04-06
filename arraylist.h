// #ifndef __ARRAYLIST_H__
// #define __ARRAYLIST_H__

#define ARRAYLIST_OK 0;
#define ARRAYLIST_OUT_OF_BOUNDS 1;

/*
ArrayList:
Resizes itself when needed.
The size of the allocated memory block
will allways be 2^x. This means than on
N pushes there will be log2(n) memory reallocations.
*/

struct arraylist {
  int size; //<- Size (How much room) of underlying array
  int stkpnt; //<- Stack Pointer, synonomous with length
  void** array; //The array
};

typedef struct arraylist arraylist;

/*
Create a new list
*/
arraylist* arraylist_new(int initSize);

/*
Free the list
*/
void arraylist_free(arraylist *list);

/*
Push an element to the end of the list
This is the only was to increase the size
of the list

returns status
*/
int arraylist_push(arraylist *list, void* value);

/*
Remove and return the last element in the list
Returns NULL if the list is empty
*/
void* arraylist_pop(arraylist *list);

/*
Return an arbitrary index form the array
NULL is returned if index is out of bounds
*/
void* arraylist_get(arraylist *list, int index);

/*
Set an arbitrary element in the array.

The arraylist will <b>not</b> resize to fit automagically
if the index is out of bounds
*/
int arraylist_set(arraylist *list, int index, void *value);

/*
Get the length of the list. AKA, how many elements are in the list
*/
int arraylist_length(arraylist *list);

/*
Calculate the required size if to hold <em>int size</em>
elements
*/
static int arraylist_required_size(int size);

/*
Resize the underlying array to fit <em>int size</em>
elements
*/
static void arraylist_resize_to_fit(arraylist *list, int size);
