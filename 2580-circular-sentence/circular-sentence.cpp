class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence.back() != sentence[0]){
            return false;
        }

        int i = 0;
        while(i < sentence.size()){
            while(i<sentence.size() && sentence[i] != ' '){
                i++;
            }
            if(i<sentence.size() && sentence[i-1] != sentence[i+1]){
                return false;
            }
            i++;
        }
        return true;
    }
};