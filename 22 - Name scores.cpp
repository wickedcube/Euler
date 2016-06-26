#include<iostream>
#include<math.h>
#include<conio.h>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std;

int compare(const void * a, const void * b) {
	const char *pa = *(const char**)a;
	const char *pb = *(const char**)b;
	return strcmp(pa, pb);
}

int main(){

	string arr[5163];
	ifstream myfile("p022_names.txt");

	long score = 0;
	 
	if (myfile.is_open())
	{

		for (int j = 0; j < 5163; j++){
			myfile >> arr[j];
		}
		
		myfile.close();
	}

	int stringLen = sizeof(arr) / sizeof(string);

	sort(arr, arr + stringLen);

	for (int i = 0; i < 5163; i++){

		int tscore = 0;
		char *cstr = new char[arr[i].length() + 1];
		strcpy(cstr, arr[i].c_str());

		for (int j = 0; j < strlen(cstr); j++){
			
			if (cstr[j] >= 65 && cstr[j] <= 90)
				tscore += (cstr[j] - 64);
		
		}

		score += tscore*(i+1);

		delete[] cstr;
	}

	cout << score;

	getchar();

	return 0;
}