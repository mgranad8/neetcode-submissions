class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //go through the array and check to see if the value repeats
        //if the value repeats more than once, return true; otherwise return false

        //check if the array is empty
        if(nums.empty()){
            //return false since there is nothing and no duplicates
            return false;
        }


        //create a map that stores the values we have already seen (element, idx)
        unordered_map<int, int> map;

        //loop through the array
        for(size_t i = 0; i < nums.size(); i++){
            //check if we have already seen this element
            if(map.count(nums[i])){
                //if we have already seen this, then we know it's a duplicate so we return true
                return true;
            }

            //otherwise, we add it to map to say we have already seen it
            map[nums[i]] = i;
        }
        
        //if we reach here, then there must be no duplicates so we return false
        return false;
    }
};