class Num {
public:
    int data;
    int index;
    Num(int a, int b) : data(a), index(b) {

    }
};

bool operator<(Num a, Num b)
{
    return a.data < b.data;
}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<Num> que;
        for (int i = 0; i < nums.size(); ++i) {
            que.push(Num(nums[i], i));
            if (i >= k - 1) {
                /* 懒惰删除 */
                while (que.top().index < i - k + 1) {
                    que.pop();
                }
                ans.push_back(que.top().data);
            }
        }
        return ans;
    }
};