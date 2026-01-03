class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for(int i=0 ; i<s.length() ; i++){
            char currChar = s[i];
            if(ans.empty() || currChar != ans.back()){
                ans.push_back(currChar);
            }
            else if(currChar == ans.back()){
                ans.pop_back();
            }
        }
        return ans;
    }
};