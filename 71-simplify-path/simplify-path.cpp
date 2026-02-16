class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr;
        
        for(int i = 0; i <= path.size(); i++) {
            if(i == path.size() || path[i] == '/') {
                
                if(curr == "..") {
                    if(!st.empty()) st.pop();
                }
                else if(curr != "" && curr != ".") {
                    st.push(curr);
                }
                
                curr = "";
            }
            else {
                curr += path[i];
            }
        }
        
        if(st.empty()) return "/";
        
        string ans = "";
        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};
