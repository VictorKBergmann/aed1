#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define true  1
#define false 0
#define MAX   10
#define bool int

typedef struct{
    int ra;
    char nome[MAX];
}Aluno;

typedef struct{
    Aluno alunos[MAX];
    int topo;
    int base;
    int limite;
}Pilha;

void reset  (Pilha *pilha);
bool FULL   (Pilha *pilha);
bool EMPTY  (Pilha *pilha);
bool push   (Pilha *pilha, char* name, int *rau);
bool pop    (Pilha *pilha, char* name, int *rau);
bool list   (Pilha *pilha, char* name, int *rau);
bool popName(Pilha *pilha, char* name, int *rau, char* delta);

int main(){
  	
        bool teste = -1;
        int menu,*rau;
        char name[MAX], delta[MAX];
        Pilha pilha;
        
        reset(&pilha);
    
  	do{

        printf("-----------\n   MENU\n-----------\n(1)adicionar:\n(2)deleta:\n(3)deleta por nome:\n(4)limpa:\n(5)lista:\n(6)FULL:\n(7)EMPTY\n(0)sair:\n--------\n    ");
        scanf("%d",&menu);

        switch(menu){

        	case 1:
                printf("diga o nome:");
                scanf("%s",name);   
                printf("diga o ra:");
                scanf("%d",rau);
    
                teste = push(&pilha,name,rau);
            break;

        	case 2:
    		    teste = pop(&pilha,name,rau);
			break;

			case 3:
                printf("diga o nome a retirar:");
                scanf("%s",delta);
                popName(&pilha,name,rau,delta);
            break;

			case 4:
            //clear();
            break;

			case 5:
               teste = list(&pilha,name,rau);
            break;
    		
            case 6:
               teste = FULL(&pilha);
            break;
        
            case 7:
               teste = EMPTY(&pilha);
            break;

            case 0:
            	menu=-1;
                return 0;
			break;

			default:
                printf("funcao indisponivel!\n");
			}
            if(teste == true) printf("\nprocedimento feito com sucesso\n");
            else              printf("\nprocedimento NAO FOI feito com sucesso\n");
            
    }while(menu != -1);

}

void reset(Pilha *pilha){
    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = MAX;
}

bool FULL(Pilha *pilha){
    return(pilha->topo == MAX);
}

bool EMPTY(Pilha *pilha){
    return(pilha->topo == 0);
}

bool push(Pilha *pilha, char* name, int *rau){
    
    if(!FULL(pilha)){
        strcpy(pilha->alunos[pilha->topo].nome, name);
        pilha->alunos[pilha->topo].ra = *rau;   
        pilha->topo++;

    return true;    
    }
    else return false;
}

bool pop(Pilha *pilha,char* name, int *rau){ 
    if(!EMPTY(pilha)){
        pilha->topo--;
        strcpy(name,pilha->alunos[pilha->topo].nome);
        *rau = pilha->alunos[pilha->topo].ra;

        return true;   
    }
    else return false;
}

bool list(Pilha *pilha, char* name, int *rau){
    Pilha aux;
    reset(&aux);

    if(!EMPTY(pilha)){
        do{
            pop(pilha,name,rau);
            push(&aux, name,rau);


        }while(pilha->topo > 0);

        do{
            pop(&aux,name,rau);            
            push(pilha,name,rau);

            printf("rau:%d\n",pilha->alunos[pilha->topo-1].ra);
            printf("nome:%s\n",pilha->alunos[pilha->topo-1].nome);
        }while(aux.topo > 0);
    return true;  
    } 
    else return false;
}

bool popName(Pilha *pilha, char* name, int *rau, char* delta){
    Pilha aux;
    reset(&aux);

    if(!EMPTY(pilha)){
        do{
            pop(pilha,name,rau);
            push(&aux, name,rau);


        }while(pilha->topo > 0);

        do{

            pop(&aux,name,rau); 
            if(strcmp(name,delta)!=0)  
                push(pilha,name,rau);

        }while(aux.topo > 0);
    return true;  
    } 
    else return false;
}