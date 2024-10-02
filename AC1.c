/*
Aloque dinamicamente a sequencia de numeros int digitados pelo usuario, até que 
este escolha N (Deseja continuar? S/N). Em seguida, deve-se subtrair o primeiro 
do segundo, o terceiro do quarto e assim por diante, ir alocando dinamicamente 
os números que tiverem como resultado da subtração valores ímpares. 
Caso sobre algum número, esse deve ser analisade sozinho(sem subtrair)e 
se ímpar, deve ser alocado e armazenado.
*/

#include<stdio.h>
#include<stdlib.h>

void alocaInt(int **p, int tam);
void leituraInt(int *p, int tam);
void mostra(int *p, int tam);

int main()
{
    int q_nums = 0, *nums = NULL;
    char op;
    do{
        alocaInt(&nums, q_nums + 1);
        leituraInt(nums, q_nums);
        q_nums++;
        printf("Deseja continuar? (S/N)");
        scanf(" %c",&op);

    } while (op == 'S'||op == 's');
    mostra(nums, q_nums);
    free(nums);
    return 0;
}
void alocaInt(int **p, int tam)
{
    *p=(int*)realloc(*p, tam*sizeof(int));
    if (*p == NULL)
    {
        exit(1);
    }
    
}
void leituraInt(int *p, int tam)
{
    printf("\nNumero:");
    scanf("%i", p+tam);

}
void mostra(int *p, int tam)
{
    for (int i = 0; i < tam; i++, p++)
    {
     printf("\nNumero: %i", *p);
    }
}