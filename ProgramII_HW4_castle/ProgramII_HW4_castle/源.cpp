#include<iostream>
#include<vector>
using namespace std;
struct info {
	vector<int> open;
	int visit;
};
vector<vector<info>> cainfo;
vector<int> num_to_open(int num) {
	vector<int> open;
	int l = 8;
	for (int i = 0; i != 4; i++) {
		if (num / l)
			open.push_back(0);//ÓÐÇ½±ê×¢Îª0
		else
			open.push_back(1);
		num = num % l;
		l = l / 2;
	}
	return open;
}
void DFS(int i, int j, int& room) {
	cainfo[i][j].visit = 1;
	room = room + 1;
	for (int k = 0; k != 4; k++) {
		if (cainfo[i][j].open[k] == 1) {
			switch (k) {
				case 0 : { //south
					if (cainfo[i + 1][j].visit == 0)
						DFS(i + 1, j, room);
				}break;
				case 1: { //east
					if (cainfo[i][j + 1].visit == 0)
						DFS(i, j + 1, room);
				}break;
				case 2: { //north
					if (cainfo[i-1][j].visit == 0)
						DFS(i-1, j, room);
				}break;
				default: { //west
					if (cainfo[i][j - 1].visit == 0)
						DFS(i, j - 1, room);
				}
			}
		}
	}
}
int main() {
	vector<vector<int>> castle;
	int row, column;
	cin >> column;
	cin >> row;
	for (int i = 0; i != column; i++) {
		vector<int> temp;
		for (int j = 0; j != row; j++) {
			int tempo;
			cin >> tempo;
			temp.push_back(tempo);
		}
		castle.push_back(temp);
	}
	for (int i = 0; i != column; i++) {
		vector<info> temp1;
		for (int j = 0; j != row; j++) {
			info temp;
			temp.visit = 0;
			temp.open = num_to_open(castle[i][j]);
			temp1.push_back(temp);
		}
		cainfo.push_back(temp1);
	}
	int maxroom = 0;
	int countroom = 0;
	for (int i = 0; i != column; i++) {
		for (int j = 0; j != row; j++) {
			if (cainfo[i][j].visit == 0) {
				int room = 0;
				DFS(i, j, room);
				if (room > maxroom)
					maxroom = room;
				countroom += 1;
			}
		}
	}	
	cout << countroom << endl;
	cout << maxroom << endl;
	system("pause");
	return 0;
}