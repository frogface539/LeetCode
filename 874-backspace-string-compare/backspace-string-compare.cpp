class Solution {
public:
    string build(string s){
        stack<char>st;
        string res;

        for(int i=0 ; i<s.length() ; i++){
            if(s[i] == '#'){
                if(!st.empty())
                    st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }

    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};