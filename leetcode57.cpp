#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int i;
        vector<vector<int>> ans;
        bool inserted = false;
        for (i = 0; i < intervals.size(); i++)
        {
            if (!inserted)
            {
                if (newInterval[1] < intervals[i][0])
                {
                    ans.push_back(newInterval);
                    inserted = true;
                }
                else if (!(newInterval[0] > intervals[i][1] || newInterval[1] < intervals[i][0]))
                {
                    while (i < intervals.size() && !(newInterval[0] > intervals[i][1] || newInterval[1] < intervals[i][0]))
                    {
                        newInterval[0] = min(newInterval[0], intervals[i][0]);
                        newInterval[1] = max(newInterval[1], intervals[i][1]);
                        i++;
                    }
                    ans.push_back(newInterval);
                    if (i < intervals.size())
                        ans.push_back(intervals[i]);
                    inserted = true;
                    continue;
                }
                else
                    ans.push_back(intervals[i]);
            }else{
                ans.push_back(intervals[i]);
            } 
        }
        if (!inserted)
            ans.push_back(newInterval);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> intervals{{1, 5}};
    vector<int> newInterval{0, 0};
    s.insert(intervals, newInterval);
}