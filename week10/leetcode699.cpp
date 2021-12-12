class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> xPos;
        /* 坐标离散化 */
        for (auto& temp : positions) {
            xPos.push_back(temp[0]);
            xPos.push_back(temp[0] + temp[1] - 1);
        }
        sort(xPos.begin(), xPos.end());
        for (int i = 0; i < xPos.size(); ++i) {
            posHash[xPos[i]] = i;
        }
        n = xPos.size() * 4;
        vec = vector<Node>(n);
        /* 建树 */
        buildTree(1, 0, xPos.size() - 1);
        vector<int> ans;
        for (auto& temp : positions) {
            int leftHash = posHash[temp[0]];
            int rightHash = posHash[temp[0] + temp[1] - 1];
            /* 查询该区间的最高高度 */
            int curHight = query(1, leftHash, rightHash);
            /* 更新该区间的最高高度 */
            update(1, leftHash, rightHash, curHight + temp[1]);
            ans.push_back(vec[1].data);
        }
        return ans;
    }
private:
    int n;
    class Node {
    public:
        int left;
        int right;
        int data;
    };
    vector<Node> vec;
    map<int, int> posHash;
    void buildTree(int index, int left, int right) {
        if (index >= n) {
            return;
        }
        int mid = (left + right) / 2;
        vec[index].left = left;
        vec[index].right = right;
        vec[index].data = 0;
        if (left == right) {
            return;
        }
        buildTree(index * 2, left, mid);
        buildTree(index * 2 + 1, mid + 1, right);
        return;
    }
    void update(int index, int left, int right, int data) {
        if (right < vec[index].left || left > vec[index].right) {
            return;
        }
        if (vec[index].left == vec[index].right) {
            vec[index].data = data;
            return;
        }
        update(index * 2, left, right, data);
        update(index * 2 + 1, left, right, data);
        vec[index].data = max(vec[index * 2].data, vec[index * 2 + 1].data);
        return;
    }
    int query(int index, int left, int right) {
        if (vec[index].left >= left && vec[index].right <= right) {
            return vec[index].data;
        }
        if (right < vec[index].left || left > vec[index].right) {
            return 0;
        }
        int v1 = query(index * 2, left, right);
        int v2 = query(index * 2 + 1, left, right);
        return max(v1, v2);
    }
};