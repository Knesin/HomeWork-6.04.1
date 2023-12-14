#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>
//=========================================
//==============    Shape    ==============
//=========================================
Shape::Shape(int type): type_ (static_cast<Shape_type>(type))
{};

Shape::Shape(Shape_type type) : type_(type)
{};

//=========================================
//==============    Line     ==============
//=========================================
Line::Line(int x1, int y1, int x2, int y2) : Shape(line), x1_(x1), y1_(y1), x2_(x2), y2_(y2)
{};

Shape Line::shift(int m, int n) 
{
	x1_ += m; y1_ += n;
	x2_ += m; y2_ += n;
	return *this;
}
Shape Line::shift(int m, int n, int k)
{
	return shift(m, n);
};
Shape Line::scaleX(int a)
{
	x1_ *= a;
	x2_ *= a;
	return *this;
}

Shape Line::scaleY(int d)
{
	y1_ *= d;
	y2_ *= d;
	return *this;
}

Shape Line::scale(int s)
{
	x1_ /= s; y1_ /= s;
	x2_ /= s; y2_ /= s;
	return *this;
}
//=========================================
//==============     Sqr     ==============
//=========================================
Sqr::Sqr(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) :Shape(sqr), x1_(x1), y1_(y1), x2_(x2), y2_(y2),
x3_(x3), y3_(y3), x4_(x4), y4_(y4)
{
	square_ = abs(x1_ - x2_) * abs(y1_ - y2_);// считаем площадь фигуры
};

Shape Sqr::shift(int m, int n)
{
	x1_ += m; y1_ += n;
	x2_ += m; y2_ += n;
	x3_ += m; y3_ += n;
	x4_ += m; y4_ += n;
	return *this;
}
Shape Sqr::shift(int m, int n, int k)
{
	return shift(m, n);
};
Shape Sqr::scaleX(int a)
{
	x1_ *= a;
	x2_ *= a;
	x3_ *= a;
	x4_ *= a;
	return *this;
}

Shape Sqr::scaleY(int d)
{
	y1_ *= d;
	y2_ *= d;
	y3_ *= d;
	y4_ *= d;
	return *this;
}

Shape Sqr::scale(int s)
{
	x1_ /= s; y1_ /= s;
	x2_ /= s; y2_ /= s;
	x3_ /= s; y3_ /= s;
	x4_ /= s; y4_ /= s;
	return *this;
}
//=========================================
//==============     Cube    ==============
//=========================================
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
Shape Cube::shift(int m, int n, int k)
{
	x5_ += m; y5_ += n; z5_ += k;
	x6_ += m; y6_ += n; z6_ += k;
	x7_ += m; y7_ += n; z7_ += k;
	x8_ += m; y8_ += n; z8_ += k;
	x1_ += m; y1_ += n; z1_ += k;
	x2_ += m; y2_ += n; z2_ += k;
	x3_ += m; y3_ += n; z3_ += k;
	x4_ += m; y4_ += n; z4_ += k;
	return *this;
}
Shape Cube::scaleX(int a) {
	x1_ *= a;
	x2_ *= a;
	x3_ *= a;
	x4_ *= a;
	x5_ *= a;
	x6_ *= a;
	x7_ *= a;
	x8_ *= a;
	return *this;
}

Shape Cube::scaleY(int d) 
{
	y1_ *= d;
	y2_ *= d;
	y3_ *= d;
	y4_ *= d;
	y5_ *= d;
	y6_ *= d;
	y7_ *= d;
	y8_ *= d;
	return *this;
}

Shape Cube::scaleZ(int e)
{
	z1_ *= e;
	y2_ *= e;
	z3_ *= e;
	z4_ *= e;
	z5_ *= e;
	z6_ *= e;
	z7_ *= e;
	z8_ *= e;
	return *this;
}

Shape Cube::scale(int s)
{
	x1_ /= s; y1_ /= s; z1_ /= s;
	x2_ /= s; y2_ /= s; z2_ /= s;
	x3_ /= s; y3_ /= s; z3_ /= s;
	x4_ /= s; y4_ /= s; z4_ /= s;
	x5_ /= s; y5_ /= s; z5_ /= s;
	x6_ /= s; y6_ /= s; z6_ /= s;
	x7_ /= s; y7_ /= s; z7_ /= s;
	x8_ /= s; y8_ /= s; z8_ /= s;
	return *this;
}

//=========================================
//=============     Circle    =============
//=========================================
Circle::Circle(int x1, int y1, double R) : Shape(circle), x1_(x1), y1_(y1), radius_(R)
{
	square_ = M_PI * radius_ * radius_;
};

//=========================================
//============     Cylinder    ============
//=========================================
Cylinder::Cylinder(int x1, int y1, double R, double H) : Shape(cylinder), x1_(x1), y1_(y1), radius_(R), height_(H)
{
	square_ = M_PI * radius_ * radius_ + 2 * radius_ * height_;// считаем площадь фигуры		
	volume_ = M_PI * radius_ * radius_ * height_;// считаем объем фигуры
}
