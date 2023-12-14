#include <iostream>
#include "shape.h"

int main() {
	Line line(0, 0, 2, 2);
	Sqr sqr(0, 0, 2, 2, 1, 1, 3, 3);
	line.scaleX(210);
	std::cout << line.getType() << std::endl;
	std::cout << sqr.getType();
	return 0;
}