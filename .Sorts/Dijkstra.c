#include <stdio.h>
#include <stdlib.h>

#define tamanho 20

void dijkstra(int grafo[tamanho][tamanho], int origem, int destino) {
    int i, atual, nova, min, aux;
    int anterior[tamanho], distancia[tamanho],fechado[tamanho];

   for(i = 0; i < tamanho; i++) {
        distancia[i] = 1000000;        //inicializa os auxiliares
        fechado[i] = 0;
        anterior[i] = -1; 
    }
    atual = origem;
    distancia[atual] = 0;
    while( atual != destino && atual != -1) {  // não para enquanto não terminar(chegar no destino)
        for(i = 0; i < tamanho; i++) {  //testa o atual com todos
            if(grafo[atual][i] != 0 && fechado[i] == 0) { // entra caso for diferente e não tiver fechado
                nova = distancia[atual] + grafo[atual][i];
                if(nova < distancia[i]) { // atualiza a distancia
                    anterior[i] = atual;
                    distancia[i] = nova;

                }
            }
        }
        fechado[atual] = 1; // fecha
        min = 1000000;
        atual = -1;
        for(i = 0; i < tamanho; i++) {
            if(fechado[i] == 0 && distancia[i] < min) {  // testa com todos os vertices
                min = distancia[i];                     // e escolhe a menos distancia
                atual = i;
            }
        }
    }
    if(atual == destino) {
        printf("\n\ndistacia de '%d' ate '%d' e %d", origem, destino, distancia[atual]);
        printf("\nantecessores: ");
        aux = destino; //prints
        while(aux >= 0) {
            printf("    %d",aux);
            aux = anterior[aux];
        }
    }
    else printf("/nnão existe caminho entre %d e %d",origem,destino);
}

int main(){
    int matriz[tamanho][tamanho],inicio, fim;
    
    int j,i;
    for(i=0; i < tamanho; i++ )
        for( j = 0; j < tamanho; j++)//inicializa toda matriz com 0
            matriz[i][j] = 0;   

    int numArestas, distacia;
    int origem, dest;
    printf("Numero de ligacoes: ");
    scanf("%d",&numArestas);
    for(; 0 < numArestas; numArestas--) {
        printf("\nvertice de origem: ");//inicializa as ligaçoes
        scanf(" %d",&origem);
        printf("vertice de destino: ");
        scanf(" %d",&dest);
        printf("distacia: ");
        scanf("%d",&distacia);        
        if(distacia < 0)return 1;
        matriz[origem][dest] = distacia;
    }
    printf("\nvertice inicial: ");
    scanf(" %d",&inicio);
    printf("vertice final: ");//origem e destino
    scanf(" %d",&fim);

    dijkstra(matriz, inicio,fim);

    return 0;
}