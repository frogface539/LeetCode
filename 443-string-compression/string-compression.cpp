class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;

        for(int i = 0 ; i<chars.size() ; i++){
            char ch = chars[i];
            int count = 0;

            while(i < chars.size() && ch == chars[i]){
                count++;
                i++;
            }

            if(count == 1){
                chars[index] = ch;
                index++;
            }

            else{
                chars[index] = ch;
                index++;
                string counti = to_string(count);

                for(auto digi : counti){
                    chars[index] = digi;
                    index++;
                }
            }
            i--;
        }
        chars.resize(index);
        return index;
    }
};