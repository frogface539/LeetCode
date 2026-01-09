class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int currentWidth = 0;
        int currentCount = 0;
        int k = 0;
        int n = words.size();
        int currentRemain = maxWidth;
        for (int i = 0; i < words.size(); i++) {
            if (static_cast<int>(words[i].size()) > currentRemain) {
                int gapWidth = maxWidth - currentWidth;
                int evenGap = 0, remainder = 0;
                if (currentCount == 1) {
                     evenGap = gapWidth;
                } else {
                    evenGap = gapWidth / (currentCount - 1);
                    remainder = gapWidth % (currentCount - 1);
                }
                string whiteGap(evenGap, ' ');
                string str;

                for (int j = k; j < i; j++) {
                    str += words[j];
                    if (remainder-- > 0) {
                        str += ' ';
                    }
                    if (j != i - 1) {
                        str += whiteGap;
                    }
                }
                if (currentCount == 1) {
                    str += whiteGap;
                }
                res.push_back(str);
                k = i;
                currentRemain = maxWidth;
                currentWidth = 0;
                currentCount = 0;
            }

            currentWidth += words[i].length();
            currentCount++;
            currentRemain -= words[i].length();
            currentRemain--;
        }
        if (currentCount > 0) {
            string str;
            for (int i = n - currentCount; i < n; i++) {
                str += words[i];
                if (str.size() < maxWidth) {
                    str += ' ';
                }
            }
            string whiteGap(maxWidth - str.size(), ' ');
            str += whiteGap;
            res.push_back(str);
        }

        return res;
    }
};