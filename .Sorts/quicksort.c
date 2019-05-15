#include<stdio.h>
#include<stdlib.h>

int* quickSort(int v[],int left,int rigth);
void swap(int* a,int* b);

int main(){
    int *v, n=10, i;
    v = malloc(sizeof (int) * (n));
    
    for(i=0; i!=n; i++){
        v[i] = rand()%100;
        printf("%d  ",v[i]);
    }

    quickSort(v,0,n-1);
        printf("\n");
    for(i=0; i!=n; i++){
        printf("%d  ",v[i]);
    }
    free(v);
    return 0;
}

void swap(int* a,int* b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
int* quickSort(int v[],int left,int rigth){
    int mid, j, i,tmp;
    i=left;
    j=rigth;
    mid = v[(j+i)/2];

    do{

        for(;mid>v[i];i++){}
        for(;mid<v[j];j--){}

        if(j>=i){
            swap(&v[j],&v[i]);
           j--;
           i++;
        }
    }while(j>=i);

    if(left<j){quickSort(v,left,j);}
    if(rigth>i){quickSort(v,i,rigth);}
}