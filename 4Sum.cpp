#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<windows.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> res;
		if(num.size()<4)return res;
		unordered_map<int,vector<pair<int,int>>> m;
		sort(num.begin(),num.end());
		for(int i=0;i<num.size();i++){
			for(int j=i+1;j<num.size();j++){
				m[num[i]+num[j]].push_back(make_pair(i,j));
			}
		}
		for(int i=0;i<num.size();i++){
			if(i>0&&num[i]==num[i-1])continue;
			for(int j=i+1;j<num.size();j++){
				if(j>i+1&&num[j]==num[j-1])continue;
				int t=target-num[i]-num[j];
				if(m.count(t)){
					for(auto it=m[t].begin();it!=m[t].end();it++){
						int h=it->first,k=it->second;
						if(h>j){
							//vector<int> tmp={num[i],num[j],num[h],num[]};
							vector<int> tmp(4);
							tmp[0]=num[i];tmp[1]=num[j];
							tmp[2]=num[h];tmp[3]=num[k];
							if(!res.empty()&&res.back()==tmp)continue;
							res.push_back(tmp);
						}
					}
				}
			}
		}
		return res;
    }
};

int main() {
	int A[]={-493,-482,-482,-456,-427,-405,-392,-385,-351,-269,-259,-251,-235,-235,-202,-201,-194,-189,-187,-186,-180,-177,-175,-156,-150,-147,-140,-122,-112,-112,-105,-98,-49,-38,-35,-34,-18,20,52,53,57,76,124,126,128,132,142,147,157,180,207,227,274,296,311,334,336,337,339,349,354,363,372,378,383,413,431,471,474,481,492};
	vector<int> num(4,0);
	Solution S;
	auto start=GetTickCount();
	S.fourSum(num,0);
	auto end=GetTickCount();
	cout<<end-start<<endl;
    return 0;
}