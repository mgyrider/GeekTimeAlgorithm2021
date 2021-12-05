class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sHash = 0;
        int pHash = 0;
        int P = 10001;
        s = "a" + s;
        if (s.size() < p.size()) {
            return {};
        }
        for (int i = 0; i < p.size(); ++i) {
            sHash = (s[i] + sHash) % 10001;
            pHash = (p[i] + pHash) % 10001;
            countS[s[i]]++;
            countP[p[i]]++;
        }
        vector<int> ans;
        for (int i = 1; i + p.size() - 1 < s.size(); ++i) {
            sHash = ((sHash - s[i - 1]) + P) % P;
            sHash = (sHash + s[i + p.size() - 1]) % P;
            countS[s[i - 1]]--;
            countS[s[i + p.size() - 1]]++;
            if (sHash == pHash && check()) {
                ans.push_back(i - 1);
            }
        }
        return ans;
    }
private:
    map<char, int> countS;
    map<char, int> countP;
    bool check() {
        for (char c = 'a'; c <= 'z'; ++c) {
            if (countP[c] != countS[c]) {
                return false;
            }
        }
        return true;
    }
};