#include<stdio.h>
#include<stdlib.h>

void insertionSort(int v[],int n){
    int i,j,tmp;

    for(j=1 ;j < n; j++){
        i=j-1;
        tmp= v[j];
        while(i>=0 && v[i]>tmp){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = tmp;
    }
}


int main(){
    int *v, n=10, i;
    v = malloc(sizeof (int) * (n));
    
    for(i=0; i!=n; i++){
        v[i] = rand()%100;
        printf("%d  ",v[i]);

    }

    insertionSort(v,n);

    
    printf("\n");
    
    for(i=0; i!=n; i++){
        printf("%d  ",v[i]);
    }
    free(v);

    return 0;
}
