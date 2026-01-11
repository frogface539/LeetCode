class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int n = s.size();
        string Answer = "";
        int cycleLen = 2 * numRows - 2; 

        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < n; j += cycleLen) {
                Answer += s[j];
                if (i != 0 && i != numRows - 1) {
                    int diagonalIndex = j + cycleLen - 2 * i;
                    if (diagonalIndex < n) {
                        Answer += s[diagonalIndex];
                    }
                }
            }
        }
        return Answer;
    }
};