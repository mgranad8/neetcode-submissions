class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //given an array containing integers and an integer k, the function should return the k most
        //frequent elements within the array, the array returned can be in any order

        /*
        Translation:
        -An array is passed in containing elements, parse the array to check which elements repeat.
        Keep track of which elements repeat and store them in an array to return. The value of 'k'
        tells the program the most frequent elements that appear in the array that should be returned.
        This is saying, in example 1, k = 2 and we return [2, 3] because 2 repeats twice and 3 repeats
        3 times and k = 2 so it is asking to return the top 2 frequent elements.

        Implementation:
        -First, check if the array is not empty or k > 0, if either condition is true then we return
        an empty array. I want to declare an array that will store the repeating elements. I could use
        a hashmap to store the elements and their frequencies. Then once we have parsed the array, we check
        if the frequency > 1 and if it is we add to our return array.
        */

        //check if the array passed in is empty or the k value passed in is 0
        if(nums.empty() || k <= 0){
            //create an empty array to return
            vector<int> none = {};
            return none;
        }

        //otherwise we can being to parse through the array
        vector<int> repeats; //array to store the repeating elements
        unordered_map<int, int> freq; //hashmap to store the elements and their frequency (element, freq)

        //parse through the array
        for(size_t i = 0; i < nums.size(); i++){
            //upload the data to the map
            (freq[nums[i]])++; //upload the element and update the frequency
        }

        vector<pair<int, int>> pairs; //array that will have the elements from the map stored

        //loop through the map and load the (key, value) pairs into a vector
        for(const auto& pair : freq){
            pairs.push_back({pair.first, pair.second}); //add the key and value to the vector
        }

        //using lambda, we create a custom sorting algorithm that sorts by the highest frequency
        sort(pairs.begin(), pairs.end(), [](const pair<int, int>&a, const pair<int, int>&b){
            return a.second > b.second; //sort by frequency in descending order
        });

        //extract the k most frequent elements
        for(size_t i = 0; i < k && i < pairs.size(); i++){
            repeats.push_back(pairs[i].first);
        }

        return repeats; //return the array containing the repeating elements
    }
};
