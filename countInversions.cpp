#include <bits/stdc++.h>
using namespace std;

class Soln{
    public:
 int mergeSort(vector<long long int>& arr){
        int inversions=0;
         mergeSort(arr,0,arr.size()-1,inversions);
         return inversions;
    }
   void mergeSort(vector<long long int>& arr,int s,int e ,int& inversions){
        if(s>=e){
            return;
        }
        int mid=(s+e)/2;
        mergeSort(arr,s,mid,inversions);
        mergeSort(arr,mid+1,e,inversions);

        inversions+=merge(arr,s,mid,e);
    }
    int merge(vector<long long int>& arr,int s,int mid,int e){
        int inversions=0;
        vector<int> left(arr.begin()+s,arr.begin()+mid+1);
        vector<int> right(arr.begin()+mid+1,arr.begin()+e+1);
        int n1=left.size();
        int n2=right.size();
        int p1=0,p2=0,p3=s;
        while(p1<n1&&p2<n2){

            if(left[p1]>=right[p2]){
                inversions+=n1-p1;
                arr[p3++]=right[p2++];
            }
            else{
                arr[p3++]=left[p1++];
            }
        }

        while(p1<n1){
            arr[p3++]=left[p1++];
        }
        while (p2 < n2) {
          arr[p3++] = right[p2++];
        }
        return inversions;
    }
};


int main(){
    Soln s;
    vector<long long int> arr{5,3,2,1,4};
    cout<<s.mergeSort(arr);
   
}