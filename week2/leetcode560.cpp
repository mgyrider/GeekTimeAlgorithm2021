class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> preSum(nums.size() + 1, 0);
        unordered_map<int, int> counts;
        counts[0] = 1;
        // 计算前缀和
        int ans = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
            // 当前前缀和减去k，看历史是否有这样的结果
            int temp = preSum[i] - k;
            if (counts.find(temp) != counts.end()) {
                ans += counts[temp];
            }
            counts[preSum[i]] += 1;
        }
        return ans;
    }
};