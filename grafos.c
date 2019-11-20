#include <stdio.h>
#include <stdlib.h>

int tem_ligacao(int v1, int v2);

int grafo[5][5] = {  -1,-1,-1,-1,-1,
                     -1,-1,-1,-1,-1,
                     -1,-1,-1,-1,-1,
                     -1,-1,-1,-1,-1,
                     -1,-1,-1,-1,-1,};

int main(){
    int i,j;
    int graficoNULO     = 0;
    int graficoCompleto = 0;
    int vetor[5]        = {0,0,0,0,0};
    int vetoraux[5]     = {0,0,0,0,0};

    for(i=1;i<5;i++){
        for(j=0;j<=i-1;j++){

          grafo[ i ][ j ] = rand() % 2 ;
        }
    }


    printf("A matriz ...\n\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%3d ", grafo[i][j]);
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
                vetoraux[i]++;
               }

            if(tem_ligacao(i,j) == 1){
               

            }
        }
    }

    printf("\nO Grafo tem %d Arestas ", graficoCompleto);

    if(graficoNULO == 10)
        printf("O grafico é nulo !\n");
   
   if(graficoCompleto == 10)
        printf("O grafico é completo ! ");


   printf("\n\n\n");

   for ( i = 0; i < 5; i++){
      printf(" %3d", vetor[i]);
   }
   printf("\n");
   for ( i = 0; i < 5; i++){
      printf(" %3d", vetoraux[i]);
   }

}

int tem_ligacao(int v1, int v2){
   if(grafo[v1][v2])
      return 1;

   return 0;
}


/*
-----------------COMENTARIOS-------------------------------

http://lampiao.ic.unicamp.br/maratona/?name=implementa
https://pt.wikipedia.org/wiki/Lista_de_algoritmos#Algoritmos_de_grafos_2
https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html
https://pt.slideshare.net/mcastrosouza/grafos-representao

-1 = não precisa dessa informção, informação redundate 
0  = nenhuma ligação
1  = ligagação enter eixo x e eixo y

exemplo
  A  B  C 
A -  -  -
B 1  -  -
C 0  1  -
 
*/