#include <stdio.h>
#include <stdlib.h>

void loadOnMatriz(char c[3][3]);
void createModel(char c[3][3]);

int main(){
    char c [3][3];
    createModel(c);
    getchar();
}

void loadOnMatriz(char c[3][3]){
    char count='1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = count++;
        }
    }
}

void createModel(char c[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j<2)
            {
                printf(" %c |", c[i][j]);
            } else{
                printf(" %c ", c[i][j]);
            }
            
        }
        if (i<2)
        {
            printf("\n--- --- ---\n");
        }
        
    }
    
    
} 