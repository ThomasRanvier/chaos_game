#include <iostream>
#include "chaosGame.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "sfml_chaos_game");

    if (SHAPE == 0) {
        chaosGame game(&window);
        game.play();
    } else {
        std::vector<point> points;
        point pt;
        switch (SHAPE) {
            case 1:
                pt.x = WIDTH / 2;
                pt.y = HEIGHT / 10;
                points.push_back(pt);
                pt.x = WIDTH / 10;
                pt.y = (9 * HEIGHT) / 10;
                points.push_back(pt);
                pt.x = (9 * WIDTH) / 10;
                pt.y = (9 * HEIGHT) / 10;
                points.push_back(pt);
                break;
            case 2:
                pt.x = WIDTH / 10;
                pt.y = HEIGHT / 10;
                points.push_back(pt);
                pt.x = (9 * WIDTH) / 10;
                pt.y = HEIGHT / 10;
                points.push_back(pt);
                pt.x = (9 * WIDTH) / 10;
                pt.y = (9 * HEIGHT) / 10;
                points.push_back(pt);
                pt.x = WIDTH / 10;
                pt.y = (9 * HEIGHT) / 10;
                points.push_back(pt);
                break;
            case 3:
                pt.x = WIDTH / 2;
                pt.y = HEIGHT / 10;
                points.push_back(pt);
                pt.x = (9 * WIDTH) / 10;
                pt.y = (4 * HEIGHT) / 10;
                points.push_back(pt);
                pt.x = (7.5 * WIDTH) / 10;
                pt.y = (9 * HEIGHT) / 10;
                points.push_back(pt);
                pt.x = (2.5 * WIDTH) / 10;
                pt.y = (9 * HEIGHT) / 10;
                points.push_back(pt);
                pt.x = WIDTH / 10;
                pt.y = (4 * HEIGHT) / 10;
                points.push_back(pt);
                break;
            default:
                return 0;
        }
        chaosGame game(points, &window);
        game.play();
    }

    return 0;
}