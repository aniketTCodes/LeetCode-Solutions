#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> subset;
        subsets(nums,subset,0,ans);
        vector<vector<int>> res{ans.begin(),ans.end()};
        return res;
    }
    void subsets(vector<int>& nums,vector<int> subset ,int lvl,set<vector<int>> ans){
            if(lvl==nums.size()){
                if(subset.size()>=2)
                ans.insert(subset);
                return;
            }
            subsets(nums,subset,lvl+1,ans);
            if(subset.size()==0){
            subset.push_back(nums[lvl]);
            subsets(nums,subset,lvl+1,ans);
            }
            else if(subset[subset.size()-1]<=nums[lvl]){
            subset.push_back(nums[lvl]);
            subsets(nums,subset,lvl+1,ans);}

    }
};
int main(){
    Solution s;
    vector<int> nums{4,4};
    s.findSubsequences(nums);
}