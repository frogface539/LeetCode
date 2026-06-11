class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& arr) {
        int n = arr.size();
        unordered_map<int,bool>visited;
        queue<int>q;
        q.push(0);
        visited[0] = true;
        int count = 1;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto& i:arr[front]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                    count++;
                }
            }
        }
        return count==n;
    }
};