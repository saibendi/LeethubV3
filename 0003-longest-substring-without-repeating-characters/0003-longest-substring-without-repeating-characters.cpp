class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map; 
        int start_idx = 0, maxLength = 0; 
        
        for (int i = 0; i < s.size(); ++i) {
            // If the character is already in the map and its index is within the current window
            if (map.count(s[i]) && map[s[i]] >= start_idx) {
                start_idx = map[s[i]] + 1; // Move the start index to the right of the last occurrence
            }
            map[s[i]] = i; // Update the character's index in the map
            maxLength = max(maxLength, i - start_idx + 1); // Calculate the length of the current substring
        
        }
        return maxLength; 
    }
};