class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        rd_val = []
        for i in range(0, len(nums)):
            rd_val.append(1)
        for i in range(1, len(nums)):
            rd_val[i] = rd_val[i-1] * nums[i-1]
        temp = 1;
        for i in range(len(nums)-2, -1, -1):
            temp = temp * nums[i+1]
            rd_val[i] = rd_val[i] * temp
        return rd_val
