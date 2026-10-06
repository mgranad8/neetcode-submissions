class Solution {
    public boolean hasDuplicate(int[] nums) {
        //function should check if any elements repeat
        //return true if they repeat; otherwise return false

        //check if the array passed in is empty
        if(nums.length == 0){
            //return false, since there are no elements
            return false;
        }

        //declare a hashmap to store the elements and their indexes (element, index)
        HashMap<Integer, Integer> myMap = new HashMap<>();

        //loop through the array
        for(int i = 0; i < nums.length; i++){
            //check if we have already seen this element
            if(myMap.containsKey(nums[i])){
                //if we have already seen this element, then we know this is a duplicate so we return true
                return true;
            }

            //otherwise, add the element and it's index to the map to check that we have already seen it
            myMap.put(nums[i], i);
        }

        //if we reach the end of the loop, then we know there are no duplicates so we return false
        return false;
    }
}