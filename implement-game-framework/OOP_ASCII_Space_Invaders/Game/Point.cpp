#include "stdafx.h"
#include "Point.h"

Point::Point(int x, int y) : xpos(x), ypos(y)
{  }

void Point::ShowPosition()
{
	std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
}

Point Point::operator+ (const Point& ref)    //operator+라는 이름의 함수
{
	const Point pos(xpos + ref.xpos, ypos + ref.ypos);
	return pos;
}

Point operator- (const Point& ref1, const Point& ref2) // 10.1
{
	Point pos(ref1.xpos - ref2.xpos, ref1.ypos - ref2.ypos);
	return pos;
}

Point& Point::operator+= (const Point& ref) // 10.2
{
	xpos += ref.xpos;
	ypos += ref.ypos;

	return *this;
}

Point& Point::operator-= (const Point& ref) // 10.2
{
	xpos -= ref.xpos;
	ypos -= ref.ypos;

	return *this;
}

bool operator== (const Point& ref1, const Point& ref2) // 10.3
{
	return ((ref1.xpos == ref2.xpos) && (ref1.ypos == ref2.ypos));
}

bool operator!= (const Point& ref1, const Point& ref2) // 10.3
{
	return !(ref1 == ref2);
}

Point operator- (const Point& ref) // 10.4
{
	Point point(-ref.xpos, -ref.ypos);

	return point;
}

std::ostream& operator<< (std::ostream& os, const Point& pos) // 10.5
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << std::endl;
	return os;
}

std::istream& operator>> (std::istream& is, Point& pos) // 10.5
{
	is >> pos.xpos >> pos.ypos;
	return is;
}

