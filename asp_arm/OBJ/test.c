#include <stdio.h>
#include <stdlib.h>

#define INT_IPM(ipm)	 (unsigned char)((ipm) + 31)	/* 内部表現に変換 */

volatile int x[8192];
int main(int argc, const char* argv)
{
	char *p;
	double double_x = 100.1111;
	float float_x = (float)double_x;
	float float_y = 1024;
	float_y = float_x - float_y;
	printf("sub float_x=%lf float_y=%lf\n", float_x, float_y);
	float_y = float_x * float_y;
	printf("mul float_x=%lf float_y=%lf\n", float_x, float_y);
	float_y = float_y / float_x;
	printf("div float_x=%lf float_y=%lf\n", float_x, float_y);
	int int_z = (int)float_y;
	printf("int_z=%d\n", int_z);

	int c = getchar();
	while (1) {
		p = malloc(1024 * 8);
		printf("addr=0x%p\n", p);
		int c = getchar();
	}

	return 0;
}
