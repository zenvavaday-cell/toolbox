#include <stdio.h>
#include <math.h>

int addition(int x, int y);
int subtraction(int x, int y);
int multiplication(int x, int y);
int division(int x, int y);

int main()
{
  int choice;
  printf(   "1. Addition \n"
            "2. Subtraction \n"
            "3. Multiplication \n"
            "4. Division \n"
            "Please select your option: ");
  scanf("%i", &choice);
    
  int num1;
  printf("Enter the first number: ");
  scanf("%i", &num1);
  int num2;
  printf("Enter the second number: ");
  scanf("%i", &num2);
  
  // Will now create conditionals for each operation

  if (choice > 5 && choice < 0){
       fprintf(stderr, "Invalid Input");
  }
  else if(choice == 1){
      printf("%i", addition(num1, num2));
  }
  else if(choice == 2){
    printf("%i", subtraction(num1, num2));
  } 
  else if(choice == 3){
    printf("%i", multiplication(num1, num2)); 
  }
  else{
    printf("%i", division(num1, num2));
  }
  return 0;
}

int addition(int x, int y){
  return x + y;
}
int subtraction(int x, int y){
  return x - y;
}
int multiplication(int x, int y){
  return x * y;
}
int division(int x, int y){
  return x/y;
}