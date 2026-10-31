#include <stdio.h>
#include <math.h>

long ci(float x, float y, float z); // Prototype 1
long si(float x, float y, float z); // Prototype 2

int main()
{
  int choice;
  printf("Please select one of the following options: \n"
         "1. Calculate Simple Interest. \n"
         "2. Calculate Compound Interest. \n"
         "Your choice: ");
  scanf("%d", &choice);

  float principal;
  printf("Please enter the principal amount: ");
  scanf("%f", &principal);

  float rate;
  printf("Please enter the Rate of Interest (in %): ");
  scanf("%f", &rate);

  float time;
  printf("Please enter the time period (preferably in years): ");
  scanf("%f", &time);

  // Function Call for Simple Interest
  if (choice == 1){
    si(principal, rate, time);
  }
  else if (choice == 2){
    ci(principal, rate, time);
  };
}

long si(float x, float y, float z){
  float a = x*y*z/100;
  printf("%f", a);
}
long ci(float x, float y, float z){
  double num = 1 + y/100;
  double num_sq = pow(num, z); // The squared value of our original number
  double amount = x * num_sq;
  float CI = amount - x;
  printf("%f", CI);
};
