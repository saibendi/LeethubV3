class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res; 
        unordered_map<int,int> m; // value : index
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (m.count(diff)) {
                return res = {m[diff], i};
            }
            else {
                m[nums[i]] = i;
            }
        } 

        return res; 
    }
};