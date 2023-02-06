#include <stdbool.h>
#include <stdio.h>

bool usage_statement(int argument_cout, char sort_type); 
bool copy_list(int number_list[], char* to_copy[], int size);
bool begin_sort(int number_list[], char sort_type, int size);
bool ascending_sort(int number_list[], int size);
bool descending_sort(int number_list[], int size);
bool display_list(int number_list[], int size);

//usage_statement does all of the error handling.
//copy_list takes two lists and copies the first one from the second.
//begin_sort decides which order to sort the list of numbers.
//ascending_sort takes in a list and sorts it into ascending order.
//descending_sort takes in a list and sorts it into descending order.
//display_list displays a list, no matter what order it is in. 