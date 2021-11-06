
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 100000;
        int right = 0;
        for (auto w : weights) {
            left = min(left, w);
            right += w;
        }
        int ans = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            int temp = getDays(weights, mid, days);
            if (temp > days) {
                /* 增大载重 */
                left = mid + 1;
            } else if (temp == days) {
                ans = min(mid, ans);
                right = mid - 1;
            } else {
                /* 减小载重 */
                ans = min(ans, mid);
                right = mid - 1;
            }
        }
        return ans;
    }
    int getDays(vector<int>& weights, int cap, int maxDays) {
        int sum = 0;
        int days = 0;
        for (int i = 0; i <weights.size(); ++i) {
            if (weights[i] > cap) {
                return maxDays + 1;
            }
            if (sum + weights[i] > cap) {
                days += 1;
                sum = weights[i];
            } else {
                sum += weights[i];
            }
        }
        days += 1;
        return days;
    }
};