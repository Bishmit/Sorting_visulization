#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>

const int RECT_WIDTH = 8; // Adjust this value for the width of rectangles
const float SORT_SPEED = 0.005f; // Adjust this value for sorting speed
const float RECT_MOVE_SPEED = 1.0f; // Adjust this value for the speed of rectangles' movement

class SortingVisualization {
protected:
    std::vector<int> array;
    sf::RenderWindow& window;

public:
    SortingVisualization(sf::RenderWindow& win);

    virtual void sort() = 0; // Pure virtual function to be overridden by derived classes

    virtual ~SortingVisualization(); // Virtual destructor to allow proper cleanup
};

class BubbleSortVisualization : public SortingVisualization {
public:
    BubbleSortVisualization(sf::RenderWindow& win);

    void sort() override;
};


