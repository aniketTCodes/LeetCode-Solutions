#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<vector<int>> visited;
        vector<int> sum={0};
        vector<int> curr;
        vector<int> fin;
        int i,j;
        for(i=0;i<grid.size();i++){
            vector<int> col;
            for(j=0;j<grid[0].size();j++){
                
                if(grid[i][j]==1){
                    curr.push_back(i);
                    curr.push_back(j);
                    col.push_back(1);
                    sum[0]+=1;
                }
                if(grid[i][j]==2){
                    fin.push_back(i);
                    fin.push_back(j);
                    col.push_back(0);
                    
                }
                if(grid[i][j]==0){
                    
                    col.push_back(0);
                }
                if(grid[i][j]==-1){
                    
                    col.push_back(1);
                    sum[0]+=1;
                }
            }
            visited.push_back(col);
        }vector<int> ans={0};
        uniquePathsIII(grid,visited,curr,fin,sum,ans);
        return ans[0];
        
    }

    void uniquePathsIII(vector<vector<int>>& grid,vector<vector<int>>& visited,vector<int>& curr,vector<int>& fin,vector<int>& sum,vector<int>& ans){
        if(curr[0]==fin[0]&&curr[1]==fin[1]&&sum[0]==grid.size()*grid[0].size()){
            ans[0]+=1;
            return; 
        }
        //right
        if(curr[1]<grid[0].size()-1&&visited[curr[0]][curr[1]+1]!=1){
            visited[curr[0]][curr[1]+1]=1;
            curr[1]+=1;
            sum[0]+=1;
            uniquePathsIII(grid,visited,curr,fin,sum,ans);
            sum[0]-=1;
            curr[1]-=1;
            visited[curr[0]][curr[1]+1]=0;
        }
        //left
        if(curr[1]!=0&&visited[curr[0]][curr[1]-1]!=1){
            visited[curr[0]][curr[1]-1]=1;
            curr[1]-=1;
            sum[0]+=1;
            uniquePathsIII(grid,visited,curr,fin,sum,ans);
            curr[1]+=1;
            sum[0]-=1;
            visited[curr[0]][curr[1]-1]=0;
        }
        //up
        if(curr[0]!=0&&visited[curr[0]-1][curr[1]]!=1){
            visited[curr[0]-1][curr[1]]=1;
            curr[0]-=1;
            sum[0]+=1;
            uniquePathsIII(grid,visited,curr,fin,sum,ans);
            sum[0]-=1;
            
            curr[0]+=1;
            visited[curr[0]-1][curr[1]]=0;
        }
        //down
         if(curr[0]<grid.size()-1&&visited[curr[0]+1][curr[1]]!=1){
            visited[curr[0]+1][curr[1]]=1;
            curr[0]+=1;
            sum[0]+=1;
            uniquePathsIII(grid,visited,curr,fin,sum,ans);
            sum[0]-=1;
            curr[0]-=1;
            visited[curr[0]+1][curr[1]]=0;
            
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid={{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout<<s.uniquePathsIII(grid);
}