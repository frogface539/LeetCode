class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int firstRow = 0;
        int endRow = n-1;
        int startCol = 0;
        int endCol = n-1;

        int val = 1;
        vector<vector<int>>output(n,vector<int>(n,0));

        while(firstRow <= endRow && startCol <= endCol){
            for(int j=startCol ; j<=endCol ; j++){
                output[firstRow][j] = val;
                val++;
            }

            for(int i=firstRow + 1 ; i<=endRow ; i++){
                output[i][endCol] = val;
                val++;
            }

            for(int j=endCol-1 ; j>=startCol ; j--){
                if(firstRow == endRow){
                    break;
                }
                output[endRow][j] = val;
                val++;
            }

            for(int i=endRow-1; i>=firstRow+1; i--){
                if(startCol == endCol){
                    break;
                }
                output[i][startCol]=val;
                val++;
            }
            firstRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        return output;
    }
};