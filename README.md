# chaos game

This is an implementation of the chaos game, it is a method to create fractals.

The rules are simple, a shape composed of numerous vertices is selected.
A point is chosen among the vertices of the shape.
At each iteration a vertex is selected and the point becomes the middle of the line between the point and the vertex, the process repeats itself until the maximum number of drawn points is reached.

Several restrictions can be applied to the game.

Obtained result using a triangle and no restrictions:

<img src="./screenshots/01.png" width="350">

Not selecting the same vertex twice in a row using, a square:

<img src="./screenshots/12.png" width="350">

Not selecting the same vertex twice in a row using, a pentagon:

<img src="./screenshots/13.png" width="350">

Anti-clockwise, current vertex cannot be one place away from the previous one, using a square:

<img src="./screenshots/22.png" width="350">

Anti-clockwise, current vertex cannot be one place away from the previous one, using a pentagon:

<img src="./screenshots/23.png" width="350">

The current vertex cannot be two place away from the previous one in either directions, using a rectangle:

<img src="./screenshots/32.png" width="350">

When we prevent the point from landing on a particular region of the square, the shape will be reproduced as a fractal in other places of the square.
Obtained result in a square with the restricted zone appearing in red.

<img src="./screenshots/42.png" width="350">
