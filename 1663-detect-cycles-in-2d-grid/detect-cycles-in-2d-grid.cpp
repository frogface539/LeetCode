class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {

        visited[node] = true;

        for (int nbr : adj[node]) {

            if (!visited[nbr]) {
                if (dfs(nbr, node, adj, visited))
                    return true;
            }
            else if (nbr != parent) {
                return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int totalNodes = n * m;

        vector<vector<int>> adj(totalNodes);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int node = i * m + j;

                if (i + 1 < n && grid[i][j] == grid[i + 1][j]) {
                    int nbr = (i + 1) * m + j;
                    adj[node].push_back(nbr);
                    adj[nbr].push_back(node);
                }

                if (j + 1 < m && grid[i][j] == grid[i][j + 1]) {
                    int nbr = i * m + (j + 1);
                    adj[node].push_back(nbr);
                    adj[nbr].push_back(node);
                }
            }
        }

        vector<bool> visited(totalNodes, false);
        for (int node = 0; node < totalNodes; node++) {
            if (!visited[node]) {
                if (dfs(node, -1, adj, visited))
                    return true;
            }
        }
        return false;
    }
};