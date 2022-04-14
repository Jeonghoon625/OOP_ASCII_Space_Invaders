#pragma once

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0);

	void ShowPosition();

	Point operator+ (const Point& ref);

	friend Point operator- (const Point& ref1, const Point& ref2); // 10.1

	Point& operator+= (const Point& ref); // 10.2
	Point& operator-= (const Point& ref); // 10.2

	friend bool operator== (const Point& ref1, const Point& ref2); // 10.3
	friend bool operator!= (const Point& ref1, const Point& ref2); // 10.3

	friend Point operator- (const Point& ref); // 10.4

	friend std::ostream& operator<< (std::ostream& os, const Point& pos); // 10.5
	friend std::istream& operator>> (std::istream& is, Point& pos); // 10.5
};

