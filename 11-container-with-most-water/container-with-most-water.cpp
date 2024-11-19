class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int s = 0;
        int e = height.size() - 1;
        while(s<e){
            int width = e-s;
            int heights = min(height[s] , height[e]);
            int area = heights * width;
            ans = max(ans , area);

            if(height[s] > height[e]){
                e--;
            }
            else{
                s++;
            }
        }
        return ans;
    }
};