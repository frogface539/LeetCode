#include <string>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        bool negative = num < 0;
        num = abs(num);
        string res = "";
        while(num > 0){
            res = char('0' + num % 7) + res;
            num /= 7;
        }
        if(negative) res = "-" + res;
        return res;
    }
};