class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>>height(m , vector<int>(n , -1));
        vector<vector<int>>directions{{1,0} , {0,1} , {-1,0} , {0,-1}};
        queue<pair<int,int>>q;

        for(int i = 0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(isWater[i][j] == 1){
                    height[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int size = q.size();

            while(size--){
                pair<int,int>front = q.front();
                q.pop();

                int i =  front.first;
                int j = front.second;

                for(auto dir : directions){
                    int a = i + dir[0];
                    int b = j + dir[1];

                    if(a>=0 && a<m && b>=0 && b<n && height[a][b] == -1){
                        height[a][b] = height[i][j] + 1;
                        q.push({a,b});
                    }
                }
            }
        }
        return height;
    }
};