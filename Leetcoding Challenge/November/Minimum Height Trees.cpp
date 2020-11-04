/*  A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 
Example:


Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.  */

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
        return vector<int>{0};
        vector<vector<int>>graph(n);
        vector<int>degree(n);
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
            if(degree[i]==1)
                q.push(i);
        vector<int>res;
        while(!q.empty())
        {
            int n=q.size();
            res.clear();
            while(n--)
            {
                int cur_node=q.front();
                q.pop();
                res.push_back(cur_node);
                for(int i=0;i<graph[cur_node].size();i++)
                {
                    degree[graph[cur_node][i]]--;
                    if(degree[graph[cur_node][i]]==1)
                        q.push(graph[cur_node][i]);
                }
            }
        }
        return res;
    }
};
