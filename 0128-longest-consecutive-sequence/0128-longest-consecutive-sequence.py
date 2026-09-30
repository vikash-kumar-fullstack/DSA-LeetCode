class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        nums.sort()
        longest=1
        counter=1
        for i,x in enumerate(nums):
            if(i+1<len(nums)):
                if x==nums[i+1]-1:
                    counter+=1
                elif x==nums[i+1]:
                    continue
                else:
                    if longest<counter:
                        longest=counter
                    counter=1
        longest=max(longest,counter)
        return longest