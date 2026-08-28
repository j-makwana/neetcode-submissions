class NumMatrix {
   private:
    vector<vector<int>> prefixSum;

   public:
    NumMatrix(vector<vector<int>>& matrix)
        : prefixSum(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0)) {
        // need to initialzie prefixSum array her
        for (int i = 1; i < matrix.size() + 1; i++) {
            for (int j = 1; j < matrix[0].size()+1; j++) {
                int temp_sum = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] +
                               matrix[i-1][j-1];
                prefixSum[i][j] = temp_sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // summing the region
        // need to sum right - sum left
        // need to check the values are in bound
        int res = 0;
        res = prefixSum[row2+1][col2+1] - prefixSum[row1][col2+1] - prefixSum[row2+1][col1] +
              prefixSum[row1][col1];

        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */