class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row_pos = 0;
        int col_pos = n - 1;
        while (row_pos < m && col_pos >= 0) {
            int val = matrix[row_pos][col_pos];
            if (target > val) {
                row_pos += 1;
            } else if (target < val) {
                col_pos -= 1;
            } else {
                return true;
            }
        }
        return false;
    }
};