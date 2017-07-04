class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto& i : nums) ++map[i];
        
        auto compare =
            [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;
            };
        
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       decltype(compare)> queue(compare);
        for (const auto& p : map) queue.push(p);
        
        vector<int> val(k, 0);
        for (int i=0; i<k; ++i) {
            val[i] = queue.top().first;
            queue.pop();
        }
        
        return val;
    }
};