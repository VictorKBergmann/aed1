/*3) Construa um programa (main) que aloque em tempo de execução (dinamicamente)
uma matriz de ordem m x n (linha por coluna), usando 1+m chamadas a função malloc.
Agora, aproveite este programa para construir uma função que recebendo os
parametros m e n aloque uma matriz de ordem m x n e retorne um ponteiro para esta
matriz alocada. Crie ainda uma função para liberar a área de memória alocada pela
matriz. Finalmente, crie um novo programa (main) que teste/use as duas funções
criadas acima.*/

#include<stdio.h>
#include<stdlib.h>


int** maloc(int *i, int *t){
	int **p,m,n;
	printf("diga quantas colunas:"); scanf("%d",i);
	p=((int **)malloc((int)(sizeof(int*))*(*i)));
	printf("diga quantas linhas:"); scanf("%d",t);
	for(m=0;m!=*i;m++){
		p[m]=(int*)malloc(sizeof(int)*(*t));
		for(n=0;n!=*t;n++){
			p[m][n]= m;
		}

	}
return p;
}

void print(int *t,int *i,int **p){
	int m,n;
	m=*t;
	n=*i;
	for(m=0;m!=*i;m++){
		printf("\n");
		for(n=0;n!=*t;n++){
			printf("%d    ",p[m][n]);
		}

	}

}


void fre(int **p,int *t){

	for(;*t!=0;*t--){
		free(p[*t]);

	}
	free(p);
}


int main(){
	int **p,i,t,o;

	printf("1)criar matriz aleatoria:\n2)printar\n3)fechar programa");
	scanf("%d",&o);
	switch(o){
		case 1:
		p = maloc(&i,&t);

		case 2:
		print(&t,&i,p);

		case 3:
		fre(p,&t);
		return 0;
	}
}
