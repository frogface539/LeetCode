class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();

        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0){
            return 0;
        }
        long long sum = grid[i][j];
        grid[i][j] = 0;
        sum += dfs(grid,i+1,j);
        sum += dfs(grid,i,j+1);
        sum += dfs(grid,i-1,j);
        sum += dfs(grid,i,j-1);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j] > 0){
                    long long sum = dfs(grid,i,j);
                    if(sum % k == 0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};