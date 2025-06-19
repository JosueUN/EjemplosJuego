# Proyecto.cpp — Juego SFML Ejemplo

Este proyecto es un ejemplo de juego desarrollado en C++ utilizando la biblioteca [SFML] para gráficos, audio y manejo de ventanas. El código está modularizado en clases y cada clase se encuentra en su propio archivo `.hpp` para facilitar el mantenimiento y la escalabilidad.

## Características

- Juego tipo arcade donde controlas a un personaje (MiniMario) que debe esquivar obstáculos.
- Fondo animado y música de fondo.
- Puntaje que aumenta al esquivar obstáculos.
- Código orientado a objetos.


## Requisitos

- [SFML 2.5+]
- Compilador C++ compatible (MinGW64 recomendado)
- [Msys2]
- Visual Studio Code.

## Compilación y Ejecución

1. **Instala todas las libreias y modifica el path como en las instrucciones de instalacion** 
2. **Ejecuta el juego**:
    "make runProyecto" en la terminal de compilacion.

## Uso

- Usa las flechas izquierda y derecha para mover al personaje.
- Esquiva los obstáculos para aumentar tu puntaje.
- Pulsa `Enter` para reiniciar el juego si pierdes.

## Archivos principales

- `Proyecto.cpp`: Archivo principal que inicializa y ejecuta el juego.
- `Fondo.hpp`: Clase para el fondo del juego.
- `MiniMario.hpp`: Clase para el personaje principal.
- `TileObstaculo.hpp`: Clase para los obstáculos.
- `Juego.hpp`: Lógica principal del juego.
- `MusicaFondo.hpp`: Música de fondo.

