#include<stdio.h>
#include<stdlib.h>

typedef struct No *Apontador;
typedef struct Registro{
    int data;
}Registro;
typedef struct No{
    Registro Reg;
    Apontador rigth,left,parent;
    
}No;

int conta(No**node){
    int a=1;
    if((*node)->left != NULL)a +=conta(&(*node)->left);
    if((*node)->rigth != NULL)a +=conta(&(*node)->rigth);

    return a;
}
int contaNos(No**node){
    int a=0;
    if((*node)->left != NULL)a +=contaNos(&(*node)->left);
    if((*node)->rigth != NULL)a +=contaNos(&(*node)->rigth);

    return a;
}
int contaFolhas(No**node){
    int a=0;
    if((*node)->left == NULL)a +=contaFolhas(&(*node)->left);
    else a++;
    if((*node)->rigth == NULL)a +=contaFolhas(&(*node)->rigth);
    else a++;

    return a;
}
int altura(No**node){
    int a=1,b=1;
    if((*node)->left != NULL)a +=altura(&(*node)->left);
    if((*node)->rigth != NULL)b +=altura(&(*node)->rigth);

    if(a>b)return a;
    else return b;

}
No* procuraImpar(No**node){
    if((*node)->Reg.data%2==1) return *node;

    if((*node)->left != NULL)
        if(procuraImpar(&(*node)->left)!=NULL)return *node;
    if((*node)->rigth != NULL)
        if(procuraImpar(&(*node)->rigth)!=NULL)return *node;
    return NULL;
}
void insere(No**node,int num){
    if(*node==NULL){
        *node=(No*)malloc(sizeof(No));
        (*node)->Reg.data = num;
        (*node)->rigth = NULL;
        (*node)->left = NULL;
        return; 
	}
    else if((*node)->Reg.data >num){
            insere(&(*node)->left,num);
            return;
	}
        else
            insere(&(*node)->rigth,num);
            return;
}
void inicializa(No**node){
    insere(&(*node),10);
    insere(&(*node),7);
    insere(&(*node),3);
    insere(&(*node),4);
    insere(&(*node),11);
    insere(&(*node),1);

}

No** parent(No**node){
    return &((*node)->parent);
}

No** grandparent(No**node){
    return &((*node)->parent->parent);
}



void printa(No* node,int i){
    int t=i;
    for(;t!=0;t--)
        printf("    ");
    printf("%d",(*node).Reg.data);
    if((*node).left != NULL)printa((*node).left,i+1);
    if((*node).rigth!= NULL)printa((*node).rigth,i+1);

    return;
}

int main(){
    No** raiz;
    inicializa(raiz);
    printa(*raiz,0);
    return 0;
    }
