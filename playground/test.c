#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

pthread_mutex_t mutex;

void *funcion(void *arg)
{
    int *i = (int *)arg;
	*i = 1;
	pthread_mutex_lock(&mutex); // Bloquear el acceso al recurso compartido
    while (*i <= 10)
    {
        printf("%i ", *i);
        (*i)++;
    }
	pthread_mutex_unlock(&mutex); // Desbloquear el acceso al recurso compartido
    pthread_exit(NULL); // Se agrega el retorno para evitar un warning
}

void *funcion2(void *arg)
{
    int *i = (int *)arg;
	*i = 1;
	printf("\n");
	pthread_mutex_lock(&mutex); // Bloquear el acceso al recurso compartido
    while (*i <= 10)
    {
        printf("%i ", *i * 2);
        (*i)++;
    }
	pthread_mutex_unlock(&mutex); // Desbloquear el acceso al recurso compartido
    pthread_exit(NULL); // Se agrega el retorno para evitar un warning
}

int main(void)
{
    int i = 0;
    int j = 5;
    pthread_t hilo;
    pthread_t hilo2;

	printf("Hilos [🟢]\n");
	pthread_mutex_init(&mutex, NULL); // Inicializar el mutex
    pthread_create(&hilo, NULL, &funcion, &i); // Pasar la dirección de 'i'

	pthread_create(&hilo2, NULL, &funcion2, &i); // Pasar la dirección de 'i'
    pthread_join(hilo, NULL);
    pthread_join(hilo2, NULL);

    return (0);
}
