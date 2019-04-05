#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct{
    char nome[20];
    int idade, mat;
    }pessoa ;


void* adiciona(void *pBuffer,int *cp, int *c, float *a){
    pessoa *novo;
    *cp+=1;
    pBuffer = realloc ( pBuffer, sizeof(int)*2+sizeof(float)+(*cp)*(sizeof(pessoa)	)	);
    c = (int*)pBuffer;
    cp =(int*)c + 1;
    a = (float*)cp + 1;
	*c = (sizeof(pessoa)) * ( *cp );
    novo = (pessoa*)(a + (*c));

    printf("nome:");
    scanf("%s",(*novo).nome);
    printf("idade:");
    scanf("%d",&(*novo).idade);
    printf("matricula:");
    scanf("%d",&(*novo).mat);

    return pBuffer;
    }

void lista(void *pBuffer, int *c,int *cp, pessoa *fw){

    fw = (pessoa*)pBuffer;
    fw+=(sizeof(int))*2+sizeof(float);

    for(*c=0 ; *c!=*cp ; (*c)++ ){
	printf("nome:%s\n",(*fw).nome);
	printf("idade:%d\n",(*fw).idade);
	printf("matricula:%d\n",(*fw).mat);

	fw++;
    }

}



int main(){
    void *pBuffer;
    int *c,*cp;

    float *a;
    pessoa *fw;
    pBuffer = malloc((sizeof(int)*2)+sizeof(float));
	c=pBuffer;
	cp =(int*)c + 1;
    *cp = 0;
    a = (float*)cp + 1;


  	do{
  	    printf("\n\n(1)adicionar a agenda:\n(2)retirar da agenda:\n(3)procurar:\n(4)lista:\n");
        scanf("%d",&*c);

        switch(*c){

          case 1:
                pBuffer= adiciona(pBuffer,cp,c,a);
            break;
            case 4:
                lista(pBuffer,c,cp,fw);
            break;

            default:
            return 0;
            break;
	        }

    }while(*c!=5);

}
