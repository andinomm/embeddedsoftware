#define BYTESIZE 8

#include<stdio.h>
#include<conio.h>

void printBits(int pixelMatrix[], int n)
{
	int mask;
	for (int i = 0; i < n; i++)
	{
		mask = 1;
		for (int j = 0; j < BYTESIZE; j++) {

			if (pixelMatrix[i] & mask)
				printf("%c", '#');
			else printf("%c", '.');

			mask <<= 1;
		}
		printf("\n");
	}
}

int main()
{
	int A[] = { 0x00,0x18,0x24,0x24,0x7E,0x42,0x42,0x00 };
	int B[] = { 0x00, 0x3f, 0x41, 0x61, 0x3f, 0x61, 0x41, 0x3f };

	printBits(A, sizeof(A) / sizeof(int));
	printf("\n");
	printBits(B, sizeof(B) / sizeof(int));

	_getch();
	return 0;
}