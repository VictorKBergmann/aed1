#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct pessoa{
    char nome[20];
    int idade, mat;
    };


void* adiciona(void *pBuffer,int cpm, int *c, int cp*,float *a){
    cp* ++;
    pBuffer = realloc( pBuffer, sizeof(int)*2)+sizeof(float)+(cp*sizeof(pessoa));
    c = (int)pBuffer;
    cp = c + 1;
    a = cp + 1;

    printf("nome:");
    scanf("%s")
}


int main(){
    void *pBuffer;
    int *c,*cp;
    float *a;
    pBuffer = malloc((sizeof(int)*2)+sizeof(float));

    printf("(1)adicionar a agenda:\n(2)retirar da agenda:\n(3)procurar:");
    switch(*c){
    case 1:adiciona(pBuffer);
    case 2:retira(pBuffer);
    case 3:procura(pBuffer);
    case 4:lista(pBuffer);

    }
}
