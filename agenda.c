#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct{
    char nome[20];
    int idade, mat;
    }pessoa ;


int *c,*cp;
void *pBuffer;
pessoa *fw;


void adiciona(){
    pessoa *novo;
    *cp+=1;
    pBuffer = realloc ( pBuffer, sizeof(int)*2+(*cp)*(sizeof(pessoa)	)	);
    c = (int*)pBuffer;
    cp =(int*)c + 1;
    fw = (pessoa*)cp + 1;
    novo = fw + ( *cp - 1 );


    printf("nome:");
    scanf(" %s",novo->nome);
    printf("idade:");
    scanf("%d",&novo->idade);
    printf("matricula:");
    scanf("%d",&novo->mat);

    }

void lista(){

    for(*c=0 ; *c!=*cp ; (*c)++ ){
	printf("\nnome:%s\n",(fw+(*c))->nome);
	printf("idade:%d\n",(fw+(*c))->idade);
	printf("matricula:%d\n\n",(fw+(*c))->mat);
    }

}



int main(){

    pBuffer = malloc((sizeof(int)*2));
	c=pBuffer;
	cp =(int*)c + 1;
	fw = (pessoa*)cp + 1;
    *cp = 0;


  	do{
  	    printf("\n\n(1)adicionar a agenda:\n(2)retirar da agenda:\n(3)procurar:\n(4)lista:\n");
        scanf("%d",&*c);

        switch(*c){

          case 1:
                adiciona();
            break;
            case 4:
                lista();
            break;

            default:
                return 0;

            break;
	        }

    }while(*c!=5);

}
