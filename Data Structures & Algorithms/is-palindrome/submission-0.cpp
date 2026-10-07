class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0){
            return false;
        }

        //otherwise intialize two pointers
        int left = 0; //start at the beginning of the string
        int right = s.length() - 1; //located at the end

        //progressively move the pointers toward each other
        while(left < right){
            //while the pointers do not equal each other we compare
            while(left < right &&  !isalnum(static_cast<unsigned char>(s[left]))){
                //skip non-alphanumeric characters from the left
                left++;
            }

            while(left < right && !isalnum(static_cast<unsigned char>(s[right]))){
                //skip non-alphanumeric characters from the right
                right--;
            }

            //the pointers are now at alphnumeric chars
            //compare case-insensitively
            if(tolower(static_cast<unsigned char>(s[left])) != tolower(static_cast<unsigned char>(s[right]))){
                //the chars do not match
                return false;
            }

            left++;
            right--;
        }

        return true; //all chars are equal to each other
    }
};
