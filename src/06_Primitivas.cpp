#include <SFML/Graphics.hpp>
//Fernando Josue Ureña Navarro 2°K 09/06/2025
int main()
{
    sf::RenderWindow window(sf::VideoMode(1800, 1200), "SFML Window");
    window.setFramerateLimit(60);

    // Posición inicial
    float posX = 100;
    float posY = 100;
    // Velocidad en cada eje
    float velX = 2;
    float velY = 2;

    // Cargar la textura de la imagen dvd
    sf::Texture dvdTexture;
    if (!dvdTexture.loadFromFile("assets/images/dvd.png")) {
        return -1;
    }
    sf::Sprite dvdSprite(dvdTexture);
    dvdSprite.setPosition(posX, posY);

    // Obtener tamaño del sprite
    sf::FloatRect spriteBounds = dvdSprite.getLocalBounds();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Actualizar posición
        posX += velX;
        posY += velY;

        // Rebote en los bordes
        if (posX < 0) {
            posX = 0;
            velX = -velX;
        }
        if (posX + spriteBounds.width > window.getSize().x) {
            posX = window.getSize().x - spriteBounds.width;
            velX = -velX;
        }
        if (posY < 0) {
            posY = 0;
            velY = -velY;
        }
        if (posY + spriteBounds.height > window.getSize().y) {
            posY = window.getSize().y - spriteBounds.height;
            velY = -velY;
        }

        dvdSprite.setPosition(posX, posY);

        window.clear();
        window.draw(dvdSprite);
        window.display();
    }

    return 0;
}