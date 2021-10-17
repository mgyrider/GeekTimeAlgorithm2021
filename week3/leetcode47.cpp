class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->vis = vector<int>(nums.size(), 0);
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(temp, nums);
        return ans;
    }
    void dfs(vector<int>& temp, vector<int>& nums) {
        int last = -1;
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i] != 0 || (last != -1 && nums[i] == nums[last])) {
                continue; // 跳过已被选过的数，如果当前选的数和上一次选的数一样，也跳过
            }
            vis[i] = 1; // 标记这个数已被选过
            temp.push_back(nums[i]);
            dfs(temp, nums);
            last = i;
            temp.pop_back();
            vis[i] = 0;
        }
    }
private:
    vector<int> vis;
    vector<vector<int>> ans;
};