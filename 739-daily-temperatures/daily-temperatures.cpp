class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>res(temperatures.size() , 0);
        stack<int>st;
        for(int i=0 ; i<temperatures.size() ; i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                int temp = st.top();
                st.pop();
                res[temp] = i - temp;
            }
            st.push(i);
        }
        return res;
    }
};