class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int r = matrix.size(), c = matrix[0].size();
        int ct = 0;
        ct = count(matrix[0].begin(), matrix[0].end(), 1);
        for (int i = 1; i < r; i++){
            ct += matrix[i][0];
        }
        for (int i = 1; i < r; i++){
            for (int j = 1; j < c; j++){
                if (matrix[i][j] == 0){
                    continue;
                }
                matrix[i][j] = min(matrix[i-1][j], min(matrix[i-1][j-1], matrix[i][j-1])) + 1;
                ct+= matrix[i][j];
            }
        }
        return ct;
    }
};
