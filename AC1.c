/*
Aloque dinamicamente a sequencia de numeros int digitados pelo usuario, até que 
este escolha N (Deseja continuar? S/N). Em seguida, deve-se subtrair o primeiro 
do segundo, o terceiro do quarto e assim por diante, ir alocando dinamicamente 
os números que tiverem como resultado da subtração valores ímpares. 
Caso sobre algum número, esse deve ser analisado sozinho(sem subtrair)e 
se ímpar, deve ser alocado e armazenado.
*/

#include<stdio.h>
#include<stdlib.h>

void alocaInt(int **p, int tam);
void leituraInt(int *p, int tam);
void mostra(int *p, int tam);
void processaImpares(int *nums, int q_nums, int **numImp, int *qtdImp);

int main()
{
    int q_nums = 0, *nums = NULL, *numImp = NULL, qtdImp = 0;
    char op;
    do{
        alocaInt(&nums, q_nums + 1);
        leituraInt(nums, q_nums);
        q_nums++;
        printf("Deseja continuar? (S/N)\n");
        scanf(" %c",&op);

    } while (op == 'S'||op == 's');
    mostra(nums, q_nums);
    processaImpares(nums, q_nums, &numImp, &qtdImp);
    printf("\nNumeros apos a subtracao:");
    mostra(numImp, qtdImp);
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
void processaImpares(int *nums, int q_nums, int **numImp, int *qtdImp) {
    *qtdImp = 0;
    *numImp = NULL;

    for (int i = 0; i < q_nums; i += 2) {
        int resultado;

        if (i + 1 < q_nums) {
            resultado = nums[i + 1] - nums[i];
        } else {
            resultado = nums[i];
        }

        if (resultado % 2 != 0) {
            alocaInt(numImp, *qtdImp + 1);
            (*numImp)[*qtdImp] = resultado;
            (*qtdImp)++;
        }
    }
}