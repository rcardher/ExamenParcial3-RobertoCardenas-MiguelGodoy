#include <stdio.h>
#include <string.h>
#include "estudiante.h"

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void ingresarDatosEstudiante(struct Estudiante *est) {
    printf("\nIngrese los datos del estudiante\n");
    printf("Nombre: ");
    fgets(est->nombre, MAX_NOMBRE, stdin);
    est->nombre[strcspn(est->nombre, "\n")] = 0;

    do {
        printf("Edad: ");
        if (scanf("%d", &est->edad) != 1 || est->edad <= 0) {
            printf("Por favor, ingrese una edad válida.\n");
            limpiarBuffer();
        } else {
            break;
        }
    } while (1);

    do {
        printf("Promedio: ");
        if (scanf("%f", &est->promedio) != 1 || est->promedio < 0 || est->promedio > 10) {
            printf("Por favor, ingrese un promedio válido (0-10).\n");
            limpiarBuffer();
        } else {
            break;
        }
    } while (1);

    est->num_materias = 0;
    limpiarBuffer();

    // Después de ingresar los datos básicos, pedimos las materias
    ingresarMaterias(est);
}

void ingresarMaterias(struct Estudiante *est) {
    char respuesta;

    printf("\nIngreso de materias cursadas\n");
    do {
        if (est->num_materias >= MAX_MATERIAS) {
            printf("Ha alcanzado el límite máximo de materias (%d).\n", MAX_MATERIAS);
            break;
        }

        printf("\nIngrese el nombre de la materia %d: ", est->num_materias + 1);
        fgets(est->materias[est->num_materias], MAX_NOMBRE_MATERIA, stdin);
        est->materias[est->num_materias][strcspn(est->materias[est->num_materias], "\n")] = 0;

        // Verificar si la materia ya existe
        int duplicada = 0;
        for (int i = 0; i < est->num_materias; i++) {
            if (strcmp(est->materias[i], est->materias[est->num_materias]) == 0) {
                printf("Esta materia ya está registrada.\n");
                duplicada = 1;
                break;
            }
        }

        if (!duplicada) {
            est->num_materias++;
        }

        if (est->num_materias < MAX_MATERIAS) {
            do {
                printf("¿Desea ingresar otra materia? (s/n): ");
                scanf(" %c", &respuesta);
                limpiarBuffer();

                if (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N') {
                    printf("Por favor, responda con 's' o 'n'.\n");
                }
            } while (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N');
        }
    } while ((respuesta == 's' || respuesta == 'S') && est->num_materias < MAX_MATERIAS);

    printf("\nSe han registrado %d materias.\n", est->num_materias);
}

void mostrarEstudiante(struct Estudiante est) {
    printf("\n=== Datos del estudiante ===\n");
    printf("Nombre: %s\n", est.nombre);
    printf("Edad: %d años\n", est.edad);
    printf("Promedio: %.2f\n", est.promedio);
    mostrarMaterias(est);
}

void mostrarMaterias(struct Estudiante est) {
    printf("\n=== Materias cursadas (%d) ===\n", est.num_materias);
    if (est.num_materias == 0) {
        printf("No hay materias registradas.\n");
        return;
    }

    for (int i = 0; i < est.num_materias; i++) {
        printf("%d. %s\n", i + 1, est.materias[i]);
    }
}