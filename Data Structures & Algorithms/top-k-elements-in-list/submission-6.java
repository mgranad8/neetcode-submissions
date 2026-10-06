class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        //check that the values passed in are not empty or null
        if(nums.length == 0 || k <= 0){
            int[] none = new int[0];
            return none;
        }

        //using bucket sort to reach O(n) runtime and space complexity
        Map<Integer, Integer> count = new HashMap<>(); //hashmap to store the frequency
        List<Integer>[] freq = new List[nums.length + 1]; //creating an arraylist that will hold all elements

        for(int i = 0; i < freq.length; i++){
            /*
            At each occurrence we initialize an arraylist to store all the elements that
            occur i times. This is, at i = 4, there lies an element that has appeared 4
            times.
            */
            freq[i] = new ArrayList<>();
        }

        for(int n : nums){
            //add the element into the hashmap and update the frequency of the character
            count.put(n, count.getOrDefault(n, 0) + 1);
        }

        for(Map.Entry<Integer, Integer> entry : count.entrySet()){
            //for every key in the map we iterate through, we add the element and it's key to the arraylist
            freq[entry.getValue()].add(entry.getKey());
        }

        int[] res = new int[k]; //create a return array that stores the k most elements
        int index = 0; //value we will use to iterate through the bucket
        //loop through the bucket (arraylist)
        for(int i = freq.length - 1; i > 0 && index < k; i--){
            //at the same time loop through the elements at the index
            for(int n : freq[i]){
                res[index++] = n; //load in the element into the return array
                if(index == k){
                    //once we have loaded in the k frequent elements then we can return the array
                    return res;
                }
            }
        }

        return res; //we return the array once again?
    }
}
