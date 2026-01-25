class Solution {
public:
    bool validSub(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
        unordered_set<char> st;
        for(int row = sr; row<=er; row++) {
            for(int col = sc; col <= ec; col++) {
                char ch = board[row][col];
                if(ch == '.') {
                    continue;
                }
                if(st.count(ch)){
                    return false;
                }
                st.insert(ch);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0 ; i<9 ; i++){
            unordered_set<int>st;
            for(int j=0 ; j<9 ; j++){
                char ch = board[i][j];
                if(ch == '.'){
                    continue;
                }
                if(st.count(ch)){
                    return false;
                }
                st.insert(ch);
            }
        }

        for(int i=0 ; i<9 ; i++){
            unordered_set<int>st;
            for(int j=0 ; j<9 ; j++){
                char ch = board[j][i];
                if(ch == '.'){
                    continue;
                }
                if(st.count(ch)){
                    return false;
                }
                st.insert(ch);
            }
        }

        for(int sr = 0; sr < 9; sr+=3) {
            int er = sr+2;
            for(int sc = 0; sc < 9; sc+=3) {
                int ec = sc+2;
                if(!validSub(board, sr, er, sc, ec)){
                    return false;
                }
            }
        }
        return true;
    }
};