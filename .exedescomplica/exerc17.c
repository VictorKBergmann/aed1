#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void BubbleSort (char *data[],int n);

int main(){

    int i,j,tam;
    char **p,aux[20];
    p=malloc(3*sizeof(char*));

    for(i=0;i!=3;i++){
        scanf("%s",aux);
        tam = strlen(aux) + 1;
        p[i] = (char*)(malloc(sizeof(char)*tam));
        strcpy(p[i],aux);
    }
    
    BubbleSort(p,3);

    for(i=0;i!=3;i++){
        printf("\n%s",p[i]);
    }
    for(i=0;i!=3;i++){
        free(p[i]);
    }
    free(p);
    
}


void BubbleSort (char **data,int n) { 
	int i,j; 
    char *tmp;
	for (i=0; i<n-1; i++) { 
		for (j=0; j < (n -i -1); j++) {
			if ((int)data[j][0] > (int)data[j+1][0]) { 
				tmp = data[j]; 
				data[j]=data[j+1]; 
				data[j+1]=tmp; 
			} 
		}
	} 
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion(char* str, char* aux,int tam){
    int i,j;
    for(i=0 ; (i < tam) && strcmp((str + i),aux) != 1; i += strlen(str + i) + 1);
    if(i < tam){
        for(j = tam - 1 ; j >= i + strlen(aux) + 1 ; j--)
        str[j] = str[j - strlen(aux) - 1];
    }
        strcpy((str + i),aux);  
}

int main(){
    char* str,aux[20];
    int i,j,tam=0;
        printf("diga o nome:");
        scanf("%s",aux);
        tam = strlen(aux) + 1;
        str=(char*)malloc(sizeof(char)*tam);
        strcpy(str,aux);
        insertion(str,aux,tam);
        printf("%s\n",str);
   
   
    for(j=0;j<4;j++){
        printf("diga o nome:");
        scanf("%s",aux);
        str=(char*)realloc(str,sizeof(char)*tam + strlen(aux) + 1);
        tam += strlen(aux) + 1;
        insertion(str,aux,tam);
        for(i=0;i<tam;i++){
            printf("%c",&str[i]);
        }
    }
    return 0;
}*/