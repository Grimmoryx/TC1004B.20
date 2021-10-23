#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 20

//funcion global
int saldo;

pthread_mutex_t saldoLock = PTHREAD_MUTEX_INITIALIZER;

void* suma100(void* arg){
    int localsaldo;
    localsaldo += 100;
    saldo = localsaldo;
    pthread_exit(NULL);
}

void * printHola(void *arg){
    printf("Hola desde el hilo\n");
    pthread_exit(NULL);//se utiliza la funcion de dos maneras diferentes
                       //de preferencia que la función solo haga una cosa
}

int main(){
    pthread_t threads[NUM_THREADS];
    saldo = 0;
    /*
    for(int i = 0; i< NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, printHola, NULL);//el print hola se puede sustituir por las diferentes funciones
                                                           // nuestro programa. Cada funcion es un hilo diferente
                                                           // y se corren de manera simultanea.
    }*/

    for(int i; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, suma100, NULL);
    }
    printf("Saldo final %d\n", saldo);

    pthread_exit(NULL); //asi acaba el hilo, no es necesario el return 0
}