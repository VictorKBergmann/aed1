#include<stdio.h>
#include<stdlib.h>


typedef struct No *Apontador;
typedef struct Registro{
    int data;
}Registro;
typedef struct No{
    Registro Reg;
	Apontador rigth,left;
}No;

int conta(No*node){
    int a=1;
	if(node->left != NULL)a +=conta(node->left);
	if(node->rigth != NULL)a +=conta(node->rigth);

	return a;
}
int contaNos(No*node){
    int a=0;
	if(node->left != NULL)a +=conta(node->left);
	if(node->rigth != NULL)a +=conta(node->rigth);

	return a;
}
int contaFolhas(No*node){
    int a=0;
	if(node->left == NULL)a +=conta(node->left);
	else a++;
	if(node->rigth == NULL)a +=conta(node->rigth);
    else a++;

	return a;
}
int altura(No*node){
    int a=1,b=1;
	if(node->left != NULL)a +=conta(node->left);
	if(node->rigth != NULL)b +=conta(node->rigth);

    if(a>b)return a;
    else return b;

}
Apontador* procura(No*node){
    if(node->Reg.data%2==1) return node;

    if(node->left != NULL)
        if(procura(node->left)!=NULL)return node;
	if(node->rigth != NULL)
        if(procura(node->rigth)!=NULL)return node;
	return NULL;
}
void inicializa(No*node){
    node->Reg.data +=10;
    node->left->Reg.data -=1;
    node->rigth->Reg.data +=1;
    inicializa(node->left);
    inicializa(node->rigth);

}


int main(){
    Apontador* raiz;
    inicializa(raiz);
    }

