#include <bits/stdc++.h>
using namespace std;

class Solution {
    int r,c;
public:
     int uniquePaths(int m, int n){
        vector<vector<int>> visited(m,vector<int>(n,-1));
        r=m-1,c=n-1;
        return paths(visited,0,0);


    }

    int paths(vector<vector<int>> &visited,int cr,int cc){
        if(cr==r and cc==c){
            return 1;
        }
        int pathcost=0;
        if((cr<=r and cc<=c)and visited[cr][cc]==-1){
            pathcost=paths(visited,cr+1,cc)+paths(visited,cr,cc+1);
            visited[cr][cc]=pathcost;
        }
        return visited[cr][cc];
    }

    
};
