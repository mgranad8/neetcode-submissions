class Solution {
    public int[] twoSum(int[] nums, int target) {
        //check if the array passed in is empty
        if(nums.length == 0){
            //return an empty array
            int[] none = {0};
            return none;
        }

        //declare a new array and hash map to store the values
        int[] idx = new int[2];
        HashMap<Integer, Integer> myMap = new HashMap<>(); //store pairs as (element, index)

        //loop through the array
        for(int i = 0; i < nums.length; i++){
            //find the difference between the target and current index value
            int diff = target - nums[i];

            //check if the difference is already in the map
            if(myMap.containsKey(diff)){
                //if the difference is already stored, then we can call it and store the value at that key and the current index
                idx[0] = myMap.get(diff);
                idx[1] = i;
            }

            //otherwise, store the current element and it's index in the map to check we have already seen it
            myMap.put(nums[i], i);
        }

        //return the array
        return idx;
    }
}
