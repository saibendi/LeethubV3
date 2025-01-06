class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // convert to hash map: <index, nums>
            // how does hash decide index or nums go first?
            // no ordering
        unordered_set<int> hash(nums.begin(), nums.end());
        int longest = 0; 

        for (auto num : hash) {
            // if previous elem doesn't exist, then start of sequence
            if (!hash.count(num-1)) {
                int length = 1; 
                while (hash.count(num + length)) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest; 
    }
};