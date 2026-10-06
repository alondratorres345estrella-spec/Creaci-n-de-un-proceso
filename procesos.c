#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // Clonamos el proceso para crear al hijo
    pid = fork();

    if (pid < 0) {
        // Ocurrió un error al intentar clonar el proceso
        fprintf(stderr, "Error al crear el proceso hijo.\n");
        return 1;
    } 
    else if (pid == 0) {
        // Código que ejecuta únicamente el PROCESO HIJO
        for (int i = 1; i <= 10000; i++) {
            printf("[Hijo] Número: %d\n", i);
        }
    } 
    else {
        // Código que ejecuta únicamente el PROCESO PADRE
        for (int i = 1; i <= 10000; i++) {
            printf("[Padre] Número: %d\n", i);
        }
    }

    return 0;
}

