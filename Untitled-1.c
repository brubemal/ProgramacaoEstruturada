
/*
Crie um vetor que armazene as temperaturas diárias
registradas durante um mês e em seguida elabore um
programa que calcule :
• A maior temperatura e o dia em que ocorreu
• A temperatura média mensal
• As temperaturas inferiores à média e os dias em
que ocorreram
*/

#include<stdio.h>
#include<stdlib.h>

void alocaInt(int **p, int tam);
void alocaFloat(float **p,  int tam);
void ReceberTemperaturas(int *p, int tam);

int main()
{
    int dias = 30;
    float *temperaturas = NULL, Media = 0;
    alocaFloat(&temperaturas, dias);
    ReceberTemperaturas(temperaturas, dias);
    return 0;
}
void alocaInt(int **p,int tam);
{
 *p = (int*)realloc(*p, tam *sizeof(int));
 if(*p == NULL){
    exit(1);
 }
}
void alocaFloat(int **p,int tam)
{
*p = (float*)realloc(*p, tam *sizeof(int));
if(*p ==NULL){
    exit(1);
}
}
void ReceberTemperaturas(float *p,int tam)
{
    for(i = 0; i < tam; i++){
        printf("\nTemperaturas: %f", i+1);
        scanf("%f", (p+1));
    }
}
