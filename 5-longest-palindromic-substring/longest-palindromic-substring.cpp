class Solution {
public:
    int start = 0;
    int maxLen = 1;

    bool solve(string& s , int i , int j){
        if(i >= j){
            return true;
        }

        bool flag = false;
        if(s[i] == s[j]){
            flag = solve(s , i+1 , j-1);
        }

        if(flag == true){
            int len = j-i+1;
            if(len > maxLen){
                maxLen = len;
                start = i;
            }
        }
        return flag;
    }

    string longestPalindrome(string s) {
         for(int i = 0 ; i<s.size() ; i++){
            for(int j=i ; j<s.size() ; j++){
                //substring check karna hai
                bool ans = solve(s , i , j);
            }
        }
        return s.substr(start , maxLen);
    }
};