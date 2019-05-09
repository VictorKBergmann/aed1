#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char *nome;
    int idade, mat;
    }pessoa ;

int *aux,*contadorPessoa,*menu,*caracteres;
void *pBuffer;
pessoa *fw,*novo;
char *temp;
 
void inicializa(){
    //cria a posicao dos ponteiros
    pBuffer = malloc (sizeof(int)*4 + sizeof(char)*(37) +(4)*(sizeof(pessoa)    )	);
    aux = (int*)pBuffer;
    contadorPessoa =(int*)aux + 1;
    *contadorPessoa = 4;
    menu = contadorPessoa + 1;
    fw = (pessoa*)(menu + 1);
    novo = fw;
    temp = (char*)(fw + ( *contadorPessoa ));

    novo->nome = temp;
    strcpy ( novo->nome ,"1");
    novo->idade = 1;
    novo->mat = 1;
    novo ++;
    temp+=strlen(temp) + 1;

    novo->nome = temp;
    strcpy( novo->nome ,"2");
    novo->idade = 2;
    novo->mat = 2;
    novo ++;
    temp+=strlen(temp) + 1;

    novo->nome = temp;
    strcpy( novo->nome ,"admin");
    novo->idade = 1;
    novo->mat = 1;
    novo ++;
    temp+=strlen(temp) + 1;

    novo->nome = temp;
    strcpy( novo->nome ,"Victor");
    novo->idade = 19;
    novo->mat = 18104996;
    temp+=strlen(temp) + 1;

}

void reaponta(){
    
	//reapontando as variaveis
    pBuffer = realloc ( pBuffer, sizeof(char)*((*caracteres)+20) + sizeof(int)*4 + ( *contadorPessoa ) * ( sizeof(pessoa) ) );
    aux = (int*)pBuffer;
    contadorPessoa =(int*)aux + 1;
    menu = contadorPessoa + 1;
    caracteres = menu + 1;
    fw = (pessoa*)(caracteres + 1);
    novo = fw + ( *contadorPessoa - 1 );

    //transfere os char
    temp = (char*)novo;
    for(*menu=*caracteres; *menu > 0 ; (*menu)--){
    	*(temp + *menu) = *(temp + sizeof(pessoa) + *menu);
    }

    //reaponta os nomes
    temp = (char*)(novo + 1);
    (fw)->nome = temp;

    for(*menu=1; *menu != *contadorPessoa ; (*menu)++){
        temp = temp + (strlen(temp) + 1);
        //for(*temp != '\0'; temp++){}
        temp++;
        ( fw+ (*menu) ) -> nome = temp;
    }
}

void adiciona(){
    *contadorPessoa+=1;

    //adiciona o nome
    printf("nome:");
    scanf(" %s", temp );
    *caracteres = *caracteres + strlen( temp ) + 1; 

    reaponta();

    //adinona o resto
    printf("idade:");
    scanf("%d",&novo->idade);
    printf("matricula:");
    scanf("%d",&novo->mat);

    }

/*
void remover(){
	pessoa *novo;
	novo = fw + ( *contadorPessoa );
	printf("nome:");
    scanf(" %s",novo->nome);

    for(*aux= 0;*aux != (*contadorPessoa) && *menu != -1 ; (*aux)++){

        if(strcmp( (fw+(*aux))->nome,novo->nome ) == 0 ){
            (*contadorPessoa)-=1;
            while( *aux != *contadorPessoa){
                strcpy( (fw+( *aux - 1 ))->nome , (fw+( *aux ))->nome );
	    		*aux+=1;
	    	}
	    	*menu = -1;

            reaponta();
            temp = (char*)novo + 1;
            fw.nome = temp;

            for(; fw[*menu] != fw[*contadorPessoa] ; (*menu)++){
                for(temp != '\0'; temp++){

                 }
                temp++;
                fw[(*menu)] = temp;

            }
        }
	}

    if(*menu == -1){
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
	*menu = 0;
	for((*aux)=0;(*aux) != *contadorPessoa; (*aux)++){
		if (strcmp( (fw+(*aux))->nome,novo->nome ) == 0 && *menu == 0) {
			printf("\nid:%d",(*aux));
			printf("\nnome:%s\n",(fw+(*aux))->nome);
			printf("idade:%d\n",(fw+(*aux))->idade);
			printf("matricula:%d\n\n",(fw+(*aux))->mat);
			*menu = -1 ;
		}
	}
    if(*menu != -1){
        printf("nome nao encontrado\n");
    }
}
*/

void lista(){

    if(*contadorPessoa == 0){
    printf("nao ha nomes na lista!\n");}

    else{
        for(*aux=0 ; *aux!=*contadorPessoa ; (*aux)++ ){
            printf("\n|id:%d",*aux);
            printf("\n|nome:%s\n",(fw+(*aux))->nome);
            printf("|idade:%d\n",(fw+(*aux))->idade);
            printf("|matricula:%d\n\n",(fw+(*aux))->mat);
        }
    }
}
/*
void insertionSort(){
    novo = fw + ( *contadorPessoa );
    for( (*aux)=1; (*aux) < (*contadorPessoa); (*aux)++){
        *menu = (*aux) - 1;
        //memcpy(novo,&(fw[*menu]),sizeof(pessoa));
        strcpy( novo->nome , (fw+( *aux))->nome );
        novo->mat =(fw+( *aux ))->mat;
        novo->idade =(fw+( *aux ))->idade;

        while(( (*menu)>=0 ) && (novo->mat < ((fw+ (*menu))->mat ) )){

           // memcpy(&(fw[*menu]), &(fw[(*menu)+1]),sizeof(pessoa));
            strcpy( (fw+( * i +1 ))->nome , (fw+( *menu ))->nome );
            (fw+( *menu + 1 ))->mat =(fw+( *menu ))->mat;
            (fw+( *menu + 1 ))->idade =(fw+( *menu ))->idade;
            (*menu)--;
        }
        //memcpy(novo,&(fw[(*menu)+1]),sizeof(pessoa));
        strcpy( (fw+( *menu + 1 ))->nome, novo->nome );
        (fw+( *menu + 1))->mat= novo->mat;
        (fw+( *menu + 1))->idade = novo->idade;
    }
}
*/



int main(){


    inicializa();

  	do{
  	    printf("-----------\n   MENU\n-----------\n(1)adicionar a agenda:\n(2)retirar da agenda:\n(3)procurar:\n(4)lista:\n(5)sair:\n--------\n    ");
        scanf("%d",&*menu);

        switch(*menu){

        	case 1:
                adiciona();
            break;

        	case 2:
//     		    remover();
			break;

			case 3:
//                pesquisa();
            break;

			case 4:
                lista();
            break;

            case 5:
//                insertionSort();
            break;

            case 6:
            	*menu=-1;
            	free(pBuffer);
                return 0;
			break;

			default:
                printf("funcao indisponivel!\n");
			}
    }while(*menu != -1);

}
