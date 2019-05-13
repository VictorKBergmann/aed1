/*Faça uma função que receba um valor n e crie dinamicamente um vetor de n
elementos e retorne um ponteiro. Crie uma função que receba um ponteiro para um
vetor e um valor n e imprima os n elementos desse vetor. Construa também uma
função que receba um ponteiro para um vetor e libere esta área de memória. Ao final,
crie uma função principal que leia um valor n e chame a função criada acima. Depois, a
função principal deve ler os n elementos desse vetor. Então, a função principal deve
chamar a função de impressão dos n elementos do vetor criado e, finalmente, liberar a
memória alocada através da função criada para liberação.*/
#include<stdio.h>
#include<stdlib.h>

int* cria(int n){
   int *vet;
   vet = (int*)malloc(sizeof(int)*n);
   for(;n!=0;n--){
       vet[n]=rand();
   }
  return vet;
}
  
void printa(int *vet, int n){
    for(;n!=0;n--){
       printf("%d\n",vet[n]);
    }
}

void libera(int *vet){
    free(vet);
}
   
 
int main (){
    int *vet,n;
    
    scanf("%d",&n);
    vet=cria(n);
    printa(vet,n);
    libera(vet);
    return 0;
}
