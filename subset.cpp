#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> ans;
         vector<int> subset;
         subsets(nums,subset,0,ans);
         return ans;
    }
    void subsets(vector<int>& nums,vector<int> subset ,int lvl,vector<vector<int>> ans){
            if(lvl==nums.size()){
                ans.push_back(subset);
                return;
            }
            subsets(nums,subset,lvl+1,ans);
            subset.push_back(nums[lvl]);
            subsets(nums,subset,lvl+1,ans);

    }
};
int main(){
    Solution s;
    vector<int> nums{1,2,3};
    s.subsets(nums);
    
}