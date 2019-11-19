#include <stdio.h>

int main(){
    int grafo[5][5] = { -1,-1,-1,-1,-1,
                        -1,-1,-1,-1,-1,
                        -1,-1,-1,-1,-1,
                        -1,-1,-1,-1,-1,
                        -1,-1,-1,-1,-1,};
/*
http://lampiao.ic.unicamp.br/maratona/?name=implementa
https://pt.wikipedia.org/wiki/Lista_de_algoritmos#Algoritmos_de_grafos_2
https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html
-1 = não precisa dessa informção, informação redundate 
0  = nenhuma ligação
1  = ligagação enter eixo x e eixo y

exemplo
  A  B  C 
A -  -  -
B 1  -  -
C 0  1  -
 
*/
    int i,j;
    int graficoNULO = 0;
    int graficoCompleto = 0;

    for(i=1;i<5;i++){
        for(j=0;j<=i-1;j++){

          grafo[ i ][ j ] = rand() % 2 ;
        }
    }


    printf("A matriz ...\n\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }

    for(i=1;i<5;i++){
        for(j=0;j<=i-1;j++){
            if(grafo[i][j] == 0)
                graficoNULO++;

            if(grafo[i][j] == 1)
               graficoCompleto++;
               if(grafo[i+1][j] == 1){

               }
        }
    }


    if(graficoNULO == 10)
        printf("O grafico é nulo !\n");
   
   if(graficoCompleto == 10)
        printf("O grafico é completo !");


}

/* vertex pa[1000];
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
}*/
