#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdbool.h>

void main(){

	int product = 1;

	for (int i = 10; i < 100; i++){
		for (int j = 10; j < 100; j++){
		
			//edge case 65/26 use float for result not int

			float res = (float)j / i;
			int rem = j % i;

			int a = (j - j % 10) / 10;
			int b = j % 10;
			int c = (i - i % 10) / 10;
			int d = i % 10;

			if (i % 10 != 0 && j % 10 != 0 && j>i && ((res == (float)a / c && b == d) || (res == (float)a / d && b == c) || (res == (float)b / c && a == d) || (res == (float)b / d && a == c)))
			{
				printf("%d %d %f \n",i,j, res);
				product = product*res;
			}
		
		}
	}


	printf("%d",product);
	
	_getch();
}