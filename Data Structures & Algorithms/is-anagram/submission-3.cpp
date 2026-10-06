class Solution {
public:
    bool isAnagram(string s, string t) {
        //given two strings, return true if the strings are anagrams of each other (contain the same char)
        //contain only lowercase English letters

        //check if the two strings are the same length
        if(s.length() != t.length() || s.length() == NULL || t.length() == NULL){
            //if they are not the same length or are empty then they are not an anagram, so we return false
            return false;
        }

        //declare a hashmap to store the chars and their index (char, index)
        unordered_map<char, int> map;
        unordered_map<char, int> map2;

        //upload the chars of the first string into the map for comparison
        for(int i = 0; i < s.length(); i++){
            map[s[i]]++;
        }

        //loop again and upload the chars in the second string to the map
        for(int i = 0; i < t.length(); i++){
            map2[t[i]]++;
        }

        //return T/F if the maps consist of the same chars and same frequency of chars
        return map == map2;
    }
};
