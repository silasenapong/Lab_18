#include <iostream>
#include <algorithm>
using namespace std;

struct Rect
{
	double x, y, w, h;
};

double overlap(Rect R1, Rect R2)
{
	double left, right;
	if (R1.x > R2.x)
	{
		left = R1.x;
	}
	else
	{
		left = R2.x;
	}

	if (R1.x + R1.w < R2.x + R2.w)
	{
		right = R1.x + R1.w;
	}
	else
	{
		right = R2.x + R2.w;
	}

	double overlap_width = right - left;

	double top, bottom;
	if (R1.y < R2.y)
	{
		top = R1.y;
	}
	else
	{
		top = R2.y;
	}

	if (R1.y - R1.h > R2.y - R2.h)
	{
		bottom = R1.y - R1.h;
	}
	else
	{
		bottom = R2.y - R2.h;
	}

	double overlap_height = top - bottom;

	if (overlap_width <= 0 || overlap_height <= 0)
	{
		return 0;
	}

	return overlap_width * overlap_height;
}

int main()
{

	Rect R1 = {1, 1, 5, 5};
	Rect R2 = {2, 2, 5, 5};
	cout << overlap(R1, R2) << endl;

	Rect R3 = {1, 1, 5, 5};
	Rect R4 = {7, 2, 3, 3};
	cout << overlap(R3, R4) << endl;

	Rect R5 = {-1, 2, 6.9, 9.6};
	Rect R6 = {0, 0, 1.2, 2.5};
	cout << overlap(R5, R6) << endl;

	Rect R7 = {0, 0, 1.2, 2.5};
	Rect R8 = {-1, 2, 6.9, 9.6};
	cout << overlap(R7, R8) << endl;

	return 0;
}