class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map; 
        // <number, count>
        for (auto num : nums) {
            map[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>> pq; 
        for (auto pair : map) {
            //<count, number>
            pq.push({pair.second, pair.first});
        }

        vector<int> res; 
        while (res.size() != k) {
            res.push_back(pq.top().second); 
            pq.pop(); 
        }

        return res;
    }
};