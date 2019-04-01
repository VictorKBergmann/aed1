#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct{
    char nome[20];
    int idade, mat;
    }pessoa ;


void* adiciona(void *pBuffer,int *cp, int *c, float *a){
    pessoa *novo;
    cp ++;
    pBuffer = realloc ( pBuffer, sizeof(int)*2+sizeof(float)+(*cp)*(sizeof(pessoa)	)	);
    c = (int*)pBuffer;
    cp =(int*)c + 1;
    a = (float*)cp + 1;
	
    novo = (pessoa*)(a + ((int)(sizeof(pessoa)) * ( *cp ) ));

    printf("nome:");
    scanf("%s",(*novo).nome);
    printf("idade:");
    scanf("%d",&(*novo).idade);
    printf("matricula:");
    scanf("%d",&(*novo).mat);

    return pBuffer;
    }

void lista(void *pBuffer, int *c, pessoa *init,int *cp, pessoa *fw){

    fw= init;
    for(*c=0 ; *c!=*cp ; *c++ ){
	printf("nome:%s\n",(*fw).nome);
	printf("idade:%d\n",&(*fw).idade);
	printf("matricula:%d\n",&(*fw).mat);
	
	fw++;
    }

}



int main(){
    void *pBuffer;
    int *c,*cp=0;
    float *a;
    pessoa *init,*fw;
    pBuffer = malloc((sizeof(int)*2)+sizeof(float));
	c=pBuffer;
	cp =(int*)c + 1;
    a = (float*)cp + 1;
	
    printf("(1)adicionar a agenda:\n(2)retirar da agenda:\n(3)procurar:\n(4)lista:\n");
    scanf("%d",&*c);
  
  
  	do{
  	
    switch(*c){
	
    case 1:
	adiciona(pBuffer,cp,c,a);
	break;
    case 4:lista(pBuffer,c,init,cp,fw);
    break;
	}
    return 0;
}while(*c!=5);
}
