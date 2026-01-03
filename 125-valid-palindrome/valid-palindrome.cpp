class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); }), s.end());
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return tolower(c); });
        int i = 0;
        int j = s.length()-1;
        while(i<=j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};