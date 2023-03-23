#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> res;
    unordered_map<string, bool> memo;
    int n;
    vector<vector<string>> partition(string s){
        n = s.size();
        if (n == 0 || n == 1)
        {
            return {{s}};
        }
        res.clear();
        memo.clear();
        backtrack(s, 0, {});
        return res;
    }
    void backtrack(string &s, int pos, vector<string> curr){
        if (pos == n){
            res.push_back(curr);
            return;
        }
        if (n - pos == 1){
            curr.push_back(s.substr(pos, 1));
            res.push_back(curr);
            return;
        }
        int si = n - pos;
        for (int i = 1; i <= si; i++){
            string temp = s.substr(pos, i);
            if (memo.find(temp) != memo.end() || isValid(temp))
            {
                curr.push_back(temp);
                backtrack(s, pos + i, curr);
                curr.pop_back();
                if (memo.find(temp) == memo.end())
                    memo[temp] = true;
            }
        }
    }
    bool isValid(string s){
        string temp = s;
        reverse(temp.begin(), temp.end());
        return temp == s;
    }
};

int main()
{
}