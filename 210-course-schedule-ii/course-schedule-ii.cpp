class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<vector<int>> ad(N);
        vector<int> topo;
        for (auto& it : prerequisites) {
            ad[it[0]].push_back(it[1]);
        }
        vector<int> inde(N, 0);
        for (int i = 0; i < N; i++) {
            for (auto it : ad[i]) {
                inde[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (inde[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for (auto it : ad[node]) {
                inde[it]--;
                if (inde[it] == 0)
                    q.push(it);
            }
        }
        reverse(topo.begin(), topo.end());

        return topo.size() == N ? topo : vector<int>{};
    }
};