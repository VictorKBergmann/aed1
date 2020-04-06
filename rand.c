#include<stdio.h>

int main (){
    int a,b[100];

    for(a=0;a!=100;a++){
        if((a/32)%2==0){
            b[a] = a;
        }
        else{
            b[a]=a*(-1);
        }
    }
     for(a=0;a!=100;a++){
         printf("%d     ",b[a]);
    }
    return 0;
}

