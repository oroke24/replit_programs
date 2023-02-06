//Creator: jamie O'roke
//Date: 11/4/22
//program that sorts, ascending or descending 
//Enjoy!!
#include "functions.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {

  if (usage_statement(argc, *argv[1])) return 0; //Base Case

  int size = argc;
  int number_list[size];

  printf("You entered %d arguments\n", size);

  copy_list(number_list, argv, size);

  printf("Before sort: ");
  display_list(number_list, size);

  begin_sort(number_list, *argv[1], size);

  printf("After sort: ");
  display_list(number_list, size);
  
  return 0;
}