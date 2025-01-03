class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map; 
        for (auto s : strs) {
            vector<int> count(26,0);
            for (auto c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key = key + "," + to_string(count[i]);
            }
            map[key].push_back(s);
        }
        vector<vector<string>> res; 
        for (auto pair : map) {
            res.push_back(pair.second);
        }
        return res; 
    }
};