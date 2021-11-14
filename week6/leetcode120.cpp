class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len;
        vector<vector<int>> dp = triangle;
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            len = triangle[i].size();
            //dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j]
            for (int j = 0; j < len; ++j) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j];
                } else if (j == len - 1) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]);
                }
                dp[i][j] += triangle[i][j];
            }
        }
        auto& temp = dp.back();
        int ans = temp[0];
        for (int i = 1; i < temp.size(); ++i) {
            ans = min(ans, temp[i]);
        }
        return ans;
    }
};