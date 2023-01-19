#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int min_so_far=INT_MAX,min_ending_here=0;
        int max_neg=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(nums[i]<0&&nums[i]>max_neg)
            max_neg=nums[i];
            min_ending_here+=nums[i];
            if(min_so_far>min_ending_here)
            min_so_far=min_ending_here;

            if(min_ending_here>0)
            min_ending_here=0;
        }
        return max(sum-min_so_far,max_neg);
    }
};
int main(){
    Solution s;
    vector<int> nums{1,-2,3,-2};
    cout<<s.maxSubarraySumCircular(nums);
}