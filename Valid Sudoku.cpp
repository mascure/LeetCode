#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include<memory>
#include<map>
#include<queue>
#include <sstream>
#include <set>
//#include <unordered_set>
using namespace std;
const int MAX_N=1000005;
const int inf=1000000;
const int MOD=1000000007;
const int MAX_WH=200;
typedef long long ll;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<set<char>> row(9);
		vector<set<char>> col(9);
		vector<set<char>> box(9);
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				char c=board[i][j];
				if(c!='.'){
					if(row[i].count(c))return false;
					row[i].insert(c);
					if(col[j].count(c))return false;
					col[j].insert(c);
					if(box[i/3*3+j/3].count(c))return false;
					box[i/3*3+j/3].insert(c);
				}
			}
		}
		return true;
    }
};

int main(){
	return 0;
}