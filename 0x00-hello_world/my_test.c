#include <stdio.h>

int main(void)
{
	char who[20];
	char when[20];
	char why[50];
	int how_much;
	
	printf("enter your name, when you sold it, why you sold it and how much you sold it. note that each should be seperated by space but 		but each answer should have no space i.e (i sold it because) is wrong but (isolditbecause) is right.");
	scanf("%s %s %s %d", &who, &when, &why, &how_much);
	printf("this phone was sold by %s %s because %s at %d.\n", who,when,why,how_much);
	return(0);
}
