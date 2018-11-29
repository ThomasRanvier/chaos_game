#ifndef CHAOS_GAME_CHAOSGAME_H
#define CHAOS_GAME_CHAOSGAME_H

#include "config.hpp"
#include <iostream>
#include <random>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>

struct point {
    int x, y;
} typedef point;

class chaosGame {
private:
    std::vector<point> points;
    point currentPoint;
    int lastChoice, pointsCount;
    sf::RenderWindow * window;
    bool ** drawnArea;

    void noRestrictions();
    void updateCurrentPoint(point);
    void notSameVertexTwiceInARow();
    void drawCurrentPoint();
    void antiClockwise();
    bool isClockWise(int);
    void not2PlacesAway();
    bool isXPlacesAway(int, int);
    void notInDrawnArea();
    bool isInDrawnArea(int);
public:
    chaosGame(sf::RenderWindow *);
    chaosGame(std::vector<point>, sf::RenderWindow *);

    void play();
};


#endif