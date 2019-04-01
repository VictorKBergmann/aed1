#include <stdio.h>
#include <stdlib.h>

void imprimeBuffer(void *pBuffer, unsigned int nTotal){
    unsigned int aux,tam;

    void *aut;
    tam= sizeof(int)+sizeof(float)+sizeof(double);
    aut = pBuffer;
    for(aux = 0;aux!=nTotal;aux++){

       printf("%d	",*(int*)aut);
       (int *)aut++;
       printf("%f	",*(float*)aut);
       (float*)aut++;
       printf("%lf\n",*(double*)aut);
	printf("fo2i\n");

    }
}
void *cria(unsigned int nTotal){
    void *maloc,*aux;

    maloc = malloc(sizeof(int)+sizeof(float)+sizeof(double));
    aux = maloc;

    for(;nTotal!=0;nTotal--){

            *(int*)aux =(10000);
            (int*)aux++;
            *(float*)aux =(10000);
            (float*)aux++;
            *(double*)aux = (double)(10000);
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
