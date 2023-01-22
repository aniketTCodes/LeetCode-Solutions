#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12)
        return {};

        res.clear();
        backtrack(s,0,0,"");
        return res;
    }

    void backtrack(string& s,int candidates,int pos,string ip){
        if(pos==s.length()&&candidates==4){
            ip.pop_back();
            res.push_back(ip);
            return;
        }
        if(pos+1<s.size()&&isValid(s.substr(pos,1)))
        backtrack(s,candidates+1,pos+1,ip+s.substr(pos,1)+"."); 
        if(pos+2<s.size()&&isValid(s.substr(pos,2)))
        backtrack(s,candidates+1,pos+2,ip+s.substr(pos,2)+".");
        if(pos+3<s.size()&&isValid(s.substr(pos,3)))
        backtrack(s,candidates+1,pos+3,ip+s.substr(pos,3)+".");
        
    }

    bool isValid(string s){
        if(stoi(s)<=255){
            if((s.size()==2&&stoi(s)/10>0)||(s.size()==3&&stoi(s)/100>0)||s.size()==1)
            return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    s.restoreIpAddresses("25525511135");
}