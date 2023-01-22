#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> rem;
        rem[0]=1;
        int sum=0;
        int i;
        int remainder,res=0;
        for(i=0;i<nums.size();i++){
            sum+=nums[i];
           
            remainder=sum%k;
            if(remainder<0)
            remainder+=k;
            if(rem.find(remainder)!=rem.end()){
                
                res+=rem[remainder];
                rem[remainder]+=1;
            }   
            else
            rem[remainder]=1;
        }
        return res;
        
    }
};