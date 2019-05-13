
#include<stdio.h>
#include<stdlib.h>

int* desloca(int vetor[], int n, int t);

int main(){
    int *v, m=10, i, t=7;
    v = malloc(sizeof (int) * (m));
    
    for(i=0; i!=m; i++){
        v[i] = i;
        printf("%d  \n",v[i]);
    }

    v = desloca(v,m,t);
    m++;

    for(i=0; i!=m; i++){
        printf("%d  ",v[i]);
    }
    return 0;
}
int* desloca(int vetor[], int n, int t){
    
    int *vitor, i;
    vitor = malloc(sizeof (int) * (n + 1));
    for(i=0; n > i && t > vetor[i] ; i++ ){
    }
    
    for(n--; n > 0 && n != i; n--){
        vitor[n+1] = vetor[n];
        
        }
            
        vitor[n+1] = t;
        
        for(; n >= 0; n--){
            vitor[n] = vetor[n];
        }

    
    free(vetor);
    return vitor;
}