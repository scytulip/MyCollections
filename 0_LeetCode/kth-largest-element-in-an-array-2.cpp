class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return QuickSelect(nums, 0, nums.size()-1, k);
    }
private:
    int QuickSelect(vector<int>& nums, const int& l, const int& r, const int& k) {
        if (l==r) return nums[l];

        int pivot = nums[l];
        int i = l;
        int j = r;

        while(i<j) {
            while(i<j && nums[j]<=pivot) --j;
            if (i<j) nums[i++] = nums[j];
            while(i<j && nums[i]>pivot) ++i;
            if (i<j) nums[j--] = nums[i];
        }
        nums[i] = pivot;

        if (i==k-1)
            return nums[i];
        else if (i>k-1)
            return QuickSelect(nums, l, i-1, k);
        else
            return QuickSelect(nums, i+1, r, k);
    }
};