/*3) Construa um programa (main) que aloque em tempo de execução (dinamicamente)
uma matriz de ordem m x n (linha por coluna), usando 1+m chamadas a função malloc.
Agora, aproveite este programa para construir uma função que recebendo os
parametros m e n aloque uma matriz de ordem m x n e retorne um ponteiro para esta
matriz alocada. Crie ainda uma função para liberar a área de memória alocada pela
matriz. Finalmente, crie um novo programa (main) que teste/use as duas funções
criadas acima.*/

#include<stdio.h>
#include<stdlib.h>


void* maloc(int *i; int *t){
	int **p,m,n;
	printf("diga quantas linhas:"); scanf("%d",&i);
	p=((int **)malloc((sizeof(int*))*i));
	printf("diga quantas colunas:"); scanf("%d",&t);
	for(m=0;m!=i;m++){
		p[m]=(int*)malloc(sizeof(int)*t);
		for(n=0;n!=i;n++){
			p[m][n]= rand()%501;
		}

	}
return p;
}

void print(int t,int i,int **p){
	for(;t!=0;t--){
		for(;0!=i;i--){
			printf("%d    ",p[m][n]);
		}
		printf("\n");
	}

}


void fre(int **p,int t){

	for(;t!=0;t--){
		free(*p[t]);

	}
	free(p);
}


int main(){
	int **p,i,t,o;

	printf("1)criar matriz aleatoria:\n2)printar\n3)fechar programa");
	scanf("%d",&o);
	swith(o){
		case 1:
		p = maloc(&i,&t);
		
		case 2:
		print(&t,&i,p);

		case 3:fre(p,&t)
	}
}
