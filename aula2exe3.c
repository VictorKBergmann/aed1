/*3) Construa um programa (main) que aloque em tempo de execução (dinamicamente)
uma matriz de ordem m x n (linha por coluna), usando 1+m chamadas a função malloc.
Agora, aproveite este programa para construir uma função que recebendo os
parametros m e n aloque uma matriz de ordem m x n e retorne um ponteiro para esta
matriz alocada. Crie ainda uma função para liberar a área de memória alocada pela
matriz. Finalmente, crie um novo programa (main) que teste/use as duas funções
criadas acima.*/
#include<stdio.h>
#include<malloc.h>



int main(){
	int **p,i,t,m,n;
	

	printf("diga quantas linhas:"); scanf("%d",&t);
	printf("diga quantas colunas:"); scanf("%d",&i);
	p=((int **)malloc((int)(sizeof(int*))*(t)));
	for(m=0;m<t;m++){
		p[m]=(int*)malloc(sizeof(int)*(i));
		for(n=0;n<i;n++){
			p[m][n]= m;
			printf("%d", p[m][n]);
		}

	
	}

	for(m=0;m<i;m++){
		printf("\n");
		for(n=0;n<t;n++){
			printf("%d    ",p[m][n]);
		}

	}

	for(;t<0;t--){
		free(p[t]);

	}
	free(p);


	return 0 ;
}
