class Solution {
public:
    vector<int> nextSmaller(vector<int>& arr){
        stack<int> st;
        st.push(-1);
        vector<int> ans(arr.size(), -1);

        for(int i = arr.size() - 1; i >= 0; i--){
            while(st.top() != -1 && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int>& arr){
        stack<int> st;
        st.push(-1);
        vector<int> ans(arr.size(), -1);

        for(int i = 0; i < arr.size(); i++){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        auto next = nextSmaller(arr);
        auto prev = prevSmaller(arr);

        long long sum = 0;
        const int mod = 1e9 + 7;

        for(int i = 0; i < arr.size(); i++){
            int nexti = (next[i] == -1) ? arr.size() : next[i];
            int previ = prev[i];

            long long left = i - previ;
            long long right = nexti - i;

            long long contribution =
                (arr[i] * left % mod * right % mod) % mod;

            sum = (sum + contribution) % mod;
        }

        return sum;
    }
};
