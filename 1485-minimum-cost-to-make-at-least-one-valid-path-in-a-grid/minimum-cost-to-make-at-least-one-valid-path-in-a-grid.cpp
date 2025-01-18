class Solution {
public:
    int minCost(vector<vector<int>>& a) {
        // 0 - 1 BFS
        // Maintain a deque(instead of a usual queue)
        // if weight is zero, push to the front of the queue
        // else, push to the back
        // weight := 0 if same direction as original, else 1
        // Modification of Djikstra

        int n = a.size(), m = a[0].size();
        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> dq; //i, j
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        auto valid = [&](int i, int j){
            return i >= 0 && i < n && j >= 0 && j < m;
        };

        dq.push_front({0, 0});
        d[0][0] = 0;
        while(!dq.empty()){
            auto [i, j] = dq.front();
            dq.pop_front();

            for(int k = 0; k < 4; k++){
                int cost = a[i][j] != (k + 1);
                int ni = i + dirs[k][0], nj = j + dirs[k][1];
                if(valid(ni, nj) && d[i][j] + cost < d[ni][nj]){
                    d[ni][nj] = d[i][j] + cost;
                    if(cost)
                        dq.push_back({ ni, nj});
                    else
                        dq.push_front({ni, nj});
                }
            }
        }
        
        return d[n - 1][m - 1];
    }
};