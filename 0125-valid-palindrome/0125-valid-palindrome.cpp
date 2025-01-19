class Solution {
public:
    bool isPalindrome(string s) {
        //TC = O(n), SC = O(1)
        int start = 0;
        int end = s.length()-1;

        while(start <= end) {
            if(!isalnum(s[start]))  {
                start++;
                continue;// Skip the remaining code in this iteration and move to the next iteration
            }
            if(!isalnum(s[end]))  {
                end--;
                continue;
            }
            if(tolower(s[start]) != tolower(s[end]))    {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};