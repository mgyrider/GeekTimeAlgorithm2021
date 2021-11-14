class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int, int>> dp(nums.size());
        int maxLen = 1;
        int ans = 0;
        dp[0].first = 1;
        dp[0].second = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int tempLen = 0;
            // 寻找 max(dp[j])，j 从 0 到 i - 1
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    tempLen = max(tempLen, dp[j].first);
                }
            }
            // 计算最长递增子序列长度等于 tempLen 的个数
            int count = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && dp[j].first == tempLen) {
                    count += dp[j].second;
                }
            }
            dp[i].first = tempLen + 1;
            dp[i].second = max(count, 1);
            maxLen = max(maxLen, dp[i].first);
        }
        // 最后统计一把答案
        for (auto &temp : dp) {
            if (temp.first == maxLen) {
                ans += temp.second;
            }
        }
        return ans;
    }
};