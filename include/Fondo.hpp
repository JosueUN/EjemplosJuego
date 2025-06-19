#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include <MusicaFondo.hpp>
#include <MiniMario.hpp>
#include <TileObstaculo.hpp>

class Fondo {
public:
    Fondo(const std::string& ruta) {
        if (!textura.loadFromFile(ruta)) {
            std::cerr << "Error al cargar la imagen de fondo: " << ruta << std::endl;
            exit(-1);
        }
        sprite.setTexture(textura);
        sf::Vector2u tamañoOriginal = textura.getSize();
        float escalaX = 800.f / tamañoOriginal.x;
        float escalaY = 700.f / tamañoOriginal.y;
        sprite.setScale(escalaX, escalaY);
    }
    void draw(sf::RenderWindow& w) { w.draw(sprite); }
private:
    sf::Texture textura;
    sf::Sprite sprite;
};