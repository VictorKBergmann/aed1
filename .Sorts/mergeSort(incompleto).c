#include<stdio.h>
#include<stdlib.h>

int main(){
    int a[20],i;
    for(i=0; i!=20; i++){
        a[i]=rand()%500;
        printf("%d  ",a[i]);
    }
    printf("\n\noi");
    i=merge_sort(a,0,19);
    for(i=0; i!=20; i++){
        printf("%d  ",a[i]);
    }
    return 0 ;
}

int merge_sort(int a[],int p, int r){
    int q;
    if (p<r){
        q=((p+r)/2);
        printf("%d\n",p);
        merge_sort(a,p,q);
        printf("%d\n",p);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
    return 0;
}

int merge(int *a,int p,int q, int r){
    int n1,n2,i,j,k;
    
    n1 = r-p +1;
    n2 = r-q;
    int l[n1+1] , t[n2+1];
    for(i=0;i!=n1;i++){
        l[i]=a[p+i];
    }    
    for(i=0;i!=n2;i++){
        t[i]=a[q+i];
    }
    
    l[n1]=500;
    t[n2]=500;
    i=0;
    j=0;
    
    for(p;p!=r;p++){
        if(l[i]<=t[j]){
            a[p]=l[i];
            i++;
        }
        else{
            a[p]=t[j];
            j++;
        }
    }
    return 0;
}
