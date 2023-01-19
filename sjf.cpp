#include <bits/stdc++.h>
using namespace std;

class doubleData{
    public:
    int processingTime;
    int idx;
    doubleData(int processingTime,int idx):processingTime(processingTime),idx(idx){}

};
bool operator<(const doubleData& d1,const doubleData& d2 ){
    if(d1.processingTime==d2.processingTime){
        return d1.idx>d2.idx;
    }
    return d1.processingTime>d2.processingTime;
}





class task{
    public:
    int enqueueTime;
    int processingTime;
    int idx;
    task(int enqueueTime,int processingTime,int idx):enqueueTime(enqueueTime),processingTime(processingTime),idx(idx){}

};
bool operator<(const task& t1,const task& t2){
    return t1.enqueueTime<t2.enqueueTime;
}
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<task> t;
        int n=tasks.size();
        int i;
        for( i=0;i<n;i++){
            t.push_back(task(tasks[i][0],tasks[i][1],i));
        }
        priority_queue<doubleData> pq;
        sort(t.begin(),t.end());
        long currTime=1;
        int taskIdx=0;
        vector<int> ans;
        while(ans.size()<n){
            while(taskIdx<n && t[taskIdx].enqueueTime<=currTime){
                pq.push(doubleData(t[taskIdx].processingTime,t[taskIdx].idx));
                taskIdx++;
            }

            while(!pq.empty()){
                doubleData d=pq.top();
                ans.push_back(d.idx);
                if(pq.size()==1){
                    currTime+=d.processingTime;
                }
                pq.pop();
            }
            
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>> tasks{{7,10},{7,12},{7,5},{7,4},{7,2}};
    vector<int> ans=s.getOrder(tasks);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    }