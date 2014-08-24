#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include<memory>
#include<map>
#include<unordered_map>
#include<queue>
#include <sstream>
#include <set>
using namespace std;
const int MAX_N=100005;
typedef long long ll;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		int n=matrix.size();
		if(n<2)return;
		for(int start=0;start<n/2;start++){
			for(int j=0;j+start<n-1-start;j++){
				int t=j+start;
				int tmp=matrix[start][t];
				matrix[start][t]=matrix[n-1-t][start];
				matrix[n-1-t][start]=matrix[n-1-start][n-1-t];
				matrix[n-1-start][n-1-t]=matrix[t][n-1-start];
				matrix[t][n-1-start]=tmp;
			}
		}
		return ;
    }
};
int main(){
}