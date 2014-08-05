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
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

  struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
  typedef vector<int> BigInt;
class Solution {
public:
   vector<int> findSubstring(string S, vector<string> &L) {
	   vector<int> res;
	   int wordLength=L.front().length();
	   if(wordLength*L.size()>S.length())return res;
	   unordered_map<string,int> wordCount;
	   for(auto const& word:L) wordCount[word]++;
	   int totalLength=wordLength*L.size();
	   for(int i=0;i+totalLength<=S.length();i++){
		   unordered_map<string,int> unused(wordCount);
		   for(int j=i;j<i+totalLength;j+=wordLength){
			   auto pos=unused.find(S.substr(j,wordLength));
			   if(pos==unused.end()||pos->second==0)break;
			   if(--pos->second==0)unused.erase(pos);
		   }
		   if(unused.size()==0)res.push_back(i);
	   }
	   return res;
   }
};
int main(){
	Solution S;
	vector<string> L;
	L.push_back("foo");
	L.push_back("bar");
	S.findSubstring("barfoothefoobarman",L);
	return 0;
}