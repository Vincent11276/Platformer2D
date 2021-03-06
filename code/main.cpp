#include <iostream>
#include <string>
using namespace std;


#include <SFML/Graphics.hpp>

#include "AnimatedSprite.hpp"


int main()
{
    std::string spriteSheetPath = "C:\\Users\\Vincent\\Documents\\GitHub\\Platformer2D-Game\\assets\\Intellect Devourer Sprites.png";

    sf::Texture texture;
    if (!texture.loadFromFile(spriteSheetPath))
        return EXIT_FAILURE;

    Animation animation;
    if (!animation.loadSpriteSheet("idle", texture, sf::Vector2i(32, 32)))
        return EXIT_FAILURE;

    AnimationPack animationPack;
    animationPack.animations.push_back(animation);

    AnimatedSprite animatedSprite(animationPack);
    animatedSprite.play(0);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Animated Sprite Demo.");
    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();

                default:
                    break;
            }
        }
        animatedSprite.update();

        window.clear();

        window.draw(animatedSprite);

        window.display();
    }



    return EXIT_SUCCESS;
}