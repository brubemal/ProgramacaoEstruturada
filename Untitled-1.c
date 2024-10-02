
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
void receberTemp(float *p, int tam);
void calcularMedia(float *p, int tam, float *media);
void leituraMedia(float media);

int main()
{
    int dias = 30;
    float *temperaturas = NULL, media= 0;
    alocaFloat(&temperaturas, dias);
    receberTemp(temperaturas, dias);
    calcularMedia(temperaturas, dias, &media);
    leituraMedia(media);
    return 0;
}
void alocaInt(int **p,int tam)
{
 *p = (int*)realloc(*p, tam *sizeof(int));
 if(*p == NULL){
    exit(1);
 }
}
void alocaFloat(float **p,int tam)
{
*p = (float*)realloc(*p, tam *sizeof(float));
if(*p ==NULL){
    exit(1);
}
}
void receberTemp(float *p,int tam)
{
    for(int i = 0; i < tam; i++){
        printf("\nTemperaturas %d: ", i+1);
        scanf("%f", (p+i));
    }
}
void calcularMedia(float *p, int tam, float *media)
{
    for (int i = 0; i < tam; i++)
    {
        *media += *(p + i);
    }
    *media = *media / tam;
    
}
void leituraMedia(float media)
{
    printf("A media das temperaturas \x82: %.2f", media);
}
