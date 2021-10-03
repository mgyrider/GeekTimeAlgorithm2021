class Rect {
public:
    Rect (int a, int b) : w(a), h(b) {

    }
    int w;
    int h;
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 维护一个单调递增的单调栈，当单调性被破坏时，逐个弹出并计算矩形面积，更新最大矩形面积
        heights.push_back(0);
        int ans = 0;
        vec.clear();
        for (int h : heights) {
            int totalWidth = 0;
            while (!vec.empty() && vec.back().h >= h) {
                int tempH = vec.back().h;
                totalWidth += vec.back().w; // 累计打到右边的宽度
                ans = max(tempH * totalWidth, ans);
                vec.pop_back();
            }
            vec.push_back(Rect(totalWidth + 1, h));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) {
            return 0;
        }
        int cols = matrix[0].size();
        vector<int> vec(cols, 0);
        int ans = 0;
        /*
         * 思路：把第0行到第1行看成柱状图，转换为"柱状图中最大矩形"的问题
         */
        for (int i = 0; i < rows; ++i) {
            vector<char> &temp = matrix[i];
            for (int j = 0; j < temp.size(); ++j) {
                if (temp[j] == '1') {
                    vec[j] += 1;
                } else {
                    vec[j] = 0;
                }
            }
            int tempAns = largestRectangleArea(vec);
            ans = max(ans, tempAns);
        }
        return ans;
    }
private:
    vector<Rect> vec;
};