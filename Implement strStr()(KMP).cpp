#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<string.h>
using namespace std;
class Solution {
public:
    char *strStr(char *S, char *T) {
		if(!S||!T)return NULL;
		if(!*T)return S;
		int Plen=strlen(T);
		int Slen=strlen(S);
		int i=0,j=0;
		int *next=new int[Plen+1];
		initNext(T,next);
		while(i<Slen&&j<Plen){
			if(j==-1||S[i]==T[j]){
				i++;j++;
			}
			else{
				j=next[j];
			}
		}
		if(j==Plen){
			return S+i-j;
		}
		else
		return NULL;
    }
private:
	void initNext(char* p,int next[]){
		int Plen=strlen(p);
		next[0]=-1;
		int k=-1,j=0;
		while(j<Plen-1){
			if(k==-1||p[k]==p[j]){
				k++;j++;
				next[j]=k;
			}
			else{
				k=next[k];
			}
		}
	}
};
int main() {
	Solution S;
	strstr("ab","a");
	string s;
    return 0;
}