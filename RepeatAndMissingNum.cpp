#include <bits/stdc++.h>
using namespace std;

class Solution{
    vector<int> repeatedNumber(const vector<int> &A);
};

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    long long int S=(n*(n+1))/2;
    long long int  P=(n*(n+1)*(2*n+1))/6;
    
    for(int i=0;i<n;i++){
        P-=(long long int)A[i]*(long long int)A[i];
        S-=(long long int)(A[i]);
    }
    long long int missing=(P+S)/2;
    long long int twice=(missing-S);
     
    vector<int> res ;
    res.push_back(missing);
    res.push_back(twice);
    return res;

}
