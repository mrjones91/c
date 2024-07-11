#include <stdio.h>
#include <stdbool.h>

struct square
{
	int sides;
	bool EvenSides;
};

int main()
{
	struct square rectangle = { 4, false };
	printf("Rectangle # of sides: %d \n", rectangle.sides);
	return 0;
}
