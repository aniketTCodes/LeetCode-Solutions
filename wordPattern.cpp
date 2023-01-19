#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> map;
        set<string> words;
        int idx=0;
        istringstream ss(s);
        string word;
        while(idx<pattern.length()&&ss >> word){
           
            char ch=pattern[idx++];
            if(map.find(ch)==map.end()){
                if(map2.find(word)==map2.end()){
                map[ch]=word;
                 map2[word]=true;
                }
                else 
                return false;


            }
            else{
                if(word!=map[ch])
                return false;
            }

        }
       
        if(!(ss>>word) && idx==pattern.length())
        return true;
        else
        return false;
    }
};

int main(){

}