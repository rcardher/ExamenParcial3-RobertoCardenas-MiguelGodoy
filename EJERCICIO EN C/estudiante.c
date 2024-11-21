#include <stdio.h>
#include "estudiante.h"

void mostrarEstudiante(struct Estudiante est) {
    printf("Datos del estudiante:\n");
    printf("Nombre: %s\n", est.nombre);
    printf("Edad: %d años\n", est.edad);
    printf("Promedio: %.2f\n", est.promedio);
}