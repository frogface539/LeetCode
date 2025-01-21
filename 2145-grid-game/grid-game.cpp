class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long robot1Sum = accumulate(begin(grid[0]) , end(grid[0]) , 0LL);
        long long robot2Sum = 0;
        long long miniRobo2Sum = LONG_LONG_MAX;

        for(int i=0 ; i<grid[0].size() ; i++){
            robot1Sum = robot1Sum - grid[0][i];
            long long robo2 = max(robot1Sum,robot2Sum);
            miniRobo2Sum = min(miniRobo2Sum , robo2);
            robot2Sum = robot2Sum + grid[1][i];
        }
        return miniRobo2Sum;
    }
};