#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n=intervals.size();
        if(n<=1)
        return intervals;
        sort(intervals.begin(),intervals.end());
        
       
        int i=1;
        vector<int> interval =intervals[0];
        while(i<n){
            if(interval[1]>=intervals[i][0]){
                interval[1]=max(interval[1],intervals[i][1]);
               
            }
            else{
                res.push_back(interval);
                interval[0]=intervals[i][0];
                interval[1]=intervals[i][1];
                
            }
            i++;
        }
        res.push_back(interval);
        return res;
    }
};