class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map; 
        // bst map uses first element to order 
        for (auto num : nums) {
            map[num]++;
        }

        vector<vector<int>> buckets(nums.size()+1, vector<int>(0));
        for (auto pair : map) {
            buckets[pair.second].push_back(pair.first);
        }
        
        vector<int> res; 
        for (int i = buckets.size() - 1; i > 0; --i) {
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