#include<iostream>
#include<math.h>
#include<conio.h>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std;

int main(){

	string arr[2500];
	ifstream myfile("p022_names.txt");

	long score = 0,countnum = 0;

	if (myfile.is_open())
	{

		for (int j = 0; j < 2500; j++){
			myfile >> arr[j];
		}

		myfile.close();
	}

	for (int i = 0; i < 2500; i++){

		int tscore = 0;
		char *cstr = new char[arr[i].length() + 1];
		strcpy(cstr, arr[i].c_str());

		for (int j = 0; j < strlen(cstr); j++){

			if (cstr[j] >= 65 && cstr[j] <= 90)
				tscore += (cstr[j] - 64);

		}

		unsigned long long trianglenumber = 8 * tscore + 1;

		long long sqrtt = sqrt(trianglenumber);

		if (sqrtt*sqrtt == trianglenumber && sqrtt % 2 == 1 && tscore > 0)
			countnum++;

		delete[] cstr;
	}

	cout << countnum;

	getchar();

	return 0;
}