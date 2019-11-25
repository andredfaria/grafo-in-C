#include <stdio.h>
#include <stdlib.h>
#include<time.h>


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
    int indice = 0;
    int ligacao = 0;
    int n = 0;
    char letras[] = {"ABCDE"};
    
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
      printf("%c", letras[i]);
      
        for(j=0;j<5;j++){
            /*replica um lado da matriz para o outro lado da matriz*/
            grafo[i][j] = grafo[j][i];
            printf("%3d ", grafo[i][j]);
        }
        printf("\n");
    }

    for (i=0;i<5;i++){
      printf(" %3c", letras[i]);
    }
    

    for(i=1;i<5;i++){
        for(j=0;j<=i-1;j++){

            //printf("%d - %d\n", i, j);

            if(grafo[i][j] == 0)
                graficoNULO++;

            if(grafo[i][j] == 1){
              vetor[j]++;  
              graficoCompleto++;
            }
            /*   
            if(tem_ligacao(i, j) == 1){
                printf("tem\n");
                vetor[j]++;   
            }

            if(nao_tem_ligacao(i, j) == 1){
                printf("naoTem\n");
                vetor[j]++;   
            }*/

        }
    }

  ;

  j=1;
  for (i = 0; i < 5; i++){ 
      if(grafo[i][j] == 1)
        


      if(vetor[i] > maiorGrau){
        maiorGrau = vetor[i];
        indice = i;
      }    
  }
 printf("\n---------------------");
////////////////////////////////////////////////////////////////////////////////////
    printf("\nO Grafo tem %d Arestas \n", graficoCompleto);
    printf("Suas ligações são:\n");
    for(i=1;i<5;i++){
        for(j=0;j<=i-1;j++){
          if(grafo[i][j] == 1)
            printf(" de %c a %c\n", letras[i], letras[j]);

      }
    }
    printf("---------------------");
    printf("\nO Grafo tem %d Arestas ", graficoCompleto);
    
    if(vetor[0] ==  vetor[1] && vetor[2] ==  vetor[4] && vetor[2] ==  vetor[0])
        printf("\nO Grafo é regular");
        

    printf("\nO Grafo tem grau %d", graficoCompleto);
    printf("\nO Maior grau é %d que é o  %c \n", maiorGrau, letras[indice]);

    if(graficoNULO == 10)
        printf("O grafico é nulo !\n");
   
   if(graficoCompleto == 10)
        printf("O grafico é completo ! \n");
  
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