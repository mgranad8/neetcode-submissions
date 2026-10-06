class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //nums = array passed in
        //target = the sum of two integers
        //function should return an array that contains the indices that contains the elements that when summed = the target
        //EVERY input has exactly one pair

        if(nums.empty()){
            //check if the array is empty
            //if so return an "empty" array
            vector<int> none = {0};
            return none;
        }

        //otherwise, parse through the array and find the indexes that contain the elements that sum to the target
        //create the vector to return
        vector<int> idx;
        unordered_map<int, int> map; //create a hashmap that stores the (element, index)
        
        //loop through the array
        for(size_t i = 0; i < nums.size(); i++){
            //find the difference of the target and current element
            int comp = target - nums[i];


            //check if the value is already in the map
            if(map.count(comp)){
                //if the value is in the map, store the index of the comp value in the vector and the current index
                idx.push_back(map[comp]);
                idx.push_back(i);
                break; //break the loop because we found our pair
            }

            //otherwise, store the current element and it's index in the map (element, index)
            map[nums[i]] = i;
        }

        //return the indices
        return idx;
    }
};
