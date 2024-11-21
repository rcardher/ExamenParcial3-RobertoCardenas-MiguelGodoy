#include <stdio.h>
#include <string.h>
#include "main.h"
#include "estudiante.h"

void ejecutarPrograma(void) {
    // Crear un estudiante de ejemplo
    struct Estudiante estudiante1;

    // Asignar valores
    strcpy(estudiante1.nombre, "Roberto Cárdenas");
    estudiante1.edad = 18;
    estudiante1.promedio = 8.5;

    // Mostrar los datos
    mostrarEstudiante(estudiante1);
}

int main() {
    ejecutarPrograma();
    return 0;
}