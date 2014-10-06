#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i=0,j=0;
		while(i<n){
			A[j++]=A[i];
			while(i<n-1&&A[i]==A[i+1])i++;
			i++;
		}
		return j;
    }
};
int main() {
    return 0;
}