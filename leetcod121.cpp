#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int minVal=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(minVal>prices[i]){
                minVal=prices[i];
            }
            max_profit=max({(prices[i]-minVal),max_profit});
        }
        return max_profit;

    }
};