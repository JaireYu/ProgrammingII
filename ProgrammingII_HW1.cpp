//brute force
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
typedef struct {
    int visit = 0;
    int round = 0;
}Process;
char strings[1000][21];
bool compare(int i, int j, int k){//比较就j,k到i前的情况
    for(int t = 0; t != i+1; t++){
        if(strings[j][t] != strings[k][t])
            return false;
    }
    return true;
}
int main(){
    int len = 0;
    char str[21];
    while(cin>>strings[len]){
        len++;
    }
    Process* status = new Process[len];
    for(int i = 0; i != 21; i++){
        for(int j = 0; j != len; j++){
            if(strings[j][i] == '\0')
                status[j].visit = 1;
            if(status[j].visit == 1)
                continue;
            int flag = 0;
            for(int k = 0; k != len; k++){
                if(k == j) continue;
                if(status[k].visit == 1)
                    continue;
                else {
                    if (compare(i, j, k)) {
                        status[j].round = i + 1;
                        flag = 1;
                    }
                }
            }
            if(flag == 0){ //区别于\0结尾的情况
                status[j].round = i + 1;
                status[j].visit = 1;
            }
        }
    }
    for(int i = 0; i != len; i++){
        int k = status[i].round;
        printf("%s ", strings[i]);
        for(int j = 0; j != k; j++){
            printf("%c", strings[i][j]);
        }
        printf("\n");
    }
    delete[] status;
}