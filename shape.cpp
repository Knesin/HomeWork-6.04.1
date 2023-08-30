#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>
Shape::Shape(int _type, int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8)
{
	type = _type;
	// заполн¤ем координаты фигуры
	switch (type)
	{
	case line: 
		x1 = _x1; y1 = _y1;
		x2 = _x2; y2 = _y2;
		square = 0;// считаем площадь фигуры
		volume = 0;// считаем объем фигуры
		break;
	case sqr:
		x1 = _x1; y1 = _y1;
		x2 = _x2; y2 = _y2;
		x3 = _x3; y3 = _y3;
		x4 = _x4; y4 = _y4;
		int a = abs(x1 - x2);
		int b = abs(y1 - y2);
		square = a * b;// считаем площадь фигуры
		volume = 0;// считаем объем фигуры
		break;
	case cube:
		x1 = _x1; y1 = _y1; z1 = _z1;
		x2 = _x2; y2 = _y2; z2 = _z2;
		x3 = _x3; y3 = _y3; z3 = _z3;
		x4 = _x4; y4 = _y4; z4 = _z4;
		x5 = _x5; y5 = _y5; z5 = _z5;
		x6 = _x6; y6 = _y6; z6 = _z6; 
		x7 = _x7; y7 = _y7; z7 = _z7;
		x8 = _x8; y8 = _y8; z8 = _z8;		
		int c = abs(z1 - z2);
		square = 2 * a * b + 2 * a * c + 2 * b * c;// считаем площадь фигуры		
		volume = a * b * c;// считаем объем фигуры
		break;
	default:
		break;
	}
}

Shape::Shape(int type, int _x1, int _y1, double R, double H)
{
	x1 = _x1; y1 = _y1;
	radius = R;
	// заполн¤ем координаты фигуры
	switch (type)
	{
	case circle:
		square = M_PI * R * R;// считаем площадь фигуры		
		volume = 0;// считаем объем фигуры
		break;
	case cylinder:
		height = H;		
		square = M_PI * R * R + 2 * R * height;// считаем площадь фигуры		
		volume = M_PI * R * R * height;// считаем объем фигуры
		break;
	default:
		break;
	}
}
