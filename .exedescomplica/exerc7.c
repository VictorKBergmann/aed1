#include<stdio.h>
#include<stdlib.h>

int procura(int vetor[], int n, int t);

int main(){
    int *v, n=10, i, t=7;
    v = malloc(sizeof (int) * (n));
    
    for(i=0; i!=n; i++){
        v[i] = i;
    }

    i = procura(v,n,t);
    n++;

    printf("%d",i);

    return 0;
}

int procura(int vetor[], int n, int t){
    
    int *vitor, i;

    for(i=0; n > i; i++ ){
        if( t == vetor[i])
        return i;
    }
    if(n == i){
        return -1;
    }
    
}