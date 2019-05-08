
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char nome;
    int idade, mat;
    }pessoa ;


int *c,*contadorPessoa,*i,*n;
void *pBuffer;
pessoa *fw,*novo;
char *primeiroNome,*temp;

/*void inicializa(){
    pessoa *novo;
    pBuffer = malloc (sizeof(int)*4 + sizeof(char)*((*n)+20) +(5)*(sizeof(pessoa)    )	);
    c = (int*)pBuffer;
    cp =(int*)c + 1;
    *contadorPessoa = 4;
    i = cp + 1;
    fw = (pessoa*)(i + 1);
    novo = fw;
    strcpy( novo->nome ,"1");
    novo->idade = 1;
    novo->mat = 1;
    novo ++;
    strcpy( novo->nome ,"2");
    novo->idade = 2;
    novo->mat = 2;
    novo ++;
    strcpy( novo->nome ,"admin");
    novo->idade = 1;
    novo->mat = 1;
    novo ++;
    strcpy( novo->nome ,"Victor");
    novo->idade = 19;
    novo->mat = 18104996;
*/



void reaponta(){
    
	//reapontando as variaveis
    pBuffer = realloc ( pBuffer, sizeof(char)*((*n)+20) + sizeof(int)*4 + ( *contadorPessoa ) * ( sizeof(pessoa) ) );
    c = (int*)pBuffer;
    contadorPessoa =(int*)c + 1;
    i = contadorPessoa + 1;
    n = i + 1;
    fw = (pessoa*)(n + 1);
    novo = fw + ( *contadorPessoa - 1 );

    //transfere os char
    temp = (char*)novo;
    for(*i=*n; *i > 0 ; (*i)--){
    	*(temp + *i) = *(temp + sizeof(pessoa) + *i);
    }

    //reaponta os nomes
    temp = (char*)(novo + 1);
    (fw)->nome = temp;

    for(*i=1; *i != *contadorPessoa ; (*i)++){
        temp = temp + (strlen(temp) + 1);
        //for(*temp != '\0'; temp++){}
        temp++;
        ( fw+ (*i) ) -> nome = (pessoa*)temp;
    }
}

void adiciona(){
    *contadorPessoa+=1;

    //adiciona o nome
    printf("nome:");
    scanf(" %s", temp );
    *n = *n + strlen( temp ) + 1; 

    reaponta();

    //adinona o resto
    printf("idade:");
    scanf("%d",&novo->idade);
    printf("matricula:");
    scanf("%d",&novo->mat);

    }


void remover(){
	pessoa *novo;
	novo = fw + ( *contadorPessoa );
	printf("nome:");
    scanf(" %s",novo->nome);

    for(*c= 0;*c != (*contadorPessoa) && *i != -1 ; (*c)++){

        if(strcmp( (fw+(*c))->nome,novo->nome ) == 0 ){
            (*contadorPessoa)-=1;
            while( *c != *contadorPessoa){
                strcpy( (fw+( *c - 1 ))->nome , (fw+( *c ))->nome );
	    		*c+=1;
	    	}
	    	*i = -1;

            reaponta();
            temp = (char*)novo + 1;
            fw.nome = temp;

            for(; fw[*i] != fw[*contadorPessoa] ; (*i)++){
                for(temp != '\0'; temp++){

                 }
                temp++;
                fw[(*i)] = temp;

            }
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
	novo = fw + ( *contadorPessoa );
	printf("\nnome que sera buscado:");
    scanf(" %s",novo->nome);
	*i = 0;
	for((*c)=0;(*c) != *contadorPessoa; (*c)++){
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

    if(*contadorPessoa == 0){
    printf("nao ha nomes na lista!\n");}

    else{
        for(*c=0 ; *c!=*contadorPessoa ; (*c)++ ){
            printf("\n|id:%d",*c);
            printf("\n|nome:%s\n",(fw+(*c))->nome);
            printf("|idade:%d\n",(fw+(*c))->idade);
            printf("|matricula:%d\n\n",(fw+(*c))->mat);
        }
    }
}

void insertionSort(){
    novo = fw + ( *contadorPessoa );
    for( (*c)=1; (*c) < (*contadorPessoa); (*c)++){
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




int main(){

    inicializa();

  	do{
  	    printf("-----------\n   MENU\n-----------\n(1)adicionar a agenda:\n(2)retirar da agenda:\n(3)procurar:\n(4)lista:\n(5)sair:\n--------\n    ");
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
            	i=-1;
            	free(pBuffer);
                return 0;
			break;

			default:
                printf("funcao indisponivel!\n");
			}
    }while(*i != -1);

}
