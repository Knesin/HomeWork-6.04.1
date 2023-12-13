#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>

Shape::Shape(int type): type_ (static_cast<Shape_type>(type))
{};

Shape::Shape(Shape_type type) : type_(type)
{};

Line::Line(int x1, int y1, int x2, int y2) : Shape(line), x1_(x1), y1_(y1), x2_(x2), y2_(y2)
{}

Sqr::Sqr(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) :Shape(sqr), x1_(x1), y1_(y1), x2_(x2), y2_(y2),
x3_(x3), y3_(y3), x4_(x4), y4_(y4)
{
	square_ = abs(x1_ - x2_) * abs(y1_ - y2_);// считаем площадь фигуры
};

Cube::Cube(	int x1, int y1, int z1, int x2, int y2, int z2,
			int x3, int y3, int z3, int x4, int y4, int z4,
			int x5, int y5, int z5, int x6, int y6, int z6,
			int x7, int y7, int z7, int x8, int y8, int z8) : Shape(cube),
	x1_(x1), y1_(y1), z1_(z1), x2_(x2), y2_(y2), z2_(z2),
	x3_(x3), y3_(y3), z3_(z3), x4_(x4), y4_(y4), z4_(z4),
	x5_(x5), y5_(y5), z5_(z5), x6_(x6), y6_(y6), z6_(z6),
	x7_(x7), y7_(y7), z7_(z7), x8_(x8), y8_(y8), z8_(z8)
{
	int a = abs(x1_ - x2_);
	int b = abs(y1_ - y2_);
	int c = abs(z1_ - z2_);
	square_ = 2 * a * b + 2 * a * c + 2 * b * c;
	volume_ = a * b * c;
};

Circle::Circle(int x1, int y1, double R) : Shape(circle), x1_(x1), y1_(y1), radius_(R)
{
	square_ = M_PI * radius_ * radius_;
};

Cylinder::Cylinder(int x1, int y1, double R, double H) : Shape(cylinder), x1_(x1), y1_(y1), radius_(R), height_(H)
{
	square_ = M_PI * radius_ * radius_ + 2 * radius_ * height_;// считаем площадь фигуры		
	volume_ = M_PI * radius_ * radius_ * height_;// считаем объем фигуры
}
