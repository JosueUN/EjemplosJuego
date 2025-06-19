#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../include/MusicaFondo.hpp"

int main() {
    MusicaFondo musicaFondo("assets/music/mario.mp3");
    musicaFondo.reproducir();

    Juego juego;
    juego.run();

    musicaFondo.detener(); // Opcional
    return 0;
}



