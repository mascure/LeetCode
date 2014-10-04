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
#include <unordered_set>
using namespace std;
const int MAX_N=105;
const int inf=1000000;
const int MOD=1000000007;
typedef long long ll;
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
		vector<unordered_set<char>> row(9);
		vector<unordered_set<char>> col(9);
		vector<unordered_set<char>> box(9);
		vector<pair<int,int>> blank;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(board[i][j]=='.'){
					blank.push_back(pair<int,int>(i,j));
					continue;
				}
				row[i].insert(board[i][j]);
				col[j].insert(board[i][j]);
				box[i/3*3+j/3].insert(board[i][j]);
			}
		}
		DFS(0,blank,board,row,col,box);
    }
private:
	bool DFS(int t,vector<pair<int,int>> &blank,vector<vector<char> > &board,vector<unordered_set<char>> &row,vector<unordered_set<char>> &col,vector<unordered_set<char>> &box){
		if(t==blank.size()){
			return true;
		}
		int i=blank[t].first,j=blank[t].second;
		for(char c='1';c<='9';c++){
			if(row[i].count(c)>0||col[j].count(c)>0||box[i/3*3+j/3].count(c)>0)
				continue;
			board[i][j]=c;
			row[i].insert(c);
			col[j].insert(c);
			box[i/3*3+j/3].insert(c);
			if(DFS(t+1,blank,board,row,col,box))return true;
			box[i/3*3+j/3].erase(c);
			col[j].erase(c);
			row[i].erase(c);
			board[i][j]='.';
		}
		return false;
	}
};

int main(){
	return 0;
}