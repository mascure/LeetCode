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
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> res;
		sort(num.begin(),num.end());
		do{
			res.push_back(num);
		}while(next_permutation(num.begin(),num.end()));
		return res;
    }
};
int main(){
}