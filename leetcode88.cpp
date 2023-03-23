#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> t(nums1.begin(),nums1.begin()+m);
        nums1.clear();
        int p1=0,p2=0;
        while(p1<m&&p2<n){
            nums1.push_back((t[p1]<nums2[p2]?:t[p1++],nums2[p2++]));
        }
        if(p1==m){
            while(p2<n){
                nums1.push_back(nums2[p2++]);
            }
        }
        else{
            while(p1<m){
                nums1.push_back(t[p1++]);
            }
        }
        
    }
};

int main(){
    Solution s;
    vector<int> nums1{1,2,3,0,0,0};
    vector<int> nums2{2,5,6};
    s.merge(nums1,3,nums2,3);
}