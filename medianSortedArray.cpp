#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArray;
        int n1=nums1.size();
        int n2=nums2.size();
        int p1=0;
        int p2=0;
        while(!(p1>=n1)||!(p2>=n2)){
            if(!(p1>=n1)&&!(p2>=n2)){
                if(nums1[p1]>nums2[p2]){
                    mergedArray.push_back(nums2[p2]);
                    p2++;
                }
                else{
                mergedArray.push_back(nums1[p1]);
                p1++;
                }
            }
            else if((p1>=n1)&&!(p2>=n2)){
                mergedArray.push_back(nums2[p2++]);
            }
            else{
                mergedArray.push_back(nums1[p1++]);
            }
        }
        int n=mergedArray.size();
        if(n%2==0){
            return ((mergedArray[n/2]*1.0)+(mergedArray[n/2+1]*1.0))/2;
        }
        else
        return mergedArray[n/2]*1.0;
    }
};
int main(){
    Solution s;
    vector<int> nums1{1,2};
    vector<int> nums2{3};
    cout<<s.findMedianSortedArrays(nums1,nums2);
}