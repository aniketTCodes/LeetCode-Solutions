#include <bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> p;
        int i;
        for(i=0;i<26;i++){
            p.push_back(i);
        }

        for(i=0;i<s1.length();i++){
            int a=(int)(s1[i]-'a');
            int b=(int)(s2[i]-'a');
            unionSet(a,b,p);
        }
        string res="";
        for(i=0;i<baseStr.size();i++){
            int x=(int)(baseStr[i]-'a');
            res+=(char)(find(x,p)+97);

        }

        return res;
    }

    int find(int x,vector<int>& p){
        if(p[x]==x)
        return x;

       return  find(p[x],p);
    }

    void unionSet(int a,int b,vector<int>& p){
        int x=find(a,p);
        int y=find(b,p);
        if(x==y)
        return;
        if(y<x){
            p[x]=y;
        }
        else
        p[y]=x;
        return;
    }
};