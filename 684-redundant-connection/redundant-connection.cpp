class Solution {
public:
    bool bfs(int src, int dest, vector<vector<int>>&adj){
        queue<int>q;
        unordered_map<int,bool>visited;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == dest){
                return true;
            }
            for(auto& nbr:adj[node]){
                 if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adj(n+1);

        for(auto& edge:edges){
            int u = edge[0];
            int v = edge[1];

            if (!adj[u].empty() && !adj[v].empty() && bfs(u, v, adj)) {
                return edge;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};