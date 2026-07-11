class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n,false);

        int ans = 0;

        for(int i=0;i<n;i++){

            if(visited[i]) continue;

            queue<int> q;
            q.push(i);
            visited[i] = true;

            int nodes = 0;
            int degreeSum = 0;

            while(!q.empty()){

                int node = q.front();
                q.pop();

                nodes++;
                degreeSum += adj[node].size();

                for(int nbr : adj[node]){

                    if(!visited[nbr]){
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }

            int edgeCount = degreeSum / 2;

            if(edgeCount == nodes * (nodes - 1) / 2)
                ans++;
        }

        return ans;
    }
};