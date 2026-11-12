#include <stdio.h>

void printQuestions(char *array[], int size); // Prototype 1
int main(void)
{
  char *strings[] = {
    "Here's a list of questions for your test."
    " 1. Define force and pressure "
    " 2. How do you calculate Pascal and what is its SI Unit. "
    " 3. What are the SI units of Force and Area"
    " 4. Define the proportional relation between area and force. "
    " 5. Why is the base of a dam broader than its top? "
    " 6. Explain air pressure and low air pressure vs high air pressure. "
  };
  printQuestions(strings, 7);
  return 0;
}
void printQuestions(char *array[], int size){
  for (int i = 0; i < size; i++){
    printf("%s\n", array[i]);
  }
}
