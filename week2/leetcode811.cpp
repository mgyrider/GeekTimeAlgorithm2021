class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> vis;
        stringstream ss;
        vector<string> ans;
        for (string &temp : cpdomains) {
            ss.clear();
            ss << temp;
            int count;
            string name;
            ss >> count;
            ss >> name;
            for (int i = name.size() - 1; i >= 0; --i) {
                if (name[i] == '.') {
                    string s = name.substr(i + 1, name.size() - 1 - i);
                    vis[s] += count;
                }
            }
            vis[name] += count;
        }
        for (auto it = vis.begin(); it != vis.end(); it++) {
            ss.clear();
            ss.str("");
            ss << it->second << " " << it->first;
            ans.push_back(ss.str());
        }
        return ans;
    }
};