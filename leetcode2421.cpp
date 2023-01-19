#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(vector<int>& parent,int x){
        if(x==parent[x])
        return x;
        return find(parent,x);
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        vector<int> parent;
        int n=vals.size();
        unordered_map<int,int> count;
        unordered_map<int,int> maxElement;
        for(int i=0;i<n;i++){
            parent.push_back(i);
            maxElement[i]=vals[i];
            count[i]=1;
        }
        sort(edges.begin(),edges.end(),[&](vector<int> a,vector<int> b){
            return max({vals[a[0]],vals[a[1]]})<max({vals[b[0]],vals[b[1]]});
        });
        int ans=n;
        for(vector<int>& edge:edges){
            int a=find(parent,edge[0]);
            int b=find(parent,edge[1]);
            if(maxElement[a]!=maxElement[b]){
                if(maxElement[a]>maxElement[b]){
                    parent[b]=a;
                }else
                parent[a]=b;
            }
            else{
                parent[a]=b;
                ans+=count[a]*count[b];
                count[b]+=count[a];
            }
        }
        return ans;

    }
};