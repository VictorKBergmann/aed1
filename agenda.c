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
    pBuffer = (void*) realloc ( pBuffer, sizeof(int)*2+sizeof(float)+((cp)*(int*)(sizeof(*novo))));
    c = (int*)pBuffer;
    cp = c + 1;
    a = (float*)((int*)cp) + 1;

    novo = (struct pessoa*)(a + ((int*)(sizeof(pessoa*)) * ( cp ) ));

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
    int *c,*cp;
    float *a;
    pessoa *init,*fw;
    pBuffer = malloc((sizeof(int)*2)+sizeof(float));

    printf("(1)adicionar a agenda:\n(2)retirar da agenda:\n(3)procurar:");
    switch(*c){
    case 1:adiciona(pBuffer,cp,c,a);

    case 4:lista(pBuffer,c,init,cp,fw);
    }
}
