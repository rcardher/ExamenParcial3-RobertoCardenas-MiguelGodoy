#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include <vector>
#include <stdexcept>

// Estructura para almacenar la información de una asistencia
struct Asistencia {
    std::string fecha;    // Fecha de la asistencia en formato YYYY-MM-DD
    std::string materia;  // Nombre de la materia
    std::string estado;   // Estado de la asistencia: "asistió", "falta", "tardanza"
};

// Estructura para almacenar la información de un estudiante
struct Estudiante {
    std::string nombre;               // Nombre del estudiante
    int edad;                         // Edad del estudiante
    float promedio;                   // Promedio de calificaciones del estudiante
    std::vector<std::string> materias; // Lista de materias del estudiante
    std::vector<Asistencia> asistencias; // Lista de asistencias del estudiante
};

// Clase para manejar excepciones de fecha inválida
class FechaInvalidaException : public std::runtime_error {
public:
    // Constructor que recibe un mensaje de error
    FechaInvalidaException(const std::string& mensaje);
};

// Clase para manejar excepciones de materia no registrada
class MateriaNoRegistradaException : public std::runtime_error {
public:
    // Constructor que recibe un mensaje de error
    MateriaNoRegistradaException(const std::string& mensaje);
};

// Declaraciones de funciones
void mostrarEstudiante(const Estudiante& estudiante); // Muestra la información del estudiante
void mostrarMaterias(const Estudiante& estudiante);   // Muestra las materias del estudiante
void registrarAsistencia(Estudiante& estudiante, const Asistencia& asistencia); // Registra una asistencia
void mostrarAsistencias(const Estudiante& estudiante); // Muestra las asistencias del estudiante
Estudiante crearEstudiante(); // Crea un nuevo estudiante
bool validarFecha(const std::string& fecha); // Valida el formato de una fecha
void registrarAsistencias(Estudiante& estudiante); // Registra asistencias para todas las materias de un estudiante

#endif // ESTUDIANTE_H