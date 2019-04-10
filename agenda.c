#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char nome[20];
    int idade, mat,id;
    }pessoa ;


int *c,*cp,*i;
void *pBuffer;
pessoa *fw;


void adiciona(){
    pessoa *novo;
    *cp+=1;
    pBuffer = realloc ( pBuffer, sizeof(int)*3+(*cp + 1)*(sizeof(pessoa)	)	);
    c = (int*)pBuffer;
    cp =(int*)c + 1;
    i = cp + 1;
    fw = (pessoa*)i + 1;
    novo = fw + ( *cp - 1 );

	novo->id = *cp - 1;  
    printf("nome:");
    scanf(" %s",novo->nome);
    printf("idade:");
    scanf("%d",&novo->idade);
    printf("matricula:");
    scanf("%d",&novo->mat);

    }
   
void remover(){
	pessoa *novo;
	novo = fw + ( *cp - 1 );
	printf("nome:");
    scanf(" %s",novo->nome); 
    *i = *cp;
    for(*c=0 ;*c != *cp && *i != -1 ; *c++){
        
        if(strcmp( (fw+(*c))->nome,novo->nome ) == 0 ){
	    	
            while( *i != *c){
                strcpy( (fw+( *i - 1 ))->nome , (fw+( *i ))->nome );
	    		*i--;
	    	}
	    	*i = -1;
        }
	}
    if(*i = -1){
        printf("retirado com sucesso!<3\n");
    }
    else{
        printf("nome nao encontrado\n");
    }
}
   

/*int pesquisar(Dicionario * dicionario, char * frase) {
    for (int i = 0; i < ALFABETO; i++) {
        if (dicionario->letras[i].frase != NULL) {
            if (strcmp(dicionario->letras[i].frase, frase) == 0) {
                return i;
            }
        }
    }
    return INVALIDO;
}*/

void pesquisa(){
	pessoa *novo;
	novo = fw + ( *cp - 1 );
	printf("\nnome:");
    scanf(" %s",novo->nome);
	*i = 0;
	for(*c=0;*c != *cp; *c++){	
		if (strcmp( (fw+(*c))->nome,novo->nome ) == 0 ) {
			printf("\nid:%d",(fw+(*c))->id);
			printf("\nnome:%s\n",(fw+(*c))->nome);
			printf("idade:%d\n",(fw+(*c))->idade);
			printf("matricula:%d\n\n",(fw+(*c))->mat);
		}	
	}
    if(*i != 0){
        printf("nome nao encontrado\n");
    }
}


void lista(){

    for(*c=0 ; *c!=*cp ; (*c)++ ){
    printf("\n|id:%d",(fw+(*c))->id);
	printf("\n|nome:%s\n",(fw+(*c))->nome);
	printf("|idade:%d\n",(fw+(*c))->idade);
	printf("|matricula:%d\n\n",(fw+(*c))->mat);
    }

}




int main(){

    pBuffer = malloc((sizeof(int)*2));
	c=(int*)pBuffer;
	cp =(int*)c + 1;
    i = cp + 1;
	fw = (pessoa*)i + 1;
    *cp = 0;


  	do{
  	    printf("--------\n   MENU\n--------\n(1)adicionar a agenda:\n(2)retirar da agenda:\n(3)procurar:\n(4)lista:\n(5)sair:\n--------\n    ");
        scanf("%d",&*c);

        switch(*c){

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
			
            default:
            	free(pBuffer);
                return 0;
			break;
	        }

    }while(*c>0 && *c < 5);

}
