#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX 100 

// o codigo vai executando as treathes enquando vai dando printf até dar estouro de pilha

void *imprimeProcesso( void *pip ) {
	long long int n;
	n = ( long long int )pip;
	printf( "processo #%lld\n", n );
	pthread_exit( NULL ); 
} 

int main ( int argc, char *argv[] ) { 
	int p1[2], p2[2], processo, t,descritor;
	pthread_t threads[ MAX ];

	if((pipe(p1) < 0) || (pipe(p2) < 0)){ 
        printf("Erro na chamada PIPE");
	    exit(0);
	}

    if ( (descritor = fork()) <0){ 
        printf("Erro na chamada FORK");
    	exit(0);
	}else{	
        close(p1[0]); 
		close(p2[1]);
		
		while(1){
			for ( t = 0; t < MAX; t++ ) { 
				printf( "criando mais um processo\n");
				processo = pthread_create( &threads[ t ], NULL, imprimeProcesso, (void *)t );
				if (processo) { 
					printf( "ERRO %d\n", processo );
					exit(0);
				}
				printf( "processo executado\n");
				
			}
		}
		close(p1[1]);
		close(p2[0]);
		exit(0);

	}
	//	system( "pause" );
	pthread_exit( NULL );
}  

// links
// http://www.di.ubi.pt/~operativos/praticos/html/9-threads.html
// https://www.man7.org/linux/man-pages/man3/pthread_create.3.html
// https://daemoniolabs.wordpress.com/2012/08/12/usando-pipes-em-c-no-linux/
