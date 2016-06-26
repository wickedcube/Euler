#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdbool.h>


int orgn;

int CountSol(int coins[],int size,int totval){

	if (totval == 0)
		return 1;

	if (totval < 0)
		return 0;

	if (size <= 0 && totval > 0)
		return 0;

	return CountSol(coins, size - 1, totval) + CountSol(coins, size, totval - coins[size - 1]);

}


void main(){

	int arr[8] = { 1, 2, 5, 10, 20, 50, 100, 200},val = 200;

	printf("%d", CountSol(arr,8,val));

	_getch();
}