#include "SortingVisualization.h"

SortingVisualization::SortingVisualization(sf::RenderWindow& win) : window(win) {
    // Initialize array with random heights
    srand(time(NULL));
    int windowWidth = window.getSize().x;
    int windowHeight = window.getSize().y;
    int arraySize = windowWidth / RECT_WIDTH;
    for (int i = 0; i < arraySize; ++i) {
        array.push_back(rand() % (windowHeight / 5));
    }
}

SortingVisualization::~SortingVisualization() {}

BubbleSortVisualization::BubbleSortVisualization(sf::RenderWindow& win) : SortingVisualization(win) {}

void BubbleSortVisualization::sort() {
    int n = array.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; ++i) {
            if (array[i - 1] > array[i]) {
                std::swap(array[i - 1], array[i]);
                swapped = true;

                // Animation of swapping elements
                sf::Vector2f pos1(i * RECT_WIDTH, window.getSize().y - array[i] * 5);
                sf::Vector2f pos2((i - 1) * RECT_WIDTH, window.getSize().y - array[i - 1] * 5);
                sf::Vector2f dir((pos2 - pos1) / RECT_MOVE_SPEED);

                // Move rectangles
                sf::Clock clock;
                while (clock.getElapsedTime().asSeconds() < SORT_SPEED) {
                    window.clear(sf::Color::White);

                    // Draw rectangles representing array elements
                    for (int j = 0; j < n; ++j) {
                        sf::RectangleShape rect(sf::Vector2f(RECT_WIDTH - 2, array[j] * 5));
                        if (j == i)
                            rect.setPosition(pos1 + dir * clock.getElapsedTime().asSeconds());
                        else if (j == i - 1)
                            rect.setPosition(pos2 - dir * clock.getElapsedTime().asSeconds());
                        else
                            rect.setPosition(j * RECT_WIDTH, window.getSize().y - array[j] * 5);
                        // Generate color based on height
                        sf::Color color(0, array[j] * 5, 255 - array[j] * 2);
                        rect.setFillColor(color);
                        window.draw(rect);
                    }

                    // Display the current state
                    window.display();
                }
            }
        }
    } while (swapped);
}
