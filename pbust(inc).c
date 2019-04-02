#include <stdio.h>
#include <stdlib.h>

void imprimeBuffer(void *pBuffer, unsigned int nTotal){
    unsigned int aux,tam;

    void *aut;
    tam= sizeof(int)+sizeof(float)+sizeof(double);
    aut = pBuffer;
    for(;nTotal!=0;nTotal--){

       printf("%d	",*(int*)aut);
       aut+=sizeof(int);
       printf("%f	",*(float*)aut);
       aut+=sizeof(float);
       printf("%lf  \n",*(double*)aut);
       aut+=sizeof(double);
	printf("fo2i\n");

    }
}
void *cria(unsigned int nTotal){
    void *maloc,*aux;

    maloc = malloc(sizeof(int)+sizeof(float)+sizeof(double));
    aux = maloc;

    for(;nTotal!=0;nTotal--){

            *(int*)aux =(10000);
            aux+=sizeof(int);
            *(float*)aux =(10000);
            aux+=sizeof(float);
            *(double*)aux =(10000);
            aux+=sizeof(double);3
    }
	printf("foi\n");
    return maloc;
}

int main(){
    void *pBuffer;
    unsigned int nTotal;
    printf("diga quantos conjuntos:\n");
    scanf("%d",&nTotal);

    pBuffer = cria(nTotal);
    imprimeBuffer(pBuffer,nTotal);
   
    return 0;
}
