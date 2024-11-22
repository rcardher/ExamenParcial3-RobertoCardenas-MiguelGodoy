#include <stdio.h>
#include <string.h>
#include "estudiante.h"

// Función para limpiar el buffer de entrada
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Función para ingresar los datos del estudiante
void ingresarDatosEstudiante(struct Estudiante *est) {
    printf("\nIngrese los datos del estudiante\n");
    printf("Nombre: ");
    fgets(est->nombre, MAX_NOMBRE, stdin);
    est->nombre[strcspn(est->nombre, "\n")] = 0;

    // Solicita la edad del estudiante y valida la entrada
    do {
        printf("Edad: ");
        if (scanf("%d", &est->edad) != 1 || est->edad <= 0) {
            printf("Por favor, ingrese una edad válida.\n");
            limpiarBuffer();
        } else {
            break;
        }
    } while (1);

    // Solicita el promedio del estudiante y valida la entrada
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

// Función para ingresar las materias del estudiante
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

// Función para mostrar los datos del estudiante
void mostrarEstudiante(struct Estudiante est) {
    printf("\n=== Datos del estudiante ===\n");
    printf("Nombre: %s\n", est.nombre);
    printf("Edad: %d años\n", est.edad);
    printf("Promedio: %.2f\n", est.promedio);
    mostrarMaterias(est);
}

// Función para mostrar las materias del estudiante
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

// Función para registrar una asistencia
void registrarAsistencia(struct Estudiante *est) {
    if (est->num_asistencias >= MAX_ASISTENCIAS) {
        printf("Ha alcanzado el límite máximo de asistencias (%d).\n", MAX_ASISTENCIAS);
        return;
    }

    struct Asistencia *asistencia = &est->asistencias[est->num_asistencias];

    printf("\nIngrese la materia: ");
    fgets(asistencia->materia, MAX_NOMBRE_MATERIA, stdin);
    asistencia->materia[strcspn(asistencia->materia, "\n")] = 0;

    printf("Ingrese la fecha (DD/MM/AAAA): ");
    fgets(asistencia->fecha, MAX_FECHA, stdin);
    asistencia->fecha[strcspn(asistencia->fecha, "\n")] = 0;

    int estado;
    do {
        printf("Ingrese el estado (0: Asistió, 1: Falta, 2: Tardanza): ");
        if (scanf("%d", &estado) != 1 || estado < 0 || estado > 2) {
            printf("Por favor, ingrese un estado válido.\n");
            limpiarBuffer();
        } else {
            asistencia->estado = (EstadoAsistencia)estado;
            break;
        }
    } while (1);

    est->num_asistencias++;
    limpiarBuffer();
    printf("Asistencia registrada correctamente.\n");
}

// Función para mostrar todas las asistencias registradas
void mostrarAsistencias(struct Estudiante est) {
    printf("\n=== Asistencias registradas (%d) ===\n", est.num_asistencias);
    if (est.num_asistencias == 0) {
        printf("No hay asistencias registradas.\n");
        return;
    }

    for (int i = 0; i < est.num_asistencias; i++) {
        struct Asistencia asistencia = est.asistencias[i];
        printf("Fecha: %s, Materia: %s, Estado: %s\n", asistencia.fecha, asistencia.materia, estadoToString(asistencia.estado));
    }
}

// Función para mostrar el resumen de asistencias por materia
void mostrarAsistenciasPorMateria(struct Estudiante est) {
    printf("\n=== Resumen de asistencias por materia ===\n");
    if (est.num_asistencias == 0) {
        printf("No hay asistencias registradas.\n");
        return;
    }

    for (int i = 0; i < est.num_materias; i++) {
        printf("\nMateria: %s\n", est.materias[i]);
        for (int j = 0; j < est.num_asistencias; j++) {
            if (strcmp(est.asistencias[j].materia, est.materias[i]) == 0) {
                printf("Fecha: %s, Estado: %s\n", est.asistencias[j].fecha, estadoToString(est.asistencias[j].estado));
            }
        }
    }
}

// Función para convertir el estado de asistencia a cadena
const char* estadoToString(EstadoAsistencia estado) {
    switch (estado) {
        case ASISTIO: return "Asistió";
        case FALTA: return "Falta";
        case TARDANZA: return "Tardanza";
        default: return "Desconocido";
    }
}

//Fuente en la que nos hemos apoyado: Copilot