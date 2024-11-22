#include <stdio.h>
#include "main.h"
#include "estudiante.h"

// Función principal del programa que maneja el menú y las opciones del usuario
void ejecutarProgramaPrincipal(void) {
    struct Estudiante estudiante;
    estudiante.num_materias = 0; // Inicializa el número de materias a 0
    estudiante.num_asistencias = 0; // Inicializa el número de asistencias a 0
    int opcion;

    do {
        // Mostramos el menú principal
        printf("\n=== Menú Principal ===\n");
        printf("1. Ingresar datos del estudiante\n");
        printf("2. Mostrar datos del estudiante\n");
        printf("3. Registrar asistencia\n");
        printf("4. Mostrar todas las asistencias\n");
        printf("5. Mostrar resumen de asistencias por materia\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");

        // Recibe la opción seleccionada por el usuario
        if (scanf("%d", &opcion) != 1) {
            printf("Opción inválida. Intente nuevamente.\n");
            limpiarBuffer();
            continue;
        }
        limpiarBuffer();

        // Ejecuta la acción correspondiente a la opción elegida
        switch (opcion) {
            case 1:
                ingresarDatosEstudiante(&estudiante); // Ingresa los datos del estudiante
                break;
            case 2:
                mostrarEstudiante(estudiante); // Muestra los datos del estudiante
                break;
            case 3:
                registrarAsistencia(&estudiante); // Registra una asistencia
                break;
            case 4:
                mostrarAsistencias(estudiante); // Muestra todas las asistencias
                break;
            case 5:
                mostrarAsistenciasPorMateria(estudiante); // Muestra el resumen de asistencias por materia
                break;
            case 6:
                printf("Saliendo del programa...\n"); // Sale del programa
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n"); // Maneja errores
        }
    } while (opcion != 6); // Repetimos el menú hasta que el usuario elija salir
}

// Función principal que inicia el programa
int main() {
    ejecutarProgramaPrincipal();
    return 0;
}
//Fuente en la que nos hemos apoyado: Copilot