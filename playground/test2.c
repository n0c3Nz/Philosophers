#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int	main(void)
{
	printf("Hilos [🔴]\n");
	int i = 1;
	while (i <= 10)
	{
		printf("%i ", i);
		i++;
	}
	i = 1;
	printf("\n");
	while (i <= 10)
	{
		printf("%i ", i * 2);
		i++;
	}
	return (0);
}
