class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        bool line = false;

        for(auto&ch : s){
            if(ch == '|'){
                line = !line;
            }
            if(ch == '*' && line == false){
                count++;
            }
        }
        return count;
    }
};