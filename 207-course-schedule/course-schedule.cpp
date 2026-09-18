class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        int count=0;
        vector<int> inDegree(V,0);
        vector<vector<int>> adj(V);
        for(auto it  : prerequisites) {
            int u=it[0];
            int v=it[1];
            inDegree[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        for(int i=0;i<V;i++) {
            if(inDegree[i]==0)
            q.push(i);
        }
        while(!q.empty()) {
            int node=q.front();
            count++;
            q.pop();
            for(auto it : adj[node]) {
                inDegree[it]--;
                if(inDegree[it]==0)
                q.push(it);
            }
        }
        if(count==V)
        return true;
        else 
        return false;
    }
};