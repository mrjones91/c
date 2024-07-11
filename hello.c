#include <stdio.h>
#include "hello.h"

int main()
{
	printf("\nHello, World.\n");
	printf("Coding in C...\n");
	printf("LIKE\nA\nBOSS!\n\n");
	
	//char* result = myMethod();

	//printf("%s\n", result);
	getAge();
	//printf("%s\n", method1());
	
	char* str1 = method1();
	printf("str1: %s\n", str1);
	
	loops();
		
	return 0;
}

int getAge()
{
	int age;
	
	printf("\nayy\n");
	
	scanf("%d", &age);
	
	printf("\n%d\n", age);
	
	return 0;
}


char* method1()
{
	return "AYYYY!";
}

int loops()
{
	for (int i = 0; i < 5; i++) 
	{
		printf("%i\n", i);
	}
	return 0;
}
