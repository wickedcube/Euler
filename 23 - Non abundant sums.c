#include<stdio.h>
#include<conio.h>
#include <stdbool.h>


int i, j, anum[30000];

int bsearch(int a[], int n, int x){

	int xloc = -1, low, high, mid;

	low = 0; high = n - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == x)
		{
			xloc = mid;
			break;
		}
		else if (x < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (xloc == -1)
		return 0;
	else
		return 1;
}


int chkab(int num){

	int sum = 0;

	for (i = 1; i <= num / 2; i++)
	{
		if (num%i == 0)
			sum += i;
	}

	if (sum > num)
		return num;
	else
		return 0;
}


int main(){

	int k = 0, j, sum = 0;

	for (j = 1; j<28124; j++){
		if (chkab(j)>0)
		{
			anum[k] = j;
			k++;
		}
	}

	for (j = 1; j < 28124; j++){

		bool found = false;
		int l = 0;

		while (j > anum[l] && found == false && l < k)
		{
			if (bsearch(anum, k, j - anum[l]) == 1)
				found = true;

			l++;
		}

		if (!found)
			sum += j;

	}

	printf("%d", sum);


	_getch();
	return 0;
}
