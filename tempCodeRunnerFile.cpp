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
            
            for(int i=0;i<n;i++){
                int curr=pq.front();
            pq.pop();
                if(curr==n*n) return steps;
                for(int j=1;j<=6;j++){
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
        }
        steps++;


            

            }
            return -1;

        }


    vector<int> getCoordinates(vector<vector<int>>& board,int i){
       int r=n-(i-1)/n -1;
       int c=(i-1)%n;
       if(r%2==n%2){
        return {r,n-1-c}; 
       }
       return {r,c};
    }
};