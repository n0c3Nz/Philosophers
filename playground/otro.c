#include <stdio.h>
#include <time.h>

int main() {
    // Obtener los segundos actuales desde el epoch
    time_t tiempo_actual;
    time(&tiempo_actual);

    // Convertir los segundos a una estructura de tiempo (struct tm)
    struct tm *info_tiempo = localtime(&tiempo_actual);

    // Convertir la estructura de tiempo a una cadena de caracteres formateada
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info_tiempo);

    // Imprimir la fecha y la hora formateada
    printf("Fecha y hora actual: %s\n", buffer);

    return 0;
}
