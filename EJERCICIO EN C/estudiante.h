#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#define MAX_MATERIAS 10
#define MAX_NOMBRE 50
#define MAX_NOMBRE_MATERIA 30
#define MAX_ASISTENCIAS 100
#define MAX_FECHA 11  // Para poder introducir fecha pidiendo dia,mes y año

// Clasificación para el estado de asistencia
typedef enum {
    ASISTIO,   // El estudiante asistió a la clase
    FALTA,     // El estudiante faltó a la clase
    TARDANZA   // El estudiante llegó tarde a la clase
} EstadoAsistencia;

// Estructura para la asistencia
struct Asistencia {
    char fecha[MAX_FECHA];               // Fecha de la asistencia en formato DD/MM/AAAA
    char materia[MAX_NOMBRE_MATERIA];    // Materia
    EstadoAsistencia estado;             // Estado de la asistencia
};

// Estructura Estudiante actualizada
struct Estudiante {
    char nombre[MAX_NOMBRE];                         // Nombre del estudiante
    int edad;                                        // Edad del estudiante
    float promedio;                                  // Promedio del estudiante
    char materias[MAX_MATERIAS][MAX_NOMBRE_MATERIA]; // Lista de materias cursadas
    int num_materias;                                // Número de materias cursadas
    struct Asistencia asistencias[MAX_ASISTENCIAS];  // Lista de asistencias registradas
    int num_asistencias;                             // Número de asistencias registradas
};

// Prototipos de funciones existentes
void ingresarDatosEstudiante(struct Estudiante *est); // Función para ingresar datos del estudiante
void ingresarMaterias(struct Estudiante *est);        // Función para ingresar materias cursadas
void mostrarEstudiante(struct Estudiante est);        // Función para mostrar datos del estudiante
void mostrarMaterias(struct Estudiante est);          // Función para mostrar materias cursadas
void limpiarBuffer();                                 // Función para limpiar el buffer de entrada


void registrarAsistencia(struct Estudiante *est);     // Función para registrar asistencia
void mostrarAsistencias(struct Estudiante est);       // Función para mostrar la asistencia
void mostrarAsistenciasPorMateria(struct Estudiante est); // Función para mostrar asistencia por materia
const char* estadoToString(EstadoAsistencia estado);  // Función para convertir el estado de asistencia a cadena
int validarFecha(const char *fecha);                  // Función para validar la fecha
int validarMateria(struct Estudiante est, const char *materia); // Función para validar la materia

#endif

//Fuente en la que nos hemos apoyado: Copilot