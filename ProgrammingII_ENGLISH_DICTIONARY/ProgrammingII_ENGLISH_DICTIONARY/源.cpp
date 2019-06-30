#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<malloc.h>
#include<limits.h>
using namespace std;
#define MAXSIZE 10000

typedef struct  {
	char state;   //# deleted * changed ^ normal
	int index;    // if changed search by it
	char* word;
	char* meaning;
	char* sentence;
}dictnode;
int index[26];

dictnode dict[MAXSIZE];
int search(const char* string, const int &count) {
	if ('a' <= string[0] && string[0] <= 'z') {
		int start = index[string[0] - 'a'];
		int end;
		if (string[0] == 'z')
			end = count;
		else
			end = index[string[0] - 'a' + 1];
		while (start <= end) {
			int i = (start + end) / 2;
			int res = strcmp(string, dict[i].word);
			if (res == 0)
				return i;
			else if (res < 0) {
				end = i - 1;
			}
			else {
				start = i + 1;
			}
		}
		return INT_MAX;
	}
	else {
		return INT_MAX;
	}

}
int main() {
	int count = 0;
	ifstream infile("dict.bat");
	if (!(infile.is_open()))
		cout << 1;
	while (!infile.eof()) {
		int tag;
		char buffer[1000];
		char* token;
		memset(buffer, 0, sizeof(buffer));
		char *p1 = NULL, *p2 = NULL, *p3 = NULL;
		infile.getline(buffer, sizeof(buffer));
		cout << buffer << endl;
		p1 = strtok_s(buffer, "_", &token);
		p2 = strtok_s(NULL, "_", &token);
		p3 = strtok_s(NULL, "_", &token);
		int l1 = strlen(p1);
		int l2 = strlen(p2);
		int l3 = strlen(p3);
		dict[count].word = new char[l1];
		dict[count].meaning = new char[l2];
		dict[count].sentence = new char[l3];
		dict[count].state = '^';
		strcpy_s(dict[count].word, 100, p1);
		strcpy_s(dict[count].meaning, 100, p2);
		strcpy_s(dict[count].sentence, 100, p3);
		count = count + 1;
	}
	index[0] = 0;
	int tag = 0;
	for (int i = 1; i != 26; i++) {
		for (int j = tag; j != count; j++) {
			if (dict[j].word[0] >= i + 'a') {
				tag = j;
				break;
			}
		}
		index[i] = tag;
	}
	while (1) {
		cout << "get me a string" << endl;
		char word[100];
		cin >> word;
		if (strcmp(word,"quit()") == 0) {
			break;
		}
		int res = search(word, count);
		if (res != INT_MAX) {
			cout << "word: " << dict[res].word << endl;
			cout << "meaning: " << dict[res].meaning << endl;
			cout << "sentence: " << dict[res].sentence << endl;
		}
		else {
			cout << "not found!" << endl;
		}
	}
	for (int i = 0; i != count; i++) {
		delete []dict[i].word;
		delete []dict[i].sentence;
		delete []dict[i].meaning;
	}
}