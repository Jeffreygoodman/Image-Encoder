

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"
void transform(sf::Image& image, FibLFSR* lfsr);

int main(int argc, char* argv[])
{
	FibLFSR lfsr(argv[3]);
	sf::Image image;
	if (!image.loadFromFile(argv[1]))
		return -1;

	

	sf::Vector2u size = image.getSize();
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "picture");
sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Encrypted picture");

	sf::Texture texture;
    sf::Texture texture2;
	texture.loadFromImage(image);

	sf::Sprite sprite;
    sf::Sprite sprite2;
	sprite.setTexture(texture);
    transform(image,&lfsr);
    texture2.loadFromImage(image);
    sprite2.setTexture(texture2);
//we have created two seperate sprites to store the new encrypted image and display it in tandem with the normal one.
	while (window1.isOpen() && window2.isOpen()) {
sf::Event event;
while (window1.pollEvent(event)) {
if (event.type == sf::Event::Closed)
window1.close();
}
while (window2.pollEvent(event)) {
if (event.type == sf::Event::Closed)
window2.close();
}
window1.clear();
window1.draw(sprite);
window1.display();

window2.clear();

window2.draw(sprite2);
window2.display();
}

	
	if (!image.saveToFile(argv[2]))
		return -1;

	return 0;
}
void transform(sf::Image& image, FibLFSR* lfsr)
{

sf::Color c;
sf::Vector2u size = image.getSize();//get the size of any image passed into the function
for (unsigned int x = 0; x<size.x; x++) {
		for (unsigned int y = 0; y< size.y; y++) {//go through every pixel and change each rgb value with the FibLFSR
			c = image.getPixel(x, y);
			c.r = c.r ^ lfsr->generate(8);
			c.g = c.g ^ lfsr->generate(8);
			c.b = c.b ^ lfsr->generate(8);
			image.setPixel(x, y, c);//set the new pixels
		}
	}

}