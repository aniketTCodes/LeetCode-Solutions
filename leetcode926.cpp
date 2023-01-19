#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
         int n=s.size();
         bool f1=false,f2=false;
        int c1=0,c2=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                f1=true;
            }
            if(f1){
                if(s[i]=='0')
                c1++;
            }
            if(s[n-i-1]=='0'){
                f2=true;
            }
            if(f2){
                if(s[n-i-1]=='1')
                c2++;
            }
        }
        return min(c1,c2);
    }
};