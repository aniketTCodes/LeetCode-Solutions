#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(0);
        }
        vector<bool> visited;
        for(int i=0;i<n;i++){
            visited.push_back(false);
        }
        visited[0]=true;
        countSubTreesHelper(n,adj,0,visited,labels,ans);
        return ans;
    }

    unordered_map<char,int> countSubTreesHelper(int& n,unordered_map<int,vector<int>>& adj,int curr,vector<bool>& visited,string& labels,vector<int>& ans){
        unordered_map<char,int> table;
        table[labels[curr]]=1;
        vector<int> neighbours=adj[curr];
        for(int i=0;i<neighbours.size();i++){
            if(!visited[neighbours[i]]){
                visited[neighbours[i]]=true;
                unordered_map<char ,int> nodeTable=countSubTreesHelper(n,adj,neighbours[i],visited,labels,ans);
                for(auto [key,value]:nodeTable){
                    table[key]+=value;
                }
            }
        }
        ans[curr]=table[labels[curr]];
        return table;
    }
};