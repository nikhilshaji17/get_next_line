#include <stdio.h>

void f()
{
	static int calls = 0;
	calls += 1;
	printf("Value of calls: %d\n", calls);
}

int main()
{
	f();
	f();
}