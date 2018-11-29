#include "chaosGame.h"

chaosGame::chaosGame(sf::RenderWindow * window) : window(window) {
    srand(time(NULL));
    for (int i(0); i < NUMBER_OF_POINTS; i++) {
        point pt;
        pt.x = rand() % WIDTH;
        pt.y = rand() % HEIGHT;
        points.push_back(pt);
        sf::RectangleShape cell(sf::Vector2f(1, 1));
        cell.setPosition(pt.x, pt.y);
        this->window->draw(cell);
    }
    this->window->display();
    this->currentPoint = this->points[0];
    this->lastChoice = 0;
    this->pointsCount = 0;
}

chaosGame::chaosGame(std::vector<point> points, sf::RenderWindow * window) : window(window), points(points){
    srand(time(NULL));
    for (int i(0); i < this->points.size(); i++) {
        sf::RectangleShape cell(sf::Vector2f(1, 1));
        cell.setPosition(this->points[i].x, this->points[i].y);
        this->window->draw(cell);
    }
    this->window->display();
    this->currentPoint = this->points[0];
    this->lastChoice = 0;
    this->pointsCount = 0;
}

void chaosGame::play() {
    if (MODE == 4) {
        this->drawnArea = new bool *[WIDTH];
        for (int i(0); i < WIDTH; i++)
            this->drawnArea[i] = new bool [HEIGHT]();
    }
    bool go(false);

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        if (this->pointsCount < POINTS_LIMIT) {
            switch (MODE) {
                case 0:
                    for (int i(0); i < STEP; i++)
                        this->noRestrictions();
                    this->window->display();
                    this->pointsCount += STEP;
                    break;
                case 1:
                    for (int i(0); i < STEP; i++)
                        this->notSameVertexTwiceInARow();
                    this->window->display();
                    this->pointsCount += STEP;
                    break;
                case 2:
                    for (int i(0); i < STEP; i++)
                        this->antiClockwise();
                    this->window->display();
                    this->pointsCount += STEP;
                    break;
                case 3:
                    for (int i(0); i < STEP; i++)
                        this->not2PlacesAway();
                    this->window->display();
                    this->pointsCount += STEP;
                    break;
                case 4:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                        go = true;

                    if (go) {
                        for (int i(0); i < STEP; i++)
                            this->notInDrawnArea();
                        this->window->display();
                        this->pointsCount += STEP;
                    } else {
                        sf::Vector2i pos = sf::Mouse::getPosition(* window);
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                            for (int i(-PEN_RADIUS); i < PEN_RADIUS; i++) {
                                for (int j(-PEN_RADIUS); j < PEN_RADIUS; j++) {
                                    if (pos.x + i >= 0 && pos.x + i < WIDTH && pos.y + j >= 0 && pos.y + j < HEIGHT) {
                                        this->drawnArea[pos.x + i][pos.y + j] = true;
                                        sf::RectangleShape cell(sf::Vector2f(1, 1));
                                        cell.setPosition(pos.x + i, pos.y + j);
                                        cell.setFillColor(sf::Color::Red);
                                        this->window->draw(cell);
                                    }
                                }
                            }
                        } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                            for (int i(-ERASER_RADIUS); i < ERASER_RADIUS; i++) {
                                for (int j(-ERASER_RADIUS); j < ERASER_RADIUS; j++) {
                                    if (pos.x + i >= 0 && pos.x + i < WIDTH && pos.y + j >= 0 && pos.y + j < HEIGHT) {
                                        this->drawnArea[pos.x + i][pos.y + j] = false;
                                        sf::RectangleShape cell(sf::Vector2f(1, 1));
                                        cell.setPosition(pos.x + i, pos.y + j);
                                        cell.setFillColor(sf::Color::Black);
                                        this->window->draw(cell);
                                    }
                                }
                            }
                        }
                        this->window->display();
                    }
                    break;
                default:
                    this->window->close();
            }
        }
    }
}

void chaosGame::noRestrictions() {
    int choice(rand() % this->points.size());
    this->lastChoice = choice;
    updateCurrentPoint(this->points[choice]);
    drawCurrentPoint();
}

void chaosGame::notSameVertexTwiceInARow() {
    int choice(rand() % this->points.size());
    while (this->points[this->lastChoice].x == this->points[choice].x &&
           this->points[this->lastChoice].y == this->points[choice].y)
        choice = rand() % this->points.size();
    this->lastChoice = choice;
    updateCurrentPoint(this->points[choice]);
    drawCurrentPoint();
}

void chaosGame::updateCurrentPoint(point newPoint) {
    this->currentPoint.x = round(float(newPoint.x + this->currentPoint.x) / 2.0);
    this->currentPoint.y = round(float(newPoint.y + this->currentPoint.y) / 2.0);
}

void chaosGame::drawCurrentPoint() {
    sf::RectangleShape cell(sf::Vector2f(1, 1));
    cell.setPosition(this->currentPoint.x, this->currentPoint.y);
    if (this->points.size() <= 5) {
        switch (this->lastChoice) {
            case 0:
                cell.setFillColor(sf::Color::Blue);
                break;
            case 1:
                cell.setFillColor(sf::Color::White);
                break;
            case 2:
                cell.setFillColor(sf::Color::Green);
                break;
            case 3:
                cell.setFillColor(sf::Color::Magenta);
                break;
            case 4:
                cell.setFillColor(sf::Color::Yellow);
                break;
        }
    }
    this->window->draw(cell);
}

void chaosGame::antiClockwise() {
    int choice(rand() % this->points.size());
    while (isClockWise(choice))
        choice = rand() % this->points.size();
    this->lastChoice = choice;
    updateCurrentPoint(this->points[choice]);
    drawCurrentPoint();
}

bool chaosGame::isClockWise(int choice) {
    return this->lastChoice == (choice + 1) % this->points.size();
}

void chaosGame::not2PlacesAway() {
    int choice(rand() % this->points.size());
    while (isXPlacesAway(choice, 2))
        choice = rand() % this->points.size();
    this->lastChoice = choice;
    updateCurrentPoint(this->points[choice]);
    drawCurrentPoint();
}

bool chaosGame::isXPlacesAway(int choice, int x) {
    return this->lastChoice == (choice + x) % this->points.size() ||
           this->lastChoice == (choice - x) % this->points.size();
}

void chaosGame::notInDrawnArea() {
    int choice(rand() % this->points.size());
    while (isInDrawnArea(choice))
        choice = rand() % this->points.size();
    this->lastChoice = choice;
    updateCurrentPoint(this->points[choice]);
    drawCurrentPoint();
}

bool chaosGame::isInDrawnArea(int choice) {
    int midX = round(float(this->points[choice].x + this->currentPoint.x) / 2.0);
    int midY = round(float(this->points[choice].y + this->currentPoint.y) / 2.0);
    return this->drawnArea[midX][midY];
}
