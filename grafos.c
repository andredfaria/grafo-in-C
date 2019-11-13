// https://www.ime.usp.br/~pf/algoritmos_para_grafos/

#include <stdio.h>

int main(){
    int grafo[5][5];
    int i,j;
    int graficoNULO;

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
           grafo[ i ][ j ] = rand() % 2 ;
        }
    }


    prinf("A matriz � ...");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }

     for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(grafo[i][j] == 0)
                graficoNULO++
        }
    }


    if(graficoNULO == 25)
        printf("O grafico � nulo !");

    
}



// vertex pa[1000];
// int dist[1000];

void GRAPHsptD0( Graph G, vertex s) 
{ 
   for (vertex v = 0; v < G->V; ++v) 
      pa[v] = -1;
   pa[s] = s, dist[s] = 0; 

   while (true) {
      int min = INFINITY;
      vertex x, y;
      for (vertex v = 0; v < G->V; ++v) {
         if (pa[v] == -1) continue;
         for (link a = G->adj[v]; a != NULL; a = a->next) {
            if (pa[a->w] != -1) continue;
            if (dist[v] + a->cst < min) {
               min = dist[v] + a->cst;
               x = v, y = a->w;
            }
         }
      }
      if (min == INFINITY) // A 
         break; // B
      pa[y] = x, dist[y] = min;
   }
}