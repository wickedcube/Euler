#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdbool.h>

bool bsearch(int a[], int n, int x){

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
		return false;
	else
		return true;
}


bool IsPandigital(long number){

	int arr[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },amax=0,amin;
	while (number > 0){

		int rem = number % 10;

		arr[rem]--;

		number = number / 10;
	}

	for (int i = 1; i < 10; i++){

		if (arr[i] < 0)
			return false;

		if (i == 1)
			amin = arr[i];

		if (arr[i]>amax)
			amax = arr[i];
	}

	if (amax == 0 && amin == 0)
		return true;
	else
		return false;
}

int cmpfunc(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

void main(){

	long res = 0, sum = 0, panarr[12] = {0}, k = 0;
	long long chkres;
	int digres, digi, digj;

	for (long i = 2; i < 9999; i++){
		for (long j = 2; j < 9999; j++){

			res = i*j;

			digres = (int)log10(res) + 1;
			digi = (int)log10(i) + 1;
			digj = (int)log10(j) + 1;

			int digits = digres + digi + digj;

			chkres = j * (int)pow(10, digres + digi) + i * (int)pow(10, digres) + res;


			if (IsPandigital(chkres) && !bsearch(panarr, k, res) && chkres > 0 && digits < 10)
			{
				printf("%d \n", chkres);
				panarr[k] = res;
				k++;
				qsort(panarr, k, sizeof(int), cmpfunc);
				sum += res;
			}

		}
	}

	printf("%d \t", sum);
	_getch();
}