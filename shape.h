#pragma once
#include<string>

enum Shape_type {
	line,
	sqr,
	cube,
	circle,
	cylinder
};

class Shape
{
public:
	Shape() = default;
	Shape(int type);
	Shape(Shape_type type);
	int getType() { return type_; }
private:
	Shape_type type_;
};

class Line : public Shape
{
public:
	Line(int x1, int y1, int x2, int y2);
private:
	int x1_ = 0, y1_ = 0,
		x2_ = 0, y2_ = 0;
};

class Sqr : public Shape
{
public:
	Sqr(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
private:
	int x1_ = 0, y1_ = 0,
		x2_ = 0, y2_ = 0,
		x3_ = 0, y3_ = 0,
		x4_ = 0, y4_ = 0;
	double square_;
};

class Cube : public Shape
{
public:
	Cube(int x1, int y1, int z1, int x2, int y2, int z2,
		 int x3, int y3, int z3, int x4, int y4, int z4,
		 int x5, int y5, int z5, int x6, int y6, int z6, 
		 int x7, int y7, int z7, int x8, int y8, int z8);
private:
	int x1_ = 0, y1_ = 0, z1_ = 0, 
		x2_ = 0, y2_ = 0, z2_ = 0, 
		x3_ = 0, y3_ = 0, z3_ = 0, 
		x4_ = 0, y4_ = 0, z4_ = 0, 
		x5_ = 0, y5_ = 0, z5_ = 0, 
		x6_ = 0, y6_ = 0, z6_ = 0, 
		x7_ = 0, y7_ = 0, z7_ = 0, 
		x8_ = 0, y8_ = 0, z8_ = 0;
	double square_;
	double volume_;
};

class Circle : public Shape
{
public:
	Circle(int x1, int y1, double R);
private:
	int x1_ = 0, y1_ = 0;
	double radius_;
	double square_;
};

class Cylinder : public Shape
{
public:
	Cylinder(int x1, int y1, double R, double H);
private:
	int x1_ = 0, y1_ = 0;
	double radius_;
	double volume_;
	double height_;
	double square_;
};