class Solution {
public:
    bool DFSRec(int s, unordered_map<int, bool>& visited,
                unordered_map<int, bool>& currVisited, vector<int> adj[]) {
        visited[s] = true;
        currVisited[s] = true;

        for (auto x : adj[s]) {
            if (!visited[x]) {
                if (DFSRec(x, visited, currVisited, adj)) {
                    return true; 
                }
            } else if (currVisited[x]) {
                return true; 
            }
        }

        currVisited[s] = false; 
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_map<int, bool> visited;
        unordered_map<int, bool> currVisited;

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (DFSRec(i, visited, currVisited, adj)) {
                    return false; 
                }
            }
        }
        return true;
    }
};