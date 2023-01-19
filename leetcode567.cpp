#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s=0;
        int e=s1.size()-1;

        if(s2.size()<s1.size())
        return false;
        char arr[e+1];
        char arr2[e+1];
        s1.copy(arr,e+1);
        sort(arr,arr+e+1);
        int i;
        while(e<s2.size()){
            s2.copy(arr2,s1.size(),s);
            sort(arr2,arr2+s1.size());
            for( i=0;i<=s1.size();i++){
                if(arr[i]!=arr2[i])
                break;
            }
            if(i==s1.size())
            return true;
            s+=1;
            e+=1;
        }
        return false;

 }
};

int main(){
    Solution s;
    cout<<s.checkInclusion("ab","eidbooaoo");
}