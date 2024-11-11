# Proyecto: get_next_line

![get_next_line Grade](https://github.com/ayogun/42-project-badges/raw/main/badges/get_next_linem.png)

## Español
El proyecto **get_next_line** consiste en crear una función en C que lea una línea de un _file descriptor_ a la vez, facilitando la manipulación de archivos de texto o entradas estándar en programas.

### Características
- Lee una línea completa por cada llamada a `get_next_line`.
- Soporta múltiples _file descriptors_ simultáneamente.
- Gestión eficiente de la memoria para evitar fugas.

### Requisitos del sistema
- `cc`
- `make`

### Instrucciones de uso
1. Clona el repositorio:  
   `git clone https://github.com/tuusuario/get_next_line.git`
2. Compila la librería:  
   `make`
3. Incluye la librería en tu proyecto:  
   `gcc tuarchivo.c -L. -lgnl`

## English
The **get_next_line** project involves creating a function in C that reads one line at a time from a file descriptor, making it easier to handle text files or standard input in programs.

### Features
- Reads one complete line per call to `get_next_line`.
- Supports multiple file descriptors simultaneously.
- Efficient memory management to prevent leaks.

### System requirements
- `cc`
- `make`

### Usage instructions
1. Clone the repository:  
   `git clone https://github.com/youruser/get_next_line.git`
2. Compile the library:  
   `make`
3. Include the library in your project:  
   `gcc yourfile.c -L. -lgnl`

### Autor / Author
Juan Carlos Herreros 
