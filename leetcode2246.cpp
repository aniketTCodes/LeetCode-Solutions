#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int result;
    int longestPath(vector<int>& parent, string s) {
        unordered_map<int,vector<int>> adj;
        for(int i=1;i<parent.size();i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
            result=0;
  
        
        
         longestPathHelper(adj,0,-1,s);
         return result;
    }

    int longestPathHelper(unordered_map<int,vector<int>>& adj,int curr,int parent,string& label){
        int longestcost=0;
        int secondlongestcost=0;

        for(auto &child:adj[curr]){
            if(child==parent){
                continue;
            }
            
            int cost=longestPathHelper(adj,child,curr,label);
            if(label[curr]==label[child])
            continue;
            if(cost>secondlongestcost)
            secondlongestcost=cost;
            if(secondlongestcost>=longestcost)
            swap(secondlongestcost,longestcost);

            

        }
        int both_r_good=longestcost+secondlongestcost+1;
        int one_good=max(longestcost,secondlongestcost)+1;
        int only_root=1;

       result=max({result,both_r_good,one_good,only_root});
       return max({one_good,only_root});
    }
};

int main(){
    Solution s;
    vector<int> parents{-1,0,1};
    string str="aab";
    cout<<s.longestPath(parents,str);
}