#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges,vector<bool> hasApple) {
     vector<bool> visited;
        for(int i=0;i<n;i++){
            visited.push_back(false);
        }
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        visited[0]=true;
        return dfs(n,adj,0,hasApple,visited);
    }


    int dfs(int n,unordered_map<int,vector<int>>& adj,int curr,vector<bool>& hasApple,vector<bool> visited){

        int cost=0;
        vector<int> neighbours=adj[curr];
        if(neighbours.size()==0){
            visited[curr]=true;

        }
        else
        for(int i=0;i<neighbours.size();i++){
            if(curr==neighbours[i])
            continue;
            if(!visited[neighbours[i]]){
                visited[neighbours[i]]=true;
                cost+=dfs(n,adj,neighbours[i],hasApple,visited);
            }
        }
        if(curr!=0)
        if(cost>0||hasApple[curr])
        return cost+2;
        return cost;
    }

};
int main(){
    Solution s;
    vector<vector<int>> edges{{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    vector<bool> hasApple{false,false,true,false,true,true,false};
    cout<<s.minTime(7,edges,hasApple);

}