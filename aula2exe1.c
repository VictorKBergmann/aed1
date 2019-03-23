/*Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos
e passe esse vetor para uma função que vai ler os elementos desse vetor. Depois, no
programa principal, o vetor preenchido deve ser impresso. Além disso, antes de
finalizar o programa, deve-se liberar a área de memória alocada.
*/


#include <stdio.h>
#include <malloc.h>
int* leitor(int n){
	int i, *vetor;
	vetor = (int*)malloc(n*sizeof(int));
	for(i=0;i!=n;i++){
		scanf("%d",&vetor[i]);
	}
	return vetor;
}




int main(){
	int n,*vetor,i;

	printf("diga quantos elementos:");
	scanf("%d",&n);
	vetor = leitor(n);

	for(i=0;n!=i;i++){
		printf("%d\n",vetor[i]);
	}
return 0;

}
