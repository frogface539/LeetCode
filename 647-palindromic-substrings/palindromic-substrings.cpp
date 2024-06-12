class Solution {
public:
    int moveAroundIndex(string s , int i , int j ){
        int count = 0;
        while(i>=0 && j < s.length() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int count = 0;
        for(int i=0 ; i<s.length() ; i++){
            int evenAns = moveAroundIndex(s , i , i+1);
            count = evenAns + count;

            int oddAns = moveAroundIndex(s , i , i);
            count = oddAns + count;
        }
        return count;
    }
};