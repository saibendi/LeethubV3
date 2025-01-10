class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> map1; 
        for (auto c : s1) {
            map1[c]++;
        }
        int window_length = s1.size(); 
        int start_idx = 0;
        unordered_map<char,int> map2; 
        for (int i = 0; i < s2.size(); ++i) {
            map2[s2[i]]++;
            if (i - start_idx + 1 == window_length) {
                if (map2 == map1) {
                    return true;
                }
                else {
                    map2[s2[start_idx]] == 1 ? map2.erase(s2[start_idx]) : map2[s2[start_idx]]--;
                    ++start_idx;
                }
            }
        }
        return false;
    }
};