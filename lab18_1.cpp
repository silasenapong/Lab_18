#include <iostream>
#include <algorithm>
using namespace std;

struct Rect
{
	double x, y, w, h;
};

double overlap(Rect R1, Rect R2)
{

	double EdgeLeft_1 = R1.x, EdgeRight_1 = R1.x + R1.w,
		   EdgeTop_1 = R1.y, EdgeBottom_1 = R1.y + R1.h;

	double EdgeLeft_2 = R2.x, EdgeRight_2 = R2.x + R2.w,
		   EdgeTop_2 = R2.y, EdgeBottom_2 = R2.y + R2.h;

	double Left_inter, Right_inter, Top_inter, Bottom_inter, width, height;

	Left_inter = max(EdgeLeft_1, EdgeLeft_2);
	Right_inter = min(EdgeRight_1, EdgeRight_2);
	Top_inter = max(EdgeTop_1, EdgeTop_2);
	Bottom_inter = min(EdgeBottom_1, EdgeBottom_2);

	if (EdgeLeft_1 < EdgeLeft_2 && EdgeRight_1 > EdgeRight_2 &&
		EdgeTop_1 > EdgeTop_2 && EdgeBottom_1 > EdgeBottom_2)
	{
		width = R2.w;
		height = R2.h;
	}
	else if (EdgeLeft_1 > EdgeLeft_2 && EdgeRight_1 < EdgeRight_2 &&
			 EdgeTop_1 < EdgeTop_2 && EdgeBottom_1 < EdgeBottom_2)
	{
		width = R1.w;
		height = R1.h;
	}
	else
	{
		width = Right_inter - Left_inter;
		height = Bottom_inter - Top_inter;
	}

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

	Rect R7 = {0, 0, 1.2, 2.5};
	Rect R8 = {-1, 2, 6.9, 9.6};
	cout << overlap(R7, R8) << endl;

	return 0;
}