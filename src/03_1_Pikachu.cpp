#include <SFML/Graphics.hpp>

class Personaje
{
public:
    Personaje(sf::Vector2f position, sf::Color color)
    {
        shape.setSize(sf::Vector2f(120, 120)); // Tamaño igual al frame del mono
        shape.setPosition(position);
        shape.setFillColor(color);

        // Cargar la imagen desde un archivo
        if (!texture.loadFromFile("assets/images/monkey.jpg"))
        {
            // Manejar error si es necesario
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position);
        sprite.setTextureRect(sf::IntRect(0, 3 * frameHeight, frameWidth, frameHeight)); // Primer frame de la cuarta fila
    }

    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(this->shape);
        window.draw(this->sprite);
    }

    void update(){
        // Animar los 4 changos de la cuarta fila (fila 3, columnas 0-3)
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 3 * frameHeight, frameWidth, frameHeight));
            clock.restart();
        }
    }

private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.15f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 4; // Solo 4 frames en la cuarta fila
    int frameWidth = 80;
    int frameHeight = 115;
};

double velocidad = .5;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Monkey Jumpey");

    Personaje mono(sf::Vector2f(400, 300), sf::Color::Transparent);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            mono.move(-velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            mono.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            mono.move(0, -velocidad);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            mono.move(0, velocidad);
        }

        // Actualizar animación del mono
        mono.update();

        // Fondo verde fuerte
        window.clear(sf::Color(55, 153, 64));
        mono.draw(window);
        window.display();
    }

    return 0;
}