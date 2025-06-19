#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include <TileObstaculo.hpp>
#include <MiniMario.hpp>
#include <Juego.hpp>
#include <Fondo.hpp>

class MusicaFondo {
public:
    MusicaFondo(const std::string& archivo) {
        if (!musica.openFromFile(archivo)) {
            std::cerr << "No se pudo cargar la música: " << archivo << std::endl;
        }
    }
    void reproducir() {
        musica.setLoop(true);
        musica.play();
    }
    void detener() {
        musica.stop();
    }
private:
    sf::Music musica;
};