#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include <MiniMario.hpp>
#include <Fondo.hpp>
#include <TileObstaculo.hpp>


class Juego {
public:
    Juego()
        : ventana(sf::VideoMode(800, 600), "Mario en picada"),
          jugador("assets/images/marioDer.png", "assets/images/marioIzq.png", {385, 100}),
          fondo("assets/images/fondo.png")
    {
        ventana.setFramerateLimit(60);
        obsVel = 2;
        generar = 0;
        puntaje = 0;
        pausado = false;
        if (!fuente.loadFromFile("assets/fonts/arial.ttf")) exit(-1);
        if (!tileset.loadFromFile("assets/images/tiles.png")) exit(-1);
        puntajeTexto.setFont(fuente);
        puntajeTexto.setString("Puntaje: 0");
        puntajeTexto.setCharacterSize(36);
        puntajeTexto.setFillColor(sf::Color::White);
        puntajeTexto.setPosition(260, 10);
        std::srand(std::time(0));
    }

    void run() {
        while (ventana.isOpen()) {
            sf::Event evento;
            while (ventana.pollEvent(evento)) {
                if (evento.type == sf::Event::Closed)
                    ventana.close();
            }

            if (!pausado) {
                manejarInput();
                generarObstaculos();
                moverObstaculos();
                contarPuntaje();
                eliminarObstaculos();
                checarColision();
                obsVel += 0.002f;
            } else {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                    reiniciar();
                }
            }

            dibujar();
        }
    }

private:
    sf::RenderWindow ventana;
    MiniMario jugador;
    Fondo fondo;
    std::vector<TileObstaculo> obstaculos;
    sf::Texture tileset;
    float obsVel;
    float generar;
    int puntaje;
    bool pausado;
    sf::Font fuente;
    sf::Text puntajeTexto;

    void manejarInput() {
        float ancho = jugador.getAncho();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            jugador.move(-6.6f, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            jugador.move(6.6f, 0);

        sf::Vector2f pos = jugador.getPosition();
        if (pos.x < 0) jugador.setPosition(0, pos.y);
        if (pos.x + ancho > 800) jugador.setPosition(800 - ancho, pos.y);
    }

    void generarObstaculos() {
        generar++;
        if (generar > 90) {
            generar = 0;
            int espacioX = rand() % 650;
            sf::IntRect tileRect(0, 0, 50, 20);
            for (int x = 0; x < espacioX; x += 50) {
                obstaculos.emplace_back(tileset, tileRect, sf::Vector2f((float)x, 600));
            }
            for (int x = espacioX + 150; x < 800; x += 50) {
                obstaculos.emplace_back(tileset, tileRect, sf::Vector2f((float)x, 600));
            }
        }
    }

    void moverObstaculos() {
        for (auto& obs : obstaculos)
            obs.move(0, -obsVel);
    }

    void contarPuntaje() {
        for (auto& obs : obstaculos) {
            if (!obs.contado && obs.getX() == 0 && obs.getY() + 20 < jugador.getPosition().y) {
                puntaje++;
                obs.contado = true;
                puntajeTexto.setString("Puntaje: " + std::to_string(puntaje));
            }
        }
    }

    void eliminarObstaculos() {
        obstaculos.erase(std::remove_if(obstaculos.begin(), obstaculos.end(),
            [](TileObstaculo& o) { return o.getY() + 20 < 0; }), obstaculos.end());
    }

    void checarColision() {
        for (auto& obs : obstaculos) {
            if (jugador.getGlobalBounds().intersects(obs.getGlobalBounds()))
                pausado = true;
        }
    }

    void reiniciar() {
        jugador.setPosition(385, 100);
        obstaculos.clear();
        obsVel = 2;
        generar = 0;
        puntaje = 0;
        puntajeTexto.setString("Puntaje: 0");
        pausado = false;
    }

    void dibujar() {
        ventana.clear();
        fondo.draw(ventana);
        jugador.draw(ventana);
        for (auto& obs : obstaculos)
            obs.draw(ventana);
        ventana.draw(puntajeTexto);

        if (pausado) {
            sf::Text pausa("ENTER para reiniciar", fuente, 40);
            pausa.setFillColor(sf::Color::Red);
            pausa.setPosition(200, 250);
            ventana.draw(pausa);
        }
        ventana.display();
    }
};