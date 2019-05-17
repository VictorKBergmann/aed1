#include<stdio.h>
#include<stdlib.h>

int merge_sort(int a[],int p, int r);
int merge(int *a,int p,int q, int r);

int main(){
    int *a,i,n=4;
    a= malloc(sizeof (int) * (n));

    for(i=0; i!=n; i++){
        a[i]=rand()%500;
        printf("%d  ",a[i]);

    }
    printf("\n");
    
    i=merge_sort(a,0,n-1);
   
    for(i=0; i!=n; i++){
        printf("%d  ",a[i]);
    }
    
    free(a);
    return 0 ;
}

int merge_sort(int a[],int p, int r){
    int q;
    if (p<r){
        q=((p+r)/2);
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
    return 0;
}

int merge(int *vetor,int inicio,int meio, int fim){
    int p1 = inicio;
    int p2 = meio + 1;
    int tamanho = fim - inicio + 1;
    int* tmp;
    int aux;
    tmp = (int*)malloc(sizeof(int)*tamanho);


    for(aux = 0; aux!=tamanho ;){
        tmp[aux++]=vetor[p1++];
    }
    p1 = 0;

    for(aux = 0; p1<=meio && p2<=fim; aux++){
        if(tmp[p1] < tmp[p2]){
            vetor[inicio++] = tmp[p1++];
        }
        else{vetor[inicio++] = tmp[p2++];
        }
    }
            
    while(p1<=meio){
        vetor[inicio++] = tmp[p1++];
    }
    while(p2<=fim){
        vetor[inicio++] = tmp[p2++];
    }

    free(tmp);
}