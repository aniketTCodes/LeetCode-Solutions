#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,vector<int>> map;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i])==map.end()){
                map[nums[i]]={i};
            }
            else{
                map[nums[i]].push_back(i);
            }
            
            
        }
        set<int> s(nums.begin(),nums.end());
        int left;
        for(auto i:s){
            left=target-i;
            if(left==i){
                if(map[left].size()>=2){
                    vector<int> curr=map[target];
                    ans.push_back(map[target][0]);
                    ans.push_back(map[target][1]);
                    break;
                }
                
            }
            if(map.find(left)!=map.end()){
                vector<int> curr=map[left];
                ans.push_back(map[i][0]);
                ans.push_back(curr[0]);
                break;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums{3,3};
    s.twoSum(nums,6);
}