#include <stdio.h>

static double version = 1.0;

void displayVersion();

int main()
{
	displayVersion();
	version = version + .1;

	return 0;
}

void displayVersion()
{
	printf("Current version is %.1f\n", version);
	return;
}