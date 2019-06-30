//浮点数相加
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
void GetStanderd(int *num, const char *str) {
	int len_int = 0, len_dec = 0;
	int len = strlen(str);
	int i = 0;
	while (str[i] != '.'&&str[i] != '\0') {
		i++;
	}
	if (str[i] == '.') {
		len_int = i;
		len_dec = len-i-1;
	}
	else {
		len_int = i;
		len_dec = 0;
	}
	memset(num, 0, sizeof(num));
	for (i = 125; i > 125 - len_int; i--) {
		num[i] = str[-126 + len_int + i] - '0';
	}
	for (i = 126; i < 126 + len_dec; i++) {
		num[i] = str[i + len - len_dec - 126] - '0';
	}
}
bool AllZero(int *num, int i, int j) {
	for (int k = i; k != j; k++) {
		if (num[k] != 0)
			return false;
	}
	return true;
}
int main() {
	char str1[250];
	char str2[250];
	int num1[250], num2[250];
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	cin>>str1;
	cin>>str2;
	GetStanderd(num1,str1);
	GetStanderd(num2,str2);
	for (int i = 249; i != 0; i--) {
		num1[i] = num2[i] + num1[i];
		if (num1[i] > 9) {
			num1[i - 1] += num1[i] / 10;
			num1[i] = num1[i] % 10;
		}
	}
	if (AllZero(num1, 126, 250) == true&&AllZero(num1, 0, 126) == true) {
		printf("0");
	}
	else if (AllZero(num1, 126, 250) == true && AllZero(num1, 0, 126)==false) {
		int i = 0;
		while (num1[i] == 0) {
			i++;
		}
		for (int k = i; k != 126; k++)
			printf("%d", num1[k]);
	}
	else if (AllZero(num1, 126, 250) == false && AllZero(num1, 0, 126) == true) {
		printf("0.");
		int i = 249;
		while (num1[i] == 0) {
			i--;
		}
		for (int k = 126; k != i + 1; k++)
			printf("%d",num1[k]);
	}
	else {
		int i = 0;
		num1[0] = 0;
		while (num1[i] == 0) {
			i++;
		}
		for (int k = i; k != 126; k++)
			printf("%d", num1[k]);
		printf(".");
		i = 249;
		num1[249] = 0;
		while (num1[i] == 0) {
			i--;
		}
		for (int k = 126; k != i + 1; k++)
			printf("%d", num1[k]);
	}
	system("pause");
}