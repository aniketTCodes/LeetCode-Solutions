#include <bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> peeps(n+1,0);
        for(auto &edges:trust){
            peeps[edges[1]]+=1;
        }
        for(int i=1;i<=n;i++){
            if(peeps[i]==n-1)
            return i;
        }
        return -1;
    }
};

int main(){
    Solution s;

}