#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#define MAX_MATERIAS 10
#define MAX_NOMBRE 50
#define MAX_NOMBRE_MATERIA 30

struct Estudiante {
    char nombre[MAX_NOMBRE];
    int edad;
    float promedio;
    char materias[MAX_MATERIAS][MAX_NOMBRE_MATERIA];
    int num_materias;
};

void ingresarDatosEstudiante(struct Estudiante *est);
void ingresarMaterias(struct Estudiante *est);
void mostrarEstudiante(struct Estudiante est);
void mostrarMaterias(struct Estudiante est);
void limpiarBuffer();

#endif