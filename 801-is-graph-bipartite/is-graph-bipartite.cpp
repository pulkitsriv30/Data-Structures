class Solution {
public:
    bool bfs(int i,vector<vector<int>>& graph, vector<int>& col) {
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            for(auto it : graph[node]) {
                if(col[it]==-1) {
                    col[it]=!col[node];
                    q.push(it);
                }
                else if(col[it]==col[node])
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> col(V,-1);
        for(int i=0;i<V;i++) {
            if(col[i]==-1) {
                if(bfs(i,graph,col)==false)
                return false;
            }
        }
        return true;
    }
};