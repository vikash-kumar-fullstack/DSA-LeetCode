class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        freq={}
        for i,x in enumerate(nums):
            if x in freq and abs(freq[x]-i)<=k:
                return True
            freq[x]=i
        return False       