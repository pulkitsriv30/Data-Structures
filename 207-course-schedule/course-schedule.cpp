class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis,vector<int>& pathVis) {
        for(auto it : adj[node]) {
            if(!vis[it]) {
                vis[it]=1;
                pathVis[it]=1;
                if(dfs(it,adj,vis,pathVis)==true)
                return true;
            }
            else if(vis[it] && pathVis[it])
            return true;
        }
        pathVis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto edge: prerequisites) {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++) {
            if(!vis[i]) {
                vis[i]=1;
                pathVis[i]=1;
                if(dfs(i,adj,vis,pathVis))
                return false;
            }
        }
        return true;
    }
};

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // int vis[numCourses]={0};
        // vis[0]=1;
        // queue<pair<int,int>> q;
        // q.push({0,-1});
        // while(!q.empty()) {
        //     int node=q.front().first;
        //     int parent=q.front().second;
        //     for(auto it : adj[node]) {
        //         if(!vis[it]) {
        //             vis[it]=1;
        //             q.push({it,node});
        //         }
        //         else if(parent!=it) {
        //             return true;
        //         }
        //     }   
        // }
        // return false; 