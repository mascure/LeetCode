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
using namespace std;
const int MAX_N=105;
const int inf=1000000;
const int MOD=1000000007;
typedef long long ll;
class Solution {
public:
    string countAndSay(int n) {
        string s="1";
		for(int i=2;i<=n;i++){
			string t="";
			int j=0;
			while(j<s.length()){
				int k=j+1;
				while(k<s.length()&&s[j]==s[k])k++;
				t+=('0'+(k-j));
				t+=s[j];
				j=k;
			}
			swap(s,t);
		}
		return s;
    }
};
int main(){
	return 0;
}