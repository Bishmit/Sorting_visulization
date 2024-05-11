#include <SFML/Graphics.hpp>
#include "SortingVisualization.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Sorting Visualization");

	sf::RectangleShape algoButtonRects[5];
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		std::cerr << "Failed to load font!" << std::endl;
		return 1;
	}
	sf::Text algoButtonLabels[5];
	std::string algoNames[5] = { "Bubble Sort", "Insertion Sort", "Selection Sort", "Merge Sort", "Quick Sort" };
	for (int i = 0; i < 5; ++i) {
		algoButtonRects[i].setSize(sf::Vector2f(150, 50));
		algoButtonRects[i].setPosition(sf::Vector2f(window.getSize().x / 2 - 75, 50 + 100 * i));
		algoButtonRects[i].setFillColor(sf::Color::Blue);

		algoButtonLabels[i].setFont(font);
		algoButtonLabels[i].setString(algoNames[i]);
		algoButtonLabels[i].setCharacterSize(20);
		algoButtonLabels[i].setFillColor(sf::Color::White);
		algoButtonLabels[i].setPosition(algoButtonRects[i].getPosition().x + 10, algoButtonRects[i].getPosition().y + 15);
	}

	SortingVisualization* sortingVis = nullptr;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					for (int i = 0; i < 5; ++i) {
						if (algoButtonRects[i].getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
							switch (i) {
							case 0:
								sortingVis = new BubbleSortVisualization(window);
								break;
								// Add cases for other sorting algorithms here
							}
							break;
						}
					}
				}
			}
		}

		window.clear(sf::Color::White);

		for (int i = 0; i < 5; ++i) {
			window.draw(algoButtonRects[i]);
			window.draw(algoButtonLabels[i]);
		}

		if (sortingVis) {
			sortingVis->sort();
			delete sortingVis;
			sortingVis = nullptr;
		}

		window.display();
	}
	return 0;
}