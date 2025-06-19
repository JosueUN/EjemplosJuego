#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include <MusicaFondo.hpp>
#include <TileObstaculo.hpp>
#include <Fondo.hpp>

class MiniMario {
public:
    MiniMario(const std::string& rutaDer, const std::string& rutaIzq, sf::Vector2f pos) {
        if (!texturaDer.loadFromFile(rutaDer)) {
            std::cerr << "Error al cargar imagen: " << rutaDer << std::endl;
            exit(-1);
        }
        if (!texturaIzq.loadFromFile(rutaIzq)) {
            std::cerr << "Error al cargar imagen: " << rutaIzq << std::endl;
            exit(-1);
        }
        sprite.setTexture(texturaDer);
        sprite.setPosition(pos);
        mirandoDerecha = true;
    }
    void move(float x, float y) {
        sprite.move(x, y);
        if (x > 0 && !mirandoDerecha) {
            sprite.setTexture(texturaDer);
            mirandoDerecha = true;
        }
        if (x < 0 && mirandoDerecha) {
            sprite.setTexture(texturaIzq);
            mirandoDerecha = false;
        }
    }
    void setPosition(float x, float y) { sprite.setPosition(x, y); }
    sf::FloatRect getGlobalBounds() const { return sprite.getGlobalBounds(); }
    void draw(sf::RenderWindow& w) { w.draw(sprite); }
    sf::Vector2f getPosition() const { return sprite.getPosition(); }
    float getAncho() const { return sprite.getGlobalBounds().width; }
private:
    sf::Texture texturaDer;
    sf::Texture texturaIzq;
    sf::Sprite sprite;
    bool mirandoDerecha;
};