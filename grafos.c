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


    prinf("A matriz é ...");
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
        printf("O grafico é nulo !");

}
