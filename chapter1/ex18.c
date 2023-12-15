#include <stdio.h>

int main() {
    int c;
    int charCount = 0;
    char curLine[1000];

    while ((c = getchar()) != EOF) {
        curLine[charCount] = c;
        if (c == '\n') {
            
            if (charCount > 1) {
            
                int temp = charCount;
                for (int i = temp; curLine[i] == ' ' || curLine[i] == '\t' || 
				curLine[i] == '\n'; i--)
	       	{
                    charCount--;
                }
                 for (int i = 0; i <=charCount; i++) {
                    printf("%c", curLine[i]);}
                printf("\n");
           
            }
            charCount = 0;
        } 
      
	else charCount++;
    
    }	
    }

