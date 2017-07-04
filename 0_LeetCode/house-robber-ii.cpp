class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size()==1) return nums[0];
        
        int n = nums.size();
        // 0 - steal, 1 - no
        vector<int> cost(2,0);
        vector<int> new_cost(2,0);
        cost[0] = nums[0];
        for (int i=1; i<n-1; ++i) {
            new_cost[0] = cost[1] + nums[i];
            new_cost[1] = max(cost[0], cost[1]);
            cost = new_cost;
        }
        int v1 = max(cost[0], cost[1]);
        
        fill(cost.begin(), cost.end(), 0);
        cost[0] = nums[1];
        for (int i=2; i<n; ++i) {
            new_cost[0] = cost[1] + nums[i];
            new_cost[1] = max(cost[0], cost[1]);
            cost = new_cost;
        }
        int v2 = max(cost[0], cost[1]);
        
        return max(v1, v2);
    }
};