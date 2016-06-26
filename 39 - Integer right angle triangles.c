#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdbool.h>


//Pythogarean triads

int EucTriads[1400][4], peri[1400]= {0};

void main(){

	int k = 1;

	for (int i = 1; i < 1000; i++)
	{
		for (int j = 1; j < 1000; j++)
		{
			if (j>i)
			{
				int temp = i*i + j*j;
				int c = floor(sqrt(temp));

				if (c*c == temp){
					EucTriads[k][0] = i;
					EucTriads[k][1] = j;
					EucTriads[k][2] = c;
					EucTriads[k][3] = i+j+c;

					k++;
				}
			}
		}
	}

	for (int i = 1; i < k; i++)
	{
		int per = EucTriads[i][3];
		peri[per]++;
	}

	int pmax = 0,pindex;

	for (int i = 1; i < 1000; i++)
	{
		if (peri[i] > pmax)
		{
			pindex = i;
			pmax = peri[i];
		}
	}


	printf("%d %d", pmax, pindex);

	_getch();
}
