#include<iostream>
#include<string>
using namespace std;
string str;
int flag;
string express(int &deep, int &flag) {
	if (deep == -1)
		return "";
	switch (str[deep]) {
	case '*': {
		deep--;
		int flag1, flag2;
		flag = 1;
		string str1 = express(deep, flag1);
		string str2 = express(deep, flag2);
		if (str1.size() == 1 && str2.size() == 1)  //左数幼鼠
			return str2 + "*" + str1;
		else if (str1.size() != 1 && str2.size() != 1) {  //左氏有屎
			if(flag2 == 1)
				return   str2  + "*" + "(" + str1 + ")";
			else
				return "(" + str2 + ")" + "*" + "(" + str1 + ")";
		}
		else if(str1.size() != 1 && str2.size() == 1){ //左数有时
				return  str2 + "*" + "(" + str1 + ")";
		}
		else {
			if (flag2 == 0) {
				return "(" + str2 + ")" + "*"  + str1 ;
			}
			else 
				return  str2  + "*"  + str1 ;
		}
	}break;
	case '-': {
		deep--;
		flag = 0;
		int flag1, flag2;
		string str1 = express(deep, flag1);
		string str2 = express(deep, flag2);
		if (str1.size() == 1)
			return str2 + "-" + str1;
		else if (str1.size() != 1 && str2.size() != 1) {
			if (flag1 == 1)
				return  str2 + "-" + str1;
			else
				return "(" + str2 + ")" + "-" + "(" + str1 + ")";
		}

		else {
			if (flag1 == 1)
				return str2 + "-" + str1;
			else
				return  str2 + "-" + "(" + str1 + ")";
		}

	}break;
	case '/': {
		deep--;
		int flag1, flag2;
		flag = 1;
		string str1 = express(deep, flag1);
		string str2 = express(deep, flag2);
		if (str1.size() == 1 && str2.size() == 1)  //左数幼鼠
			return str2 + "/" + str1;
		else if (str1.size() != 1 && str2.size() != 1) {  //左氏有屎
			if (flag2 == 1)
				return   str2 + "/" + "(" + str1 + ")";
			else
				return "(" + str2 + ")" + "/" + "(" + str1 + ")";
		}
		else if (str1.size() != 1 && str2.size() == 1) { //左数有时
			return  str2 + "/" + "(" + str1 + ")";
		}
		else {
			if (flag2 == 0) {
				return "(" + str2 + ")" + "/" + str1;
			}
			else
				return  str2 + "/" + str1;
		}
	}break;

	case '+': {
		deep--;
		flag = 0;
		int flag1, flag2;
		string str1 = express(deep, flag1);
		string str2 = express(deep, flag2);
		if (str1.size() == 1)
			return str2 + "+" + str1;
		else if(str1.size() != 1 && str2.size() != 1){
			if (flag1 == 1)
				return  str2 + "+" + str1;
			else 
				return "(" + str2 + ")" + "+" + "(" + str1 + ")";
		}	
		else {
			if(flag1 == 1)
				return str2 + "+"  + str1;
			else
			return  str2  + "+" + "(" + str1 + ")";
		}
			
	}break;
	default: {
		string strtemp;
		strtemp.push_back(str[deep]);
		deep--;
		return strtemp;
	}
	}
}
int main() {
	getline(cin, str);
	int index = str.size() - 1;
	int num = 0;
	string str2 = express(index, num);
	cout << str2;
	system("pause");
	return 0;
}