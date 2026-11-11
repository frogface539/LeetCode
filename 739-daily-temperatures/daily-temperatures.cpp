class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n,0);

        for(int i=n-1 ; i>=0 ; i--){
            while(!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=0;
            }
            else{
                ans[i] = st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};