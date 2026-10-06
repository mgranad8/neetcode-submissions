class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        #parse through the list to find duplicates
        #if a duplicate exists, return true; otherwise return false
        
        #check if the list is empty
        if not nums:
            #return false since there are technically no repeating values
            return False
        
        #declare a dictionary to store the elements and their indexes (element, index)
        hashMap = {}
        
        #loop through the list
        for i in range(len(nums)):
            #check if the current element is already in the hashmap
            if hashMap.get(nums[i]) is not None:
                #if we have already seen this element, then we know there is a duplicate so we return true
                return True
            
            #otherwise, add the current element and it's index
            hashMap[nums[i]] = i
        
        #if we reached the end, then we know there are no duplicates so we return false
        return False