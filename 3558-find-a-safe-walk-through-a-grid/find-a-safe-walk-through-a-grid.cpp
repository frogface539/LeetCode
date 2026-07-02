class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>> q;

        int startHealth = health - grid[0][0];

        if(startHealth <= 0)
            return false;

        vector<vector<int>> best(n, vector<int>(m, -1));

        best[0][0] = startHealth;

        q.push({0,0,startHealth});

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!q.empty()){

            auto curr = q.front();
            q.pop();

            int x = curr[0];
            int y = curr[1];
            int hp = curr[2];

            if(x == n-1 && y == m-1)
                return true;

            for(int k=0;k<4;k++){

                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx<0 || nx>=n || ny<0 || ny>=m)
                    continue;

                int newHealth = hp - grid[nx][ny];

                if(newHealth <= 0)
                    continue;

                if(newHealth > best[nx][ny]){

                    best[nx][ny] = newHealth;
                    q.push({nx, ny, newHealth});
                }
            }
        }

        return false;
    }
};