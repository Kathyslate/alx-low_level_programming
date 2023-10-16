#include <stdio.h>

int main(void)
{
	char who[20];
	char when[20];
	char why[50];
	int how_much;
	
	scanf("%s %s %s %d", &who, &when, &why, &how_much);
	printf("this phone was sold by %s %s because %s at %d.\n", who,when,why,how_much);
	return(0);
}
