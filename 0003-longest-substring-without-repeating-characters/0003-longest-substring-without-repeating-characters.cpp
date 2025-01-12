class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // char - index
        unordered_map<char,int> map; 
        int start_idx = 0; int maxLength = 0; 
        for (int i = 0; i < s.size(); ++i) {
            // if already in the map
            if (map.count(s[i]) && start_idx <= map[s[i]]) {
                start_idx = map[s[i]] + 1;
            }
            map[s[i]] = i;
            maxLength = max(maxLength, i - start_idx + 1);
        }
        return maxLength; 
    }
};