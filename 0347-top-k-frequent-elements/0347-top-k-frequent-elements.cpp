class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m; 
        for (const int num : nums) {
            m[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        for (auto pair : m) {
            // the order switch is probably what provides key to heap  
            pq.push({pair.second, pair.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res; 
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().second);
            pq.pop();  
        }
        return res; 
    }
};