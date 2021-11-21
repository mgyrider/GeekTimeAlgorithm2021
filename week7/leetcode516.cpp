class Solution {
public:
    int longestPalindromeSubseq(string s) {
        /* 如果 s[i] == s[j]，dp[i][j] = dp[i + 1][j - 1] + 2
            否则 dp[i][j] = max(dp[i][j - 1]，dp[i + 1][j]) */
        int len = s.size();
        dp = vector<vector<int>>(len, vector<int>(len, -1));
        for (int i = 0; i < len; ++i) {
            dp[i][i] = 1;
        }
    
        return find(s, 0, len - 1);
    }
private:
    vector<vector<int>> dp;
    int find(string& s, int left, int right) {
        if (left > right) {
            return 0;
        }
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        if (s[left] == s[right]) {
            dp[left][right] = find(s, left + 1, right - 1) + 2;
        } else {
            int val2 = find(s, left, right - 1);
            int val1 = find(s, left + 1, right);
            dp[left][right] = max(val1, val2);
        }
        return dp[left][right];
    }
};