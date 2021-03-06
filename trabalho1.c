
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define uteis
#define OFFSET 97
#define ALFABETO 26
#define true 1
#define false 0
#define bool int
#define INVALIDO -1
#define DEFAULT "Pais desconhecido\0"

// Estruturas de dados


struct Celula {
    char * pais;
    char * frase;
};

struct Dicionario {
    struct Celula letras[ALFABETO];
};




typedef struct Celula Celula;
typedef struct Dicionario Dicionario;

// Pesquisar : retorna true se a frase esta no dicionario, false caso contrario
int pesquisar(Dicionario * dicionario, char * frase) {
    for (int i = 0; i < ALFABETO; i++) {
        if (dicionario->letras[i].frase != NULL) {
            if (strcmp(dicionario->letras[i].frase, frase) == 0) {
                return i;
            }
        }
    }
    return INVALIDO;
}

// Inserir : insere par pais - frase no dicionario caso a primeira letra do pais esteja livre e retorna true, false caso nao insira
bool inserir(Dicionario * dicionario, char * pais, char * frase) {

    // ao invez de testar todas as letra, apenas diminuo OFFSET da primeira letra do pais, entao consigo a exta posição no alfabeto
     int i = ((int) pais[0]) -OFFSET;
    //for(int i=0; i != ALFABETO; i++){
     //   if( pais[0] == OFFSET + i && dicionario->letras[i].pais == NULL ){

            //antes, usava strlen para saber o tamanho para dar malloc, agora uso sizeof(pais)
            dicionario->letras[i].pais = (char*)malloc(sizeof(pais));
            strcpy( dicionario->letras[i].pais , pais );


            dicionario->letras[i].frase = (char*)malloc(sizeof(frase));


            strcpy( dicionario->letras[i].frase, frase );
       //     return true;
      //  }
    //}


    return false;
}

// Identificar : retorna a a traducao de "Feliz Natal!" no pais passado como parametro caso esteja no dicionario, retorna frase DEFAULT caso contrario
char * identificar(Dicionario * dicionario, char * frase) {

    for (int i = 0; i < ALFABETO; i++) {
        if(dicionario->letras[i].frase!= NULL ){
               if (strcmp(dicionario->letras[i].frase, frase) == 0)  {

                return (dicionario->letras[i].pais);
            }
        }


    }

    return DEFAULT;
}

//função que liberara a memoria
void fre(Dicionario *d){
    for(int i=0; i != ALFABETO; i++){
            free(d->letras[i].frase);
            free(d->letras[i].pais);
    }
    free(d);
}

// Inicializa dicionario
Dicionario * initDicionario() {
    Dicionario * d = (Dicionario *) malloc(sizeof(Dicionario));

    for (int i = 0; i < ALFABETO; i++) {
        d->letras[i].pais = NULL;
    }

    printf("Inserindo brasil\n");
    inserir(d, "brasil\0", "Feliz Natal!\0");

    printf("Inserindo alemanha\n");
    inserir(d, "alemanha", "Frohliche Weihnachten!\0");

    printf("Inserindo coreia\n");
    inserir(d, "coreia", "Chuk Sung Tan!\0");

    printf("Inserindo grecia\n");
    inserir(d, "grecia", "Kala Christougena!\0");

    printf("Inserindo estados-unidos\n");
    inserir(d, "estados-unidos", "Merry Christmas!\0");

    printf("Inserindo suecia\n");
    inserir(d, "suecia", "God Jul!");

    printf("Inserindo turquia\n");
    inserir(d, "turquia", "Mutlu Noeller\0");

    printf("Inserindo mexico\n");
    inserir(d, "mexico", "Feliz Navidad!\0");

    printf("Inserindo italia\n");
    inserir(d, "italia", "Buon Natale!\0");

    printf("Inserindo japao\n");
    inserir(d, "japao", "Merii Kurisumasu!\0");

    return d;
}

int main() {
    printf("---Inicializacao---\n");
    Dicionario * d = initDicionario();
    char * resultado;

    printf("\n---Testes de Validacao---\n");
    printf("1. Pesquisa por traducao existente");
    if (pesquisar(d, "Feliz Natal!\0") != INVALIDO) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL.\n" RESET);
    }

    printf("2. Pesquisa por traducao nao existente");
    if (pesquisar(d, "Nollaig Shona Dhuit!\0") == INVALIDO) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL.\n" RESET);
    }

    printf("3. Saudacao valida");
    if (strcmp(identificar(d, "Merii Kurisumasu!\0"), "japao") == 0) {

        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL.\n" RESET);
    }

    printf("4. Saudacao invalida");
    if (strcmp(identificar(d, "Nollaig Shona Dhuit!\0"), DEFAULT) == 0) {


        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL.\n" RESET);
    }

    //adicionada a função que liberara a memoria
    fre(d);

    return 0;
}
