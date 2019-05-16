#include<stdio.h>
#include<stdlib.h>


void BubbleSort (int data[],int n);

int main(){
    int *v, n=3, i;
    v = malloc(sizeof (int) * (n));
    
    for(i=0; i!=n; i++){
        v[i] = 10 - i;
        printf("%d  ",v[i]);

    }

    BubbleSort(v,n);

    
    printf("\n");
    
    for(i=0; i!=n; i++){
        printf("%d  ",v[i]);
    }
    free(v);

    return 0;
}

void BubbleSort (int data[],int n) { 
	int tmp,i,j; 
	for (i=0; i<n-1; i++) { 
		for (j=0; j <( n -i -1); j++) {
			if (data[j] > data[j+1]) { 
				tmp = data[j]; 
				data[j] = data[j+1]; 
				data[j+1] = tmp; 
			} 
		}
	} 
}
