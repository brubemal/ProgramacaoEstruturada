/*
Fazer um programa para Controle de Hotel - este programa se destina a controlar o check-in
(cadastro de hóspedes) de um hotel. O hotel possui 15 quartos, sendo 5 de categoria Solteiro e
10 de categoria Familiar. Utilizar alocação dinâmica e ponteiros para a estrutura.
[1] Check-in - alocar dinamicamente espaço, receber os valores digitados pelo usuário, se o
hóspede não tiver acompanhantes atribuir categoria Solteiro, caso contrário Familiar, buscar o
número do quarto disponível, de acordo com a categoria na estrutura quartos. Apenas um
hóspede é cadastrado por vez. Não esquecer de atualizar o quarto da estrutura quartos para
Ocupado.
[2] Check-out – encerra a estadia e apresenta o relatório, de acordo com o quarto. Apenas um
registro é acessado por vez, buscar e mostrar o número do quarto, o nome do hóspede,
quantidade de acompanhantes, a categoria (Solteiro ou Familiar), o tempo de permanência em
dias e o valor a ser pago.
[3] Fim
Dica:
• No check-in - não esquecer de verificar se na estrutura hospede há um espaço vago
(cujo quarto = -1), se houver o novo hóspede deverá ser ali armazenado, caso contrário,
acrescentar no final da estrutura.
Categoria de quarto:
[S]olteiro – diária R$ 85,00 por pessoa
[F]amiliar – diária R$ 65,00 por pessoa
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct quarto{
int num; 
char categoria; 
char status; 
}Quarto;

typedef struct hospede{
int quarto; 
char nome[80];
int acompanhante; 
char categoria; 
int dias;
}Hospede;

void alocaQuartos(Quarto **p_quartos, int qtd);
void cadastraQuartos(Quarto *p_quartos, int qtd);
int buscaVago(Hospede *p_hospede, int qtd);
void alocarHospede(Hospede **p_hospede, int qtd);
void cadastraHospede(Hospede *p_hospede, Quarto *p_quartos, int qtd);

int main()
{
    Quarto *quartos = NULL;
    Hospede *hospedes = NULL;
    int numQuartos = 15, op, qtdHospedes = 0, retornoBuscaVago;
    alocaQuartos(&quartos, numQuartos);
    cadastraQuartos(quartos, numQuartos);

    do
    {
        scanf("[1]Check-In\n [2]Check-Out\n [3]");
        switch (op)
        {
        case 1:
        {
           retornoBuscaVago = buscaVago(hospedes, qtdHospedes); //busca se tem algum quarto vago (-1)
           if (retornoBuscaVago == -1)
           {
            alocaHospede(&hospedes, qtdHospedes + 1); //Quantidade de hospedes aumenta em 1(qtdHospedes + 1)
            cadastraHospede(hospedes, quartos, numQuartos);
           }
           
        }
        case 2:
        {

        }
        }
    } while (op != 3);
    


    return 0;
}
void alocaQuartos(Quarto **p_quartos, int qtd){
    *p_quartos = (Quarto*)realloc(*p_quartos, qtd*sizeof(Quarto));
    if (*p_quartos == NULL)
    {
        exit(1);
    }
    
}
void cadastraQuartos(Quarto *p_quartos, int qtd){
    for(int i = 0; i < qtd; i++, *p_quartos++){
        p_quartos->status = 'L'; // adiciona o status livre a todos os quartos
        p_quartos->num = i + 1; //a cada iteração do for será cadastrado 1 quarto(+1 serve para o primeiro quarto cadastro comer do 1)
        if (i < 5)
        {
            p_quartos->categoria = 'S';
        }
        else{
            p_quartos->categoria = 'F';
        }

        
    }
}
int buscaVago(Hospede *p_hospede, int qtd)
{
    for (int i = 0; i < qtd; i++, p_hospede++)
    {
        if (p_hospede->quarto == -1)
        {
            return i;
        }
        
    }
    return -1; //aqui poderia ser qualquer numero negativo ou qualquer numero que nao de conflito como o numero dos quartos
}
void alocarHospede(Hospede **p_hospede, int qtd){
    *p_hospede = (Hospede*)realloc(*p_hospede, qtd*sizeof(Hospede));
    if (*p_hospede == NULL)
    {
        exit(1);
    }
    
}
void cadastraHospede(Hospede *p_hospede, Quarto *p_quartos, int qtd)
{
    printf("Nome: ");
    gets(p_hospede->nome);
    printf("Acompanhantes: ");
    scanf("%i", &p_hospede->acompanhante);
    if (p_hospede->acompanhante == 0)
    {
        p_hospede->categoria = 'S';
    }
    else{
        p_hospede->categoria = 'F';
    }
    

}