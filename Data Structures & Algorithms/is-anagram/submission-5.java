class Solution {
    public boolean isAnagram(String s, String t) {
        //check if the 2 strings passed in are anagrams(contain the same chars and same amount of char frequencies)
        //return true if they are an anagram or false otherwise
        
        //check if the strings passed in are the same length or empty
        if(s.length() != t.length() || s.equals("") || t.equals("")){
            //should return false since the strings are either not the same length or empty
        }

        //declare a hashmap to store the chars and their integer
        HashMap<Character, Integer> map = new HashMap<>();
        HashMap<Character, Integer> map2 = new HashMap<>();

        //upload the characters to their respective map
        for(int i = 0; i < s.length(); i++){
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1); //upload the char and increase the count to make sure we are keeping track of how many times we have seen this char
        }
        for(int i = 0; i < t.length(); i++){
            map2.put(t.charAt(i), map2.getOrDefault(t.charAt(i), 0) + 1);
        }

        //check if the maps equal each other which means they contain the same chars and the number of frequencies
        return map.equals(map2);
    }
}
