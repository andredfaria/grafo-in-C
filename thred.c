#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUMERO_THREADS 100 

// o codigo vai executando as treathes enquando vai dando printf até dar estouro de pilha

void *PRINT_THREAD( void *threadid ) {
	int tid;
	tid = ( int )threadid;
	printf( "Thread #%d!\n", tid );
	pthread_exit( NULL ); 
} 

int main ( int argc, char *argv[] ) { 
	int R, t;
	pthread_t threads[ NUMERO_THREADS ];

	while(1){
		for ( t = 0; t < NUMERO_THREADS; t++ ) { 
			printf( "criando mais uma thread\n");
			R = pthread_create( &threads[ t ], NULL, PRINT_THREAD, ( void * )t );
			if ( R ) { 
				printf( "ERRO %d\n", R );
				exit( -1 );
			}
			printf( "thread executada\n");
		}
	}
//	system( "pause" );

	pthread_exit( NULL );
}  