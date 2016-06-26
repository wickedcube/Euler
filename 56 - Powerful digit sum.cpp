#include<iostream>
#include<math.h>

using namespace std;

int n, temp, m, x, y;

int calcpow(int n,int p){

	int pow[200], loopvar = p,fsum = 0;

	temp = 0;
	m = 1;

	pow[0] = n;
	y = n;

	if (n > 9){
		m = 2;
		pow[0] = n % 10;
		pow[1] = n / 10;
	}

	while (loopvar > 1){

		for (int i = 0; i < m; i++)
		{
			x = pow[i] * (y) + temp;
			pow[i] = x % 10;
			temp = x / 10;
		}

		while (temp > 0)
		{
			pow[m] = temp % 10;
			temp = temp / 10;
			m = m + 1;
		}
		
		loopvar--;
	}

	for (int j = m; j > 0; j--)
	{
		fsum += pow[j - 1];
	}

	return fsum;

}

int main(){

	int dmax = 0,dn,dp;

	for (int i = 1; i < 100; i++){

		for (int j = 1; j < 100; j++){

			int sod = calcpow(i,j);

			if (sod>dmax){
				dmax = sod;
				dn = i;
				dp = j;
			}
		}

	}

	cout << dmax <<" "<<dn<<" "<<dp;

	getchar();

	return 0;
}