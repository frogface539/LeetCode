class Solution {
public:
    string toLowerCase(string s) {
        string newString = "";
        for(int i=0 ; i<s.size() ; i++){
            newString = newString + (char) tolower(s[i]);
        }
        return newString;
    }
};