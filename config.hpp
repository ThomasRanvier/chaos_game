
const int WIDTH = 700;
const int HEIGHT = 700;
const int NUMBER_OF_POINTS = 3;
const int STEP = 1000;
const int POINTS_LIMIT = 2000000;
const int PEN_RADIUS = 6;
const int ERASER_RADIUS = 10;

//MODE
//0: No restrictions
//1: Not same vertex twice in a row
//2: Anti-clockwise, not one place away from previous
//3: Not 2 places away
//4: Not in drawn area
const int MODE = 2;

//SHAPE, replaces NUMBER_OF_POINTS
//0: Random with NUMBER_OF_POINTS
//1: Triangle
//2: Rectangle
//3: Pentagon
const int SHAPE = 2;