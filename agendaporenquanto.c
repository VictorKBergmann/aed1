#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char nome[20];
    int idade, mat;
    }pessoa ;


int *c,*cp,*i,*n;
void *pBuffer;
pessoa *fw,*novo;

void inicializa(){

    pBuffer = malloc (sizeof(int)*3+(sizeof(char)*20)+(4)*(sizeof(pessoa)    )	);
    c = (int*)pBuffer;
    cp =(int*)c + 1;
    *cp = 4;
    i = cp + 1;
    fw = (pessoa*)(i + 1);
    novo = fw;

    strcpy( novo->nome ,"2");
    novo->idade = 2;
    novo->mat = 2;
    novo ++;

    strcpy( novo->nome ,"1");
    novo->idade = 1;
    novo->mat = 1;
    novo ++;

    strcpy( novo->nome ,"admin");
    novo->idade = 0;
    novo->mat = 0;
    novo ++;

    strcpy( novo->nome ,"Victor");
    novo->idade = 19;
    novo->mat = 18104996;


}


void insertionSort(){
    novo = fw + ( *cp );
    for( (*c)=1; (*c) < (*cp); (*c)++){
        *i = (*c) - 1;
        //memcpy(novo,&(fw[*i]),sizeof(pessoa));
        strcpy( novo->nome , (fw+( *c))->nome );
        novo->mat =(fw+( *c ))->mat;
        novo->idade =(fw+( *c ))->idade;

        while(( (*i)>=0 ) && (novo->mat < ((fw+ (*i))->mat ) )){

           // memcpy(&(fw[*i]), &(fw[(*i)+1]),sizeof(pessoa));
            strcpy( (fw+( * i +1 ))->nome , (fw+( *i ))->nome );
            (fw+( *i + 1 ))->mat =(fw+( *i ))->mat;
            (fw+( *i + 1 ))->idade =(fw+( *i ))->idade;
            (*i)--;
        }
        //memcpy(novo,&(fw[(*i)+1]),sizeof(pessoa));
        strcpy( (fw+( *i + 1 ))->nome, novo->nome );
        (fw+( *i + 1))->mat= novo->mat;
        (fw+( *i + 1))->idade = novo->idade;
    }
}

void adiciona(){
    pessoa *novo;
    *cp+=1;
    pBuffer = realloc ( pBuffer, sizeof(int)*3+(*cp + 1)*(sizeof(pessoa)	)	);
    c = (int*)pBuffer;
    cp =(int*)c + 1;
    i = cp + 1;
    fw = (pessoa*)(i + 1);
    novo = fw + ( *cp - 1 );

    printf("nome:");
    scanf(" %s",novo->nome);
    printf("idade:");
    scanf("%d",&novo->idade);
    printf("matricula:");
    scanf("%d",&novo->mat);

}
// remover ta errado
void remover(){
	pessoa *novo;
	novo = fw + ( *cp );
	printf("nome:");
    scanf(" %s",novo->nome);

    for(*c= 0;*c != (*cp) && *i != -1 ; (*c)++){

        if(strcmp( (fw+(*c))->nome,novo->nome ) == 0 ){
            (*cp)-=1;
            while( *c != *cp){
                strcpy( (fw+( *c - 1 ))->nome , (fw+( *c ))->nome );
                (fw+( *c - 1 ))->mat =(fw+( *c ))->mat;
                (fw+( *c - 1 ))->idade =(fw+( *c ))->idade;
	    		*c+=1;
	    	}
	    	*i = -1;

	    	pBuffer = realloc ( pBuffer, sizeof(int)*3+(*cp + 1)*(sizeof(pessoa)	)	);
            c = (int*)pBuffer;
            cp =(int*)c + 1;
            i = cp + 1;
            fw = (pessoa*)(i + 1);
        }
	}
    if(*i == -1){
        printf("retirado com sucesso!<3\n");
    }
    else{
        printf("nome nao encontrado\n");
    }
}


void pesquisa(){
	pessoa *novo;
	novo = fw + ( *cp );
	printf("\nnome que sera buscado:");
    scanf(" %s",novo->nome);
	*i = 0;
	for((*c)=0;(*c) != *cp; (*c)++){
		if (strcmp( (fw+(*c))->nome,novo->nome ) == 0 && *i == 0) {
			printf("\nid:%d",(*c));
			printf("\nnome:%s\n",(fw+(*c))->nome);
			printf("idade:%d\n",(fw+(*c))->idade);
			printf("matricula:%d\n\n",(fw+(*c))->mat);
			*i = -1 ;
		}
	}
    if(*i != -1){
        printf("nome nao encontrado\n");
    }
}


void lista(){

    if(*cp == 0){
    printf("nao ha nomes na lista!\n");}

    else{
        for(*c=0 ; *c!=*cp ; (*c)++ ){
            printf("\n|id:%d",*c);
            printf("\n|nome:%s\n",(fw+(*c))->nome);
            printf("|idade:%d\n",(fw+(*c))->idade);
            printf("|matricula:%d\n\n",(fw+(*c))->mat);
        }
    }
}




int main(){

    inicializa();

  	do{
  	    printf("-----------\n   MENU\n-----------\n(1)adicionar a agenda:\n(2)retirar da agenda:\n(3)procurar:\n(4)lista:\n(5)insertionSort:\n(6)sair:\n--------\n    ");
        scanf("%d",&*i);

        switch(*i){

        	case 1:
                adiciona();
            break;

        	case 2:
      		    remover();
			break;

			case 3:
                pesquisa();
            break;

			case 4:
                lista();
            break;

            case 5:
                insertionSort();
            break;

            case 6:
            	free(pBuffer);
                return 0;
			break;

			default:
					printf("funcao indisponivel!\n");
			}
    }while(*i != 5);

}
