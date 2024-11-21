#include <stdio.h>
#include "main.h"
#include "estudiante.h"

void ejecutarPrograma(void) {
    struct Estudiante estudiante;
    int opcion;

    do {
        printf("\n=== Menú Principal ===\n");
        printf("1. Ingresar datos del estudiante\n");
        printf("2. Mostrar datos del estudiante\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Opción inválida. Intente nuevamente.\n");
            limpiarBuffer();
            continue;
        }
        limpiarBuffer();

        switch (opcion) {
            case 1:
                ingresarDatosEstudiante(&estudiante);
            break;
            case 2:
                mostrarEstudiante(estudiante);
            break;
            case 3:
                printf("Saliendo del programa...\n");
            break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 3);
}

int main() {
    ejecutarPrograma();
    return 0;
}