class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // <sorted letters -> anagrams>
        unordered_map<string,vector<string>> map;
        for (auto str : strs) {
            const string unalteredStr = str;
            sort(str.begin(), str.end());
            // if sorted word doesn't already exist in map, add
            // if (!map.count(str)) {
                map[str].push_back(unalteredStr);
            // // }
            // else {
            //     map[str].push_back(unalteredStr);
            // }
        }

        vector<vector<string>> res; 
        for (auto pair : map) {
            res.push_back(pair.second);
        }
        return res; 
    }
};