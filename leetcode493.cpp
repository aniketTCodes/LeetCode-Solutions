#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        long long int reversePair=0;
        mergeSort(nums,0,nums.size()-1,reversePair);
        return reversePair;
    }

    int merge(vector<int>& nums,int low,int mid,int high){
        long long int revPairs=0;
        int i,j;
        //Calculating reverse pair
         for(i=mid+1;i<=high;i++){
            j=low;
            while(j<=mid&&nums[i]*2>=nums[j])
                j++;
            revPairs+=(mid+1)-j;
        }

        //merging operation

        vector<int> left(nums.begin()+low,nums.begin()+mid+1);
        vector<int> right(nums.begin()+mid+1,nums.begin()+high+1);
        int p1=0,p2=0,p3=low,n1=left.size(),n2=right.size();

        while(p3<=high){
            if(p1<n1&&p2<n2){
                if(left[p1]<=right[p2]){
                    nums[p3++]=left[p1++];
                }
                else
                nums[p3++]=right[p2++];
            }
            else if(p1>=n1&&p2<n2){
                nums[p3++]=right[p2++];
            }
            else
                nums[p3++]=left[p1++];
            
        }
        return revPairs;
    }

    void mergeSort(vector<int>& nums,int low,int high,long long int& revPairs){
        if(low>=high){
            return;
        }
        int mid=(low+high)/2;
        mergeSort(nums,low,mid,revPairs);
        mergeSort(nums,mid+1,high,revPairs);

        revPairs+=merge(nums,low,mid,high);
    }
};

int main(){
    Solution s;
    vector<int> nums {2,4,3,5,1};
    cout<<s.reversePairs(nums);
}