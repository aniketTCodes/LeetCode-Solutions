#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n;
    int snakesAndLadders(vector<vector<int>>& board) {
        int steps=0;
         n=board.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        queue<int> pq;
        pq.push(1);
        visited[n-1][0]=true;
        while(!pq.empty()){
            int si=pq.size();
            for(int i=0;i<si;i++){
                int curr=pq.front();
            pq.pop();
                if(curr==n*n) return steps;
                for(int j=1;j<=6;j++){
                    if(j+curr>n*n) break;
                vector<int> pos=getCoordinates(board,curr);
                int r=pos[0];
                int c=pos[1];
                if(visited[r][c]==true) continue;
                visited[r][c]=true;
                if(board[r][c]==-1)
                pq.push(curr+j);
                else{
                    pq.push(board[r][c]);
                }

            }
            steps+=1;
        }
       


            

            }
            return -1;

        }


    vector<int> getCoordinates(vector<vector<int>>& board,int i){
       int row=n%i==0?(n/i)-1:n/i;
       int temp= board[row][0];
       int col=abs(temp-i);
       return {row,col};
    }
};

int main(){
    Solution s;
    vector<vector<int>> board{{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    cout<<s.snakesAndLadders(board);
}   