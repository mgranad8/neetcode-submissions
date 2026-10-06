class Solution {
    public int search(int[] nums, int target) {
        //check if the array passed in is empty
        if(nums.length == 0){
            return -1;
        }

        //create the left and right endpoints
        int left = 0;
        int right = nums.length - 1;

        //search through the array to find the target while our endpoints do not
        //surpass each other
        while(left <= right){
            //calculate the middle index value
            int middle = left + (right - left) / 2;

            //check if the middle index element has the target value
            if(nums[middle] == target){
                //if the element is the target then we return the middle value(index)
                return middle;
            }

            //otherwise we adjust our window
            if(nums[middle] > target){
                //the current middle element is too big to be our target value so we look to the left
                right = middle - 1;
            }

            if(nums[middle] < target){
                //the current middle element is too small to be our target value so we look to the right
                left = middle + 1;
            }
        }

        return -1; //if we reach the end then the element does not exist
    }
}
