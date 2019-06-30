#include<iostream>
#include<stdio.h>
int NUM[9][9] = { { 1,1,0,1,0,0,0,0,0 } ,{ 1,1,1,0,1,0,0,0,0 }, { 0,1,1,0,0,1,0,0,0 }, { 1,0,0,1,1,0,1,0,0 }, {1,0,1,0,1,0,1,0,1},
{ 0,0,1,0,1,1,0,0,1 },
{ 0,0,0,1,0,0,1,1,0 }, { 0,0,0,0,1,0,1,1,1 }, { 0,0,0,0,0,1,0,1,1 } };
int state[9];
int Operate[9];
bool Right() { //即operate存储的是从1-9的操作次数
	int temp[9]; //记录A-I的总操作数，算初始态
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i != 9; i++) {
		for (int j = 0; j != 9; j++) {
			temp[i] += NUM[i][j] * Operate[j];
		}
		temp[i] = temp[i] + state[i]; //原有的状态
	}
	for (int i = 0; i != 9; i++) {
		if (temp[i] % 4 != 0)
			return false;
	}
	return true;
}
int main() {
	//read in state;
	for (int i = 0; i != 9; i++) {
		scanf_s("%d", &state[i]);
	}
	for (int k = 0; k != 28; k++)
		for(int a = 0; a < 4; a++)
			for(int b = 0; b < 4&&b<= k - a; b++)
				for(int c = 0; c < 4&&c<=k - a -b; c++)
					for(int d = 0; d < 4&&d<=k-a-b-c; d++)
						for(int e = 0; e < 4&&e<=k-a-b-c-d; e++)
							for(int f = 0; f < 4&&f<=k-a-b-c-d-e;f++)
								for(int g = 0; g < 4&&g<=k-a-b-c-d-e-f;g++)
									for(int h = 0; h < 4&&h<=k-a-b-c-d-e-f-g; h++) {
										int i = k - a - b - c - d - e - f - g - h;
											    Operate[0] = a;
												Operate[1] = b;
												Operate[2] = c;
												Operate[3] = d;
												Operate[4] = e;
												Operate[5] = f;
												Operate[6] = g;
												Operate[7] = h;
												Operate[8] = i;
												if (Right() == true) {
													for (int i = 0; i != 9; i++) {
														for (int j = 0; j != Operate[i]; j++) {
															printf_s("%d ", i + 1);
														}
													}
													system("pause");
	                                                return 0;
												}
										}
	
}