class Solution {
public:
    bool detectCapitalUse(string word) {
        int small = 0;
        int capital = 0;

        for(char c: word){
            if(islower(c)) {
                small++;
            }
            else {
                capital++;
            }
        }

        if(capital==word.size()||small==word.size()|| isupper(word[0])&&small== word.size()-1) return true;

        return false;
    }
};