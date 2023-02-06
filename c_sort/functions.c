#include "functions.h"
#include <ctype.h>
#include <stdlib.h>

bool usage_statement(int argument_count, char sort_type) {
  if (argument_count < 3 || argument_count > 34 || (tolower(sort_type) != 'a' && tolower(sort_type) != 'd') ) {
    printf("\n  Usage: ./file_name {a|d} [int] [int] . . . [int]\n\n"
           "- file_name is the file to be ran (so running main looks like \"./main\") \n\n"
           "- {a|d} \"a\" or \"d\" means choose either a (for ascending sort)\n"
           "  or d (for descending sort)\n\n"
           "- [int] is an integer, you may have up to, but no more than, 32\n"
           "  different integers following the filename and sort type command.\n\n");

    return true;
  }
  return false;
};

bool begin_sort(int number_list[], char sort_type, int size){//description in functions.h
 if(tolower(sort_type) == 'a') return ascending_sort(number_list, size); 
 if(tolower(sort_type) == 'd') return descending_sort(number_list, size);
 return false;
};
bool copy_list(int number_list[], char* to_copy[], int size){//description in functions.h
  for (int i = 0; i < size; i++) {
    number_list[i] = atoi(to_copy[i]);
  }
 return true; 
};
bool ascending_sort(int number_list[], int size){//description in functions.h
  for(int i = 0; i < size; i++){
   for(int j = 0; j < size; j++){
     if(number_list[j] > number_list[j+1]){
     int swap = number_list[j];
     number_list[j] = number_list[j+1];
     number_list[j+1] = swap;
       }
   } 
  }
 return true;
};
bool descending_sort(int number_list[], int size){//description in functions.h
  for(int i = 0; i < size; i++){
   for(int j = 0; j < size; j++){
     if(number_list[j] < number_list[j+1]){
     int swap = number_list[j];
     number_list[j] = number_list[j+1];
     number_list[j+1] = swap;
       }
   } 
  }
 return true; 
};
bool display_list(int number_list[], int size){//description in functions.h
   for (int i = 2; i < size; i++){
    printf("%d ", number_list[i]);
  }
  printf("\n");
 return true; 
};