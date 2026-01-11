class Solution {
public:
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        string vowel = "aeiouAEIOU";

        while(i<=j){
            if(vowel.find(s[i]) == string :: npos){
                i++;
            }
            else if(vowel.find(s[j]) == string :: npos){
                j--;
            }
            else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};