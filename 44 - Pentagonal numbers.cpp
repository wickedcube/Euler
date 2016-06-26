#include<iostream>
#include<conio.h>
#include<math.h>


using namespace std;

void main(){

	int count = 0, dmin;

	for (int i = 1; i < 100000; i++){
		for (int j = 1; j < 100000; j++){
			
			if (j>i){

				long long  pj = (j)*(3 * j -1) / 2;
				long long  pi = (i)*(3 * i -1) / 2;
			
				long long diff = pj - pi;
				long long sum = pj + pi;

				diff = 24 * diff + 1;
				sum = 24 * sum + 1;

				long sqrootd = sqrt(diff);
				long sqroots = sqrt(sum);

				if (sqrootd*sqrootd == diff && sqrootd % 6 == 5 && sqroots*sqroots == sum && sqroots % 6 == 5){
				
					if (count == 0){
						dmin = pj - pi;
						cout <<" "<< pj << " " << pi<< " ";
					}
						
					else if (pj - pi < dmin)
					{
						dmin = pj - pi;
						cout <<" "<< pj <<" " << pi<<" ";
					}

					count++;
				}			
			}
		}
	}

	cout << dmin;

	getchar();
}