#include "function.h"

void func();
void tricked()
{
    printf("hmm \n");
}

int main()
{
    tricked();
	func();
	printf("made my FIRST Makefile! \n");
	return 0;
}
