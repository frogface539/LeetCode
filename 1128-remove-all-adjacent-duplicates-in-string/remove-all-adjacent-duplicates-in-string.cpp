class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i=0 ; i<s.size() ; i++){
            char element = s[i];

            if(!st.empty() && st.top() == element){
                st.pop();
            }
            else{
                st.push(element);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};