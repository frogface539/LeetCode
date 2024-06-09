class Solution {
public:
    string reverseWords(string s) {
        int lastSpace = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                reverse(s.begin()+lastSpace, s.begin()+i);
                lastSpace = i+1;
            }
        }

        reverse(s.begin()+lastSpace, s.end());
        return s;
    }
};