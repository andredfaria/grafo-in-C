#include <stdio.h>
#include <stdlib.h>

char getCidade(int c);
char CidadeP[30];
char CidadeS[30];

int main(){
    int i,j;
    int c1, c2;
    int distancias[10][10] = {
                                0, 44,121,116,142, 80, 74,107, 77,163,
                               44,  0, 75, 79, 98, 37, 81, 77, 35,121,
                              121, 75,  0, 36, 32, 43, 56,129, 85,129,
                              116, 79, 36,  0, 28, 41, 91,121, 78, 93,
                              142, 98, 32, 28,  0, 66, 81,145,102,117,
                               80, 37, 43, 41, 66,  0, 63, 84, 41,103,
                               74, 81, 56, 91, 81, 63,  0,157,114,176,
                              107, 77,129,121,145, 84,157,  0, 46, 76,
                               77, 35, 85, 78,102, 41,114, 46,  0,121,
                              163,121,129, 93,117,103,176, 76,121,  0,
};

    /* Disatancias das ciadades em KM
    0  Muzambinho
    1  Botelhos
    2  São joão da Boa Vista
    3  Andradas
    4  Espirito Santo do pinhal
    5  Poços de Caldas
    6  São José do Rio Pardo
    7  Machado
    8  Campestre 
    9 Pouso Alegre
    */


   for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%5d", distancias[i][j]);

        }
        printf("\n");        
        
    }


        printf("Digite para saber a distancia entre duas cidades e os caminho mais curto \n\n");
        printf(" 0 Muzambinho\n 1  Botelhos\n 2  São joão da Boa Vista\n 3  Andradas\n 4  Espirito Santo do pinhal\n 5  Poços de Caldas\n 6  São José do Rio Pardo\n 7  Machado\n 8  Campestre \n 9 Pouso Alegre");
        printf("\n\nPrimeira cidade\n");    
        scanf(" %d", &c1);
        printf("Segunda cidade\n");
        scanf(" %d", &c2);
        

        printf("%d %d",  c1, c2);
        char a = getCidade(c1);
        printf("\n A distantica entre %s é de %d", a , distancias[c1][c2]);
}

char getCidade(int c){

    char Cidade[30];
        switch (c)
        {
        case 0: 
        Cidade[30] = (char) "Muzambinho";
    break;
        case 1:
        Cidade[30] = (char) "Botelhos";
    break;
        case 2:
        Cidade[30] = (char) "São joão da Boa Vista";
    break;
        case 3:
        Cidade[30] = (char) "Andradas";
    break;
        case 4:
        Cidade[30] = (char) "Espirito Santo do pinhal";
    break;
        case 5:
        Cidade[30] = (char) "Poços de Caldas";
    break;
        case 6:
        Cidade[30] = (char) "São José do Rio Pardo";
    break;
        case 7:
        Cidade[30] = (char) "Machado";
    break;
        case 8:
        Cidade[30] = (char) "Campestre ";
    break;
        case 9:
        Cidade[30] = (char) "Pouso Alegre";    
    break;
        
        default:
            break;   

    return Cidade;
    }
}
