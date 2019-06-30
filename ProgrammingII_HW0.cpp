#include<iostream>
using namespace std;
#define Max_Len 16
#define Max_Size 65535
bool JudgeCircle(unsigned int& a,unsigned int& b) {
	for (int i = 0; i != Max_Len; i++) {
		a = ((a << i) | (a >> (Max_Len - i)))&Max_Size;
		if (a == b)
			return true;
	}
	return false;
}
int main() {
	int numLength;
	cin >> numLength;
	unsigned int * Store1 = new unsigned int[numLength];
	unsigned int * Store2 = new unsigned int[numLength];
	for (int i = 0; i != numLength; i++) {
		cin>>Store1[i]>>Store2[i];
	}
	for (int i = 0; i != numLength; i++) {
		if (JudgeCircle(Store1[i], Store2[i]) == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	delete[]Store1;
	delete[]Store2;
}

