class Solution {
public:
    string digitSum(string s, int k) {

        while(s.size() > k) {

            string ans = "";
            int i = 0, j = 0;

            while(j < s.size()) {

                if(j-i+1 < k) {
                    j++;
                }
                else if(j-i+1 == k) {

                    int sum = 0;

                    for(int x = i; x <= j; x++) {
                        sum += s[x] - '0';
                    }

                    ans += to_string(sum);

                    i = j + 1;
                    j = i;
                }
            }

            // Process the remaining digits
            if(i < s.size()) {
                int sum = 0;

                for(int x = i; x < s.size(); x++) {
                    sum += s[x] - '0';
                }

                ans += to_string(sum);
            }

            s = ans;
        }

        return s;
    }
};