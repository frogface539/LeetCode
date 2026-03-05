class Solution {
    public int myAtoi(String s) {
        char[] stringy = s.toCharArray();
        int result = 0;
        int i = 0;
        int flag = 1;
        if(s.length() == 0) return result;
        for(; i<stringy.length; i++){
            if(stringy[i] == ' ') continue;
            else break;
        }
        if(i < s.length() && (stringy[i] == '-' || stringy[i] == '+')){
            if (stringy[i] == '-') flag = -1;
            i++;
        }
        for(;i<stringy.length;i++){
            if(Character.isLetter(stringy[i])) break;
            else if(stringy[i] == '+' || stringy[i] == '-' || stringy[i] == '.') break;
            else if(stringy[i] == ' ') break;
            else{
                if((result > 214748364) || ((result == 214748364) && stringy[i] - '0' > 7)){
                    if (flag == -1) return Integer.MIN_VALUE;
                    else return Integer.MAX_VALUE;
                }
                result = result * 10 + stringy[i] - '0';
            }
        }

        return result * flag;
    }
}