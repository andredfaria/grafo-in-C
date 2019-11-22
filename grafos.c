#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int tem_ligacao(int v1, int v2);
int tem_ligacao_r(int v1, int v2);

int v[5] = {0,0,0,0,0};
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
    int maiorGrau = 0;
<<<<<<< HEAD
    int indice;
    int nulo;
=======
    int maiorGrauD = 0;
>>>>>>> 28a76f8c08fe95de2899b8cfefece3f2f1a56d00
    
    /*gera matriz aleatoria com 1 ou 0 1=ligação | 0= sem ligação */
    srand(time(NULL));
    for(i=1;i<5;i++){
        for(j=0;j<=i-1;j++){
          grafo[ i ][ j ] = rand() % 2 ;
        }
    }

    /*mostra a matriz*/
    printf("A matriz ...\n\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            /*replica um lado da matriz para o outro lado da matriz*/
            grafo[i][j] = grafo[j][i];

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
               
            if(tem_ligacao(i, j) == 1)
                vetor[j]++;   

        }
    }

   printf("\n");

<<<<<<< HEAD
   for ( i = 1; i < 5; i++){
      if (vetor[i] > vetor[i+1])
=======
   for ( i = 0; i < 5; i++){
      if (vetor[i]> vetor[i+1])
>>>>>>> 28a76f8c08fe95de2899b8cfefece3f2f1a56d00
        maiorGrau = i;

      printf(" ligações do %i vertice = %3d\n", i, vetor[i-1]);

      if(vetor[i-1] == 0){
        indice = i-1;
        for(i=0;i<5;i++){

           if(grafo[indice][i] == 0)
             nulo++;

           if(grafo[i][indice] == 0)
             nulo++;

        }
      } 

   }

   printf("\n\n");

////////////////////////////////////////////////////////////////////////////////////
    printf("\nO Grafo tem %d Arestas ", graficoCompleto);
    
    if(vetor[0] ==  vetor[1] && vetor[2] ==  vetor[4] && vetor[2] ==  vetor[0])
        printf("\nO Grafo é regular");
        

    printf("\nO Grafo tem grau de %d", graficoCompleto);
    printf("\nO Maior grau é %d que é o  %d", vetor[maiorGrau], maiorGrau);

    if(graficoNULO == 10)
        printf("O grafico é nulo !\n");
   
   if(graficoCompleto == 10)
        printf("O grafico é completo ! ");

}

int tem_ligacao(int v1, int v2){
   if(grafo[v1][v2] == 1)
      return 1;

   return 0;
}


int tem_ligacao_r(int v1, int v2){
   if(grafo[v1][v2] == 1){
     v[v1]++;
     if(v1 == -1 || v2 == -1)
        return 0;
     tem_ligacao_r(v1, v2+1);

   }
   return 1;
}


/*
-----------------COMENTARIOS-------------------------------

http://lampiao.ic.unicamp.br/maratona/?name=implementa
https://pt.wikipedia.org/wiki/Lista_de_algoritmos#Algoritmos_de_grafos_2
https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html
https://www.inf.ufsc.br/grafos/definicoes/definicao.html
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