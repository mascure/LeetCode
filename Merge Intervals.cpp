#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#include<set>
#include<stack>
#include<math.h>
#include<unordered_map>
#include<windows.h>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 10005
#define MAX_SIZE 1005
#define MAX_M 1005
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105

typedef unsigned long long ull;
using namespace std;
int const MAX_N=105;
struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
bool cmp(Interval a,Interval b){
		return a.start<b.start;
	}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
		if(intervals.size()==0)return res;
		sort(intervals.begin(),intervals.end(),cmp);
		Interval now=intervals[0];
		for(int i=1;i<intervals.size();i++){
			if(intervals[i].start<=now.end){
				now.end=max(now.end,intervals[i].end);
			}
			else{
				res.push_back(now);
				now=intervals[i];
			}
		}
		res.push_back(now);
		return res;
    }
};
int main(){
	Solution S;
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
	}
	return 0;
}