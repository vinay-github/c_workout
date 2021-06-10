// Calculate and print the areas of circles
#include <stdio.h>

double circularArea(double radius);

int main()
{
	double radius = 6.0, area = 0;

	area = circularArea(radius);
	printf("Area of circle when radius %.1f is %.1f\n", radius, area);
	
	return 0;
}
