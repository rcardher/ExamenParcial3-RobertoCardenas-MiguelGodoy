#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

// Prototipo de la función
void mostrarEstudiante(struct Estudiante est);

#endif