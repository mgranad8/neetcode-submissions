class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        Given an array of strings, the task is to group all anagrams together into a sublist
        and return that sublist. The order of the array returned does not matter. An anagram is
        a string that contains the exact same characters as another string, but the order of the characters
        can be different. Input length is between 1 and 1000 where the element has a length of anywhere
        between 0 and 100 and the element is made up of lowercase English letters.
        */

        /*
        Initial thoughts:
        -I can iterate through every element and check that each element's letters are loaded in and
        remembered. I could use a hashmap to store the element as the key and the chars as the values.
        When I go through each element I check to see if ALL the characters being read have already been
        logged into the map. Making sure that the algorithm doesn't automatically check it off when only
        ONE char has already been seen.

        New thoughts:
        -The idea of parsing through each char is too complex of an algorithm to create and have received
        some tips by Claude AI to approach this differently. A trick regrading anagrams is that, when the 
        chars are sorted, they produce the same word. For example, "act", "tac", "cat", all produce "act"
        when sorted. So now I will go through each element and sort them, once the sorting is done, I will
        store them in a hashmap where the key = the sorted string and the value is a vector<string> that
        will contain the orignal elements
        */

        //check to see if the array passed in is empty
        if(strs.empty()){
            //if the array passed in is empty, then return an empty array
            vector<vector<string>> none;
            return none;
        }

        //otherwise we can parse through the array passed in
        vector<vector<string>> sublist; // variable to store a list of the sublists created
        unordered_map<string, vector<string>> letters; //hashmap to store the word and its characters

        //go through the array and store the data in the map
        for(size_t i = 0; i < strs.size(); i++){
            //load the element into the map
            //acquire the current element and load it into a string
            string curr = strs[i];

            //sort the current element
            sort(curr.begin(), curr.end());

            //add these values into the map where the key is the sorted string and the value is the original
            //string
            letters[curr].push_back(strs[i]);
        }

        //store the values of the map into an array
        for(const auto& pair:letters){
            sublist.push_back(pair.second);
        }

        //return the array
        return sublist;
    }
};