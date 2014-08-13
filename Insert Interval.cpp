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
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 10005
#define MAX_SIZE 1005
#define MAX_N 100005
#define MAX_M 1005
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105

typedef unsigned long long ull;
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int n=intervals.size();
		vector<Interval> Left,Right,res;
		if(n==0){
			res.push_back(newInterval);
			return res;
		}
		vector<Interval>::iterator it=intervals.begin();
		if(newInterval.start>=intervals[0].start){
			for(it=intervals.begin();it!=intervals.end();it++){
				if(newInterval.start<=it->end)break;
			}
			Left.insert(Left.begin(),intervals.begin(),it);
			if(it!=intervals.end())
			newInterval.start=min(it->start,newInterval.start);
		}
		while(it!=intervals.end()&&it->start<=newInterval.end){it++;}
		Right.insert(Right.begin(),it,intervals.end());
		if(it!=intervals.begin()){
			it--;
			newInterval.end=max(newInterval.end,it->end);
		}
		res.insert(res.end(),Left.begin(),Left.end());
		res.push_back(newInterval);
		res.insert(res.end(),Right.begin(),Right.end());
		return res;
	}
};
int main(){
	
	return 0;
}