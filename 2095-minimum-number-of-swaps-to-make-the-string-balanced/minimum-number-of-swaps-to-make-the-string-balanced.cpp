class Solution {
public:
    int minSwaps(string s) {
        if(s.size() & 1){
            return -1;
        }

        stack<char>st;
        for(auto ch:s){
            if(ch == '['){
                st.push(ch);
            }

            else{
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        
        int unmatched = st.size();
        return (unmatched / 2 + 1) / 2;
    }
};