/*Criar um tipo abstrato de dados que represente uma pessoa, contendo nome, data de
nascimento e CPF. Crie uma variável que é um ponteiro para este TAD (no programa
principal). Depois crie uma função que receba este ponteiro e preencha os dados da
estrutura e também uma uma função que receba este ponteiro e imprima os dados da
estrutura. Finalmente, faça a chamada a esta função na função principal.*/
#include <stdio.h>
#include <malloc.h>

struct data{
    int dia, mes, ano;
};

struct pessoa{
    char nome[30];
    int cpf;
    struct data niver;
};

void nomeia(struct pessoa *primer){
    printf("diga o nome:");
    scanf("%s", primer->nome);
    printf("diga o dia do aniversario:");
    scanf("%d", &primer->niver.dia);
    printf("diga o mes do aniversario:");
    scanf("%d", &primer->niver.mes);
    printf("diga o ano do nascimento:");
    scanf("%d", &primer->niver.ano);
    printf("diga o cpf:");
    scanf("%d", &primer->cpf);
}
void imprime(struct pessoa *primer){
    printf("nome:");
    printf("%s\n", primer->nome);
    printf("aniversario:");
    printf("%d", &primer->niver.dia);
    printf("/");
    printf("%d", &primer->niver.mes);
    printf("/");
    printf("%d\n", &primer->niver.ano);
    printf("diga o cpf:");
    printf("%d", &primer->cpf);
int main(){
    struct pessoa *primer;
    primer = (struct *pessoa)malloc(sizeof(struct pessoa));
    nomeia(primer);
    return 0;
}
    
