#include "main.h"

int print_string(char *string){
  int count = 0;
  int i;

  for (i = 0; string[i] != '\0'; i++){
    count += _putchar(string[i]);
  }
  
  return (count);
}
