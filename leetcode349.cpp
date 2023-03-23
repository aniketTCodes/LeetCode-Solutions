#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> tem(1001,false);
        vector<int> res;
        int i;
        for( i=0;i<nums1.size();i++){
            tem[nums1[i]]=true;
        }
        set<int> s(nums2.begin(),nums2.end());
        for(auto i :s){
            if(tem[i])
            res.push_back(i);
        }
    }
};

int main(){
    Solution s;
    vector<int> nums1{1,2,2,1};
    vector<int> nums2{2,2};
    vector<int> res=s.intersection(nums1,nums2);
}