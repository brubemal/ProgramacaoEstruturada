
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
void calculaMaior(float *p, int tam, float *maiorTemp, int *diaMaior);
void leituraMaiorTemp(float maiorTemp, int diaMaior);

int main()
{
    int dias = 30, diaMaior = 0;
    float *temperaturas = NULL, media= 0, maiorTemp = 0;
    alocaFloat(&temperaturas, dias);
    receberTemp(temperaturas, dias);
    printf("\n\n");
    calcularMedia(temperaturas, dias, &media);
    leituraMedia(media);
    calculaMaior(temperaturas, dias, &maiorTemp, &diaMaior);
    leituraMaiorTemp(maiorTemp, diaMaior);
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
    printf("\nA media das temperaturas \x82: %.2f", media);
}
void calculaMaior(float *p, int tam, float *maiorTemp, int *diaMaior)
{
	for(int i = 0; i < tam; i++)
	{
	if(*(p + i) > *maiorTemp){
		*maiorTemp = *(p + i);
		*diaMaior = i + 1;
	}
	}
	
}
void leituraMaiorTemp(float maiorTemp, int diaMaior)
{
	printf("\nA maior temp \x82 %.2f e o dia que ocorrou foi %i", maiorTemp, diaMaior);	
}
