#include <SFML/Graphics.hpp>   // 24310225
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include <MusicaFondo.hpp>

int main() {
    MusicaFondo musicaFondo("assets/music/mario.mp3");
    musicaFondo.reproducir();

    Juego juego;
    juego.run();

    musicaFondo.detener();
    return 0;
}



