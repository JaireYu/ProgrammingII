#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;
typedef struct DIR {
	string name;
	vector<string> file;
	vector<DIR> dir;
}DIR;
vector<vector<string>> sys;
DIR storage(const vector<string>& sys, int& index);
void print(DIR temp, int depth);
void print_space(int depth);
int main() {
	while (1) {
		string str;
		getline(cin, str);
		if (str == "#")
			break;
		else {
			vector<string> part;
			while (1) {
				if (str == "*")
					break;
				else {
					part.push_back(str);
				}
				getline(cin, str);
			}
			sys.push_back(part);
		}
	}
	for (int i = 0; i != sys.size(); i++) {
		printf("DATA SET %d:\n", i+1);
		DIR temp;
		int num = 0;
		temp = storage(sys[i], num);
		print(temp,0);
		printf("\n");
	}
	system("pause");
	return 0;
}

DIR storage(const vector<string>& sys, int& index){
	DIR temp;
	int size = sys.size();
	if (index == 0) {
		temp.name = "ROOT";
	}
	else {
		temp.name = sys[index];
		index++;
	}
	while(index != size) {
		if (sys[index][0] == ']') {
			index ++;	
			return temp;
		}
		else if (sys[index][0] == 'f') {
			int i = 0;
			for (i = 0; i != temp.file.size(); i++) {
				if (sys[index] < temp.file[i]) {
					break;
				}
			}
			temp.file.insert(temp.file.begin() + i, sys[index]);
			index++;
		}
		else {
			temp.dir.push_back(storage(sys, index));
		}
	}
	return temp;
}

void print(DIR temp, int depth) {
	print_space(depth);
	cout << temp.name << endl;
	for (int i = 0; i != temp.dir.size(); i++) {
		print(temp.dir[i], depth + 1);
	}
	for (int i = 0; i != temp.file.size(); i++) {
		print_space(depth);
		cout << temp.file[i] << endl;
	}
}

void print_space(int depth){
	for (int i = 0; i != depth; i++) {
		printf("|     ");
	}
}
