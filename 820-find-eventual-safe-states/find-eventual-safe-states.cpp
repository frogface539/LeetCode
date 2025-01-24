class Solution {
public:
    bool checkCycle(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& rec, vector<bool>& safe) {
        if (rec[u]) return false;
        if (visited[u]) return safe[u];

        visited[u] = true;
        rec[u] = true;

        for (int v : adj[u]) {
            if (!checkCycle(adj, v, visited, rec, safe)) {
                return false;
            }
        }

        rec[u] = false;
        safe[u] = true;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V, false);
        vector<bool> rec(V, false);
        vector<bool> safe(V, false);
        vector<int> safeNodes;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                checkCycle(graph, i, visited, rec, safe);
            }
        }

        for (int i = 0; i < V; i++) {
            if (safe[i]) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};
