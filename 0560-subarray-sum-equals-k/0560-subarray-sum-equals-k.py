class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        total=0
        prefix_sum=0
        trace={0:1}
        for x in nums:
            prefix_sum+=x

            if prefix_sum-k in trace:
                total+=trace[prefix_sum-k]
            trace[prefix_sum]=trace.get(prefix_sum,0)+1
        return total