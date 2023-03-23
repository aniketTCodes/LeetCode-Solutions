#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
        bool flag=n<0;
        n=abs(n);
        while(n>0){
            if(n%2==1)
            res*=x;

            x=x*x;
            n=n/2;
        }
        if(flag)
        return 1.0/res;
        return res;
    }
};

int main(){
    Solution s;
    cout<<s.myPow(2.0,-2);
}