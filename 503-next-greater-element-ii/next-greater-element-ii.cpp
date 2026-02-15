class Solution {
public:
    void solve(stack<int>& st, vector<int>& nums, vector<int>& ans){
        
        int n = nums.size();
        
        for(int i = 2*n - 1; i >= 0; i--){
            
            int element = nums[i % n];
            
            while(!st.empty() && st.top() <= element){
                st.pop();
            }
            
            if(i < n){  
                if(st.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(st.top());
                }
            }
            
            st.push(element);
        }
        
        reverse(ans.begin(), ans.end());
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> st;
        vector<int> ans;
        
        solve(st, nums, ans);
        
        return ans;
    }
};
