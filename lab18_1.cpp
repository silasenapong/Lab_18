#include <iostream>
#include <algorithm>
using namespace std;

struct Rect
{
	double x, y, w, h;
};

double overlap(Rect Rx, Rect Ry)
{

	double EdgeLeft_x = Rx.x, EdgeRight_x = Rx.x + Rx.w,
		   EdgeTop_x = Rx.y, EdgeBottom_x = Rx.y + Rx.h;

	double EdgeLeft_y = Ry.x, EdgeRight_y = Ry.x + Ry.w,
		   EdgeTop_y = Ry.y, EdgeBottom_y = Ry.y + Ry.h;

	double Left_inter = max(EdgeLeft_x, EdgeLeft_y),
		   Right_inter = min(EdgeRight_x, EdgeRight_y),
		   Top_inter = max(EdgeTop_x, EdgeTop_y),
		   Bottom_inter = min(EdgeBottom_x, EdgeBottom_y);

	double width = Right_inter - Left_inter,
		   height = Bottom_inter - Top_inter;

	if (width <= 0 || height <= 0)
	{
		return 0;
	}
	else
	{
		return width * height;
	}
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

	return 0;
}