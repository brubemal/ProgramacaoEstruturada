/*alocar um numero e perguntar ao usuario se deseja continuar (S/N)? calcular a
média dos números e alocar os maiores e os menores que a média*/

#include<stdio.h>
#include<stdlib.h>

void alocaInt(int **p, int tam);
void leitura(int *p, int tam);
void mostraInt(int *p, int tam);
void calcularMedia(int *p, int tam, float *media);
void mostraMedia(float media);

int main()
{
int *nums = NULL, q = 0;
char op;
float media = 0;
do{ alocaInt(&nums, q + 1);
leitura(nums, q);
q++;
printf("Quer continuar(S/N)?");
scanf(" %c", &op);
} while (op == 'S'||op == 's');
mostraInt(nums, q);
calcularMedia(nums, q, &media);
mostraMedia(media);


}
void alocaInt(int **p, int tam)//alocar os números
{
    *p = (int*)realloc(*p, tam *sizeof(int));
    if (*p ==NULL)
    {
        exit(1);
    }
    
}
void leitura(int *p, int tam)
{
    printf("Numero:");
    scanf("%i",p+tam); 
}
void mostraInt(int *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("\nNumero %i", p[i]);
    }
    
}
void calcularMedia(int *p, int tam, float *media)
{
    for (int i = 0; i < tam; i++)
    {
        *media += p[i];
    }
    *media = *media / tam;
}
void mostraMedia(float media)
{
    printf("\nA media dos numeros \x82: %.2f", media);
}