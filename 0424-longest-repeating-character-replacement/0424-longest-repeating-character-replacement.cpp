class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> map; 
        int start_idx = 0; int maxFreq = 0;
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            map[s[i]]++;
            maxFreq = max(map[s[i]], maxFreq);

            int windowLength = i - start_idx + 1;
            if (windowLength - maxFreq <= k) {
                res = max(res,windowLength);
            }
            else {
                map[s[start_idx]]--;
                start_idx++;
            }
        }
        return res;
    }
};