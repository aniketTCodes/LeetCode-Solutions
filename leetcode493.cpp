#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int reversePairs(vector<int>& nums){
        long long int revPair=0;
        int n=nums.size();
        if(n==0)
        return 0;

        mergeSort(nums,0,n-1,revPair);
        return revPair;
        
    }

    void mergeSort(vector<int>& nums,int s,int e,long long int& revPair){
        if(s>=e)
        return ;

        int mid=(s+e)/2;
        mergeSort(nums,s,mid,revPair);
        mergeSort(nums,mid+1,e,revPair);
        revPair+=merge(nums,s,mid,e);
        
        
    }

    int merge(vector<int> &nums,int s,int mid,int e){
        int revPari=0;
        vector<int> left(nums.begin()+s,nums.begin()+mid+1);
        vector<int> right(nums.begin()+mid+1,nums.begin()+e+1);
        int n1=left.size();
        int n2=right.size();
        int p1=0,p2=0,p3=s,t;
        while(p1<n1&&p2<n2){
            if(left[p1]<right[p2]){
                nums[p3++]=left[p1++];
            }

            else{
                int t=p1;
                while(t<n1&&(long long int)left[t]<=2*(long long int)right[p2]){
                    t+=1;
                }
                revPari+=n1-t;
                nums[p3++]=right[p2++];
            }
        }
        while(p1<n1){
            nums[p3++]=left[p1++];
        }
        while(p2<n2){
            nums[p3++]=right[p2++];

        }

        return revPari;
        
    }
};

int main(){
    Solution s;

    vector<int> nums{1,3,2,3,1};
    cout<<s.reversePairs(nums);
}