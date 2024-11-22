cmake_minimum_required(VERSION 3.29)  # Corrección del nombre
project(ExamenParcial3_RobertoCardenas_MiguelGodoy LANGUAGES C CXX)  # Añadido soporte para C++ también

# Configuración del estándar de C y C++
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Incluye directorios
include_directories("EJERCICIO EN C")
include_directories("EJERCICIO EN C++")

# Primer ejecutable en C
add_executable(ExamenParcial3_RobertoCardenas_MiguelGodoyEJC
        "EJERCICIO EN C/estudiante.c"
        "EJERCICIO EN C/main.c"
)

# Segundo ejecutable en C++
add_executable(ejercicio2
        "EJERCICIO EN C++/main.cpp"
        "EJERCICIO EN C++/estudiante.cpp"
)
