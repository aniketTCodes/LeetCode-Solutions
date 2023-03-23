#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows=matrix.size();
        int col=matrix[0].size();
        
        int start=0;
        int end=rows-1;
        int mid;
        
        while(start<=end){
            mid=(start+end)/2;
            if(matrix[mid][0]<=target&&matrix[mid][col-1]>=target){
                return binSearch(matrix[mid],0,col-1,target);
            }
            else if(matrix[mid][0]>target){
                end=mid-1;
            }
            else 
            start=mid+1;
        }
        return false;


    }

    bool binSearch(vector<int>& arr,int s,int e,int target){
        if(s>e)
        return false;
        int mid=(s+e)/2;
        if(arr[mid]==target)
        return true;
        if(arr[mid]<target){
            return binSearch(arr,mid+1,e,target);
        }
        else{
            return binSearch(arr,s,mid-1,target);
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<s.searchMatrix(mat,3);
} 