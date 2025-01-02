class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m; 
        for (auto num : nums) {
            m[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto pair : m) {
            buckets[pair.second].push_back(pair.first);
        }

        vector<int> res; 
        for (int i = nums.size(); i > 0; --i) {
            for (auto val : buckets[i]) {
                res.push_back(val); 
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};