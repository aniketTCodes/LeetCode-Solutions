#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rank;
    vector<int> parent;
    int find(int x)
    {
        if (x == parent[x])
            return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionF(int a, int b)
    {
        int x = find(a);
        int y = find(b);

        if (rank[x] < rank[y])
        {
            parent[y] = x;
            rank[x]++;
        }
        else if (rank[y] < rank[x])
        {
            parent[x] = y;
            rank[y]++;
        }
        else
            parent[y] = x;
        rank[x]++;
    }

    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {
        int n = vals.size();
        parent.resize(n);
        rank.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        unordered_map<int, vector<int>> adj;
        for (vector<int> &vec : edges)
        {
            adj[(vec[0])].push_back(vec[1]);
            adj[(vec[1])].push_back(vec[0]);
        }

        map<int, vector<int>> val;
        for (int i = 0; i < n; i++)
        {
            val[vals[i]].push_back(i);
        }

        int res = n;

        vector<bool> active(n, false);

        for (auto &it : val)
        {

            vector<int> nodes = it.second;

            for (auto &node : nodes)
            {
                for (auto &neig : adj[node])
                {
                    if (active[neig])
                        unionF(node, neig);
                }
                active[node] = true;
            }

            vector<int> parent_of_node;

            for (int i = 0; i < nodes.size(); i++)
            {
                parent_of_node.push_back(find(nodes[i]));
            }

            sort(parent_of_node.begin(), parent_of_node.end());
            for (int i = 0; i < parent_of_node.size(); i++)
            {
                long count = 0;
                int curr_parent = parent_of_node[i];
                while (i < parent_of_node.size() && parent_of_node[i] == curr_parent)
                {
                    count++;
                    i++;
                }
                i--;

                res += (count * (count - 1) / 2);
            }
        }

        return res;
    }
};