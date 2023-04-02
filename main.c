#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void loadOnMatriz(char c[3][3]);
void createModel(char c[3][3]);
char whichFicha();
void select(char c[3][3], char ficha);
void ia(char c[3][3], char ficha);

int main(){
    char c [3][3];
    loadOnMatriz(c);
    char ficha = whichFicha();
    do
    {
        createModel(c);
        printf("\n\n");
        select(c,ficha);
        ia(c, ficha);
    } while (1);
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

char whichFicha(){
    int decision;
    printf("\nDigite con que ficha va a jugar: \n");
    printf("[1/para O] || [2/para X]\n[   ]\b\b\b");
    scanf("%d", &decision);
    
    if (decision == 1)
    {
        return 'O';
    }
    if (decision == 2)
    {
        return 'X';
    }
    printf("Input inesperado");
    exit(1);
}

void ia(char c[3][3], char ficha){
    char posicion;
    char fichaComputer;
    if (ficha=='O')
    {
        fichaComputer = 'X';
    } else{
        fichaComputer = 'O';
    }
    
    srand(time(NULL));
    do
    {
        posicion = (rand()%9)+'0';
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (c[i][j] == posicion)
                {
                    c[i][j] = fichaComputer;
                    return;
                }
                
                
            }
            
        }
    } while (1);
}

void select(char c[3][3], char ficha){
    char input;
    do
    {
        fflush(stdin);
        printf("\nDigite en que posicion quiere su ficha [   ]\b\b\b");
        scanf("%c", &input);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (c[i][j] == input)
                {
                    c[i][j] = ficha;
                    return;
                }
                
                
            }
            
        }
        printf("\nNo se encuentra disponible la ubicacion:(");
        getchar();
    } while (1);
    
}