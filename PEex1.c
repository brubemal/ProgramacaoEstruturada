/*alocar um numero e perguntar ao usuario se deseja continuar (S/N)? calcular a
média dos números e alocar os maiores e os menores que a média*/

#include<stdio.h>
#include<stdlib.h>

void alocaInt(int **p, int tam);
void leitura(int *p, int tam);
void mostraInt(int *p, int tam);
void calcularMedia(int *p, int tam, float *media);
void mostraMedia(float media);
void alocarMenores(int *p, int tam, float media, int **menorMedia, int *qtdMenores);
void mostraMenores(int *menorMedia, int qtdMenores);

int main()
{
int *nums = NULL, q = 0, maiorMed = 0, menorMedia = 0, qtdMenores = 0, qtdMaiores= 0;
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
alocarMenores(nums, q, media, &menorMedia, &qtdMenores);
mostraMenores( *menorMedia, qtdMenores);


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
void alocarMenores(int *p, int tam, float media, int **menores, int *qtdMenores) {
    for (int i = 0; i < tam; i++) {
        if (p[i] < media) {
            (*qtdMenores)++;
        }
    }

    alocaInt(menores, *qtdMenores);

    int posicao = 0;
    for (int i = 0; i < tam; i++) {
        if (p[i] < media) {
            (*menores)[posicao] = p[i];
            posicao++;
        }
    }
}

void mostraMenores(int *menores, int qtdMenores) {
    if (qtdMenores == 0) {
        printf("Nao existem numeros menores que a media.\n");
        return;
    }
    
    printf("Menores que a media: ");
    for (int i = 0; i < qtdMenores; i++) {
        printf("%i ", menores[i]);
    }
    printf("\n");
}