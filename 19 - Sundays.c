#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

//Remainder arrays for normal and leap years
int mr[12] = { 3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3 }, lymr[12] = { 3, 1, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3 };

void main(){

	int count = 0,startday = 1;;

	for (int i = 1901; i < 2000; i++){

		//add remainder of every month to get 1st day of next month.
		if (i % 4 == 0){
			for (int j = 0; j < 12; j++){

				if ((startday + lymr[j]) % 7 == 0)
				{
					count++;
				}
				startday += lymr[j];
			}
		}
		else
		{
			for (int j = 0; j < 12; j++){

				if ((startday + mr[j]) % 7 == 0)
				{
					count++;
				}
				startday += mr[j];
			}
		}

	}

	printf("%d",count);

	_getch();
}