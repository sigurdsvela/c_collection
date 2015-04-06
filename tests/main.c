#include <stdio.h>
#include <stdlib.h>
#include "../arraylist.h"

void assert(int i1, int i2, char *msg) {
  printf("assert:");
  if (i1 != i2) {
    printf("failed");
    if (msg != NULL) {
      printf(" with message: ");
      printf("%s", msg);
    }
    printf("\n");
    return;
  }
  printf("OK\n");
}

void passert(void* p1, void* p2, char* msg) {
  printf("assert:");
  if (p1 != p2) {
    printf("failed");
    if (msg != NULL) {
      printf(" with message: ");
      printf("%s", msg);
    }
    printf("\n");
    return;
  }
  printf("OK\n");
}

int main(int argc, char** argv) {
  printf("Running tests...\n");

  //Init array
  arraylist* list = arraylist_new(10);
  assert(list->size, 16, "Wrong init size");
  assert(list->stkpnt, 0, "Wrong init stack pnt");

  //Push to array
  printf("Pushing:\n");
  for (int i = 0; i < 100; i++) {
    int *val = (int*)malloc(sizeof(int));
    *val = i;
    arraylist_push(list, (void*)val);
  }
  printf("OK\n");

  //Test Array
  assert(list->stkpnt, 100, "Stack pointer at wrong positiong");
  assert(*(int*)arraylist_get(list, 0), 0,   "Index 0 has wrong value");
  assert(*(int*)arraylist_get(list, 10), 10, "Index 10 has wrong value");
  assert(*(int*)arraylist_get(list, 34), 34, "Index 34 has wrong value");
  assert(*(int*)arraylist_get(list, 54), 54, "Index 54 has wrong value");

  passert(arraylist_get(list, 100), NULL, "Failed to get out of bounds index");

  //Test Set
  int *tt = malloc(sizeof(int));
  *tt = 33;
  int *temp = arraylist_get(list, 22);
  arraylist_set(list, 22, tt);
  assert(*(int*)arraylist_get(list, 22), 33, "Set Failed");
  arraylist_set(list, 22, temp);
  free(tt);

  //Pop Array
  for (int i = 99; i >= 0; i--) {
    int *val = arraylist_pop(list);
    assert(*val, i, NULL);
    free(val);
  }

  //Free Array
  arraylist_free(list);
}
