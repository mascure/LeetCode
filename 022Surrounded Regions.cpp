#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<list>
#include <stack>
#include<queue>
#include<sstream>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<ext/hash_map>
#include<time.h>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 500
#define MAX_N 105
#define MAX_M 20;
typedef long long ll;
using namespace std;


class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size()==0||board[0].size()==0) {
            return;
        }
        int m=board.size(),n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j]=='O'&&!visited[i][j]) {
                    bool flag=true;
                    isSurrounded(i,j,board, visited, flag);
                    if (flag) {
                        replace(board, i, j);
                    }
                }
            }
        }
    }
    //遍历的过程检查是否被包围，如果是，标记flag如果不是，继续遍历完
    void isSurrounded(int x,int y,vector<vector<char>> &board,vector<vector<bool>> &visited,bool &flag){
        int dir[4][2]={
            {-1,0},
            {0,1},
            {1,0},
            {0,-1}
        };
        int m=board.size(),n=board[0].size();
        visited[x][y]=true;
        if (x==0||x==m-1||y==0||y==n-1) {
            flag=false;
        }
        for (int i=0; i<4; i++) {
            int xx=x+dir[i][0],yy=y+dir[i][1];
            if (xx>=0&&xx<m&&yy>=0&&yy<n&&board[xx][yy]=='O'&&!visited[xx][yy]) {
                isSurrounded(xx, yy, board, visited, flag);
            }
        }
    }
    //置换
    void replace(vector<vector<char>> &board,int x,int y){
        board[x][y]='X';
        int dir[4][2]={
            {-1,0},
            {0,1},
            {1,0},
            {0,-1}
        };
        int m=board.size(),n=board[0].size();
        for (int i=0; i<4; i++) {
            int xx=x+dir[i][0],yy=y+dir[i][1];
            if (xx>=0&&xx<m&&yy>=0&&yy<n&&board[xx][yy]=='O'){
                replace(board,xx,yy);
            }
        }
    }
};


int main() {
    Solution S;
    clock_t start=clock();
    freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    int m,n;
    scanf("%d%d",&m,&n);
    vector<vector<char>> board(m,vector<char>(n,'X'));
    for (int i=0; i<m; i++) {
        getchar();
        for (int j=0; j<n; j++) {
            scanf("%c",&board[i][j]);
        }
    }
    S.solve(board);
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
    clock_t end=clock();
    cout<<end-start<<endl;
    return 0;
}
