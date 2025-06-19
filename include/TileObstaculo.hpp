#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include <MusicaFondo.hpp>
#include <MiniMario.hpp>
#include <Fondo.hpp>

class TileObstaculo {
public:
    TileObstaculo(sf::Texture& tileset, sf::IntRect tileRect, sf::Vector2f pos)
        : contado(false)
    {
        sprite.setTexture(tileset);
        sprite.setTextureRect(tileRect);
        sprite.setPosition(pos);
    }
    void move(float x, float y) { sprite.move(x, y); }
    void draw(sf::RenderWindow& w) { w.draw(sprite); }
    sf::FloatRect getGlobalBounds() const { return sprite.getGlobalBounds(); }
    float getX() const { return sprite.getPosition().x; }
    float getY() const { return sprite.getPosition().y; }
    bool contado;
private:
    sf::Sprite sprite;
};
