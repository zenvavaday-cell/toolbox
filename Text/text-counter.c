#include <stdio.h>

int main()
{
    char word[100];
    printf("Please enter a word, number or symbol: ");
    scanf("%99s", word);

    int count = 0;

    for(int i = 0; word[i] != 0; ++i){
        ++count;
    }

    printf("Number of characters in  %s is %i characters.\n", word, count);
    return 0; 
}