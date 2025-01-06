class Solution {
public:
    bool isPalindrome(int x) {
        string input = to_string(x);
        int i = 0; int j = input.length() - 1; 
        while (i < j) {
            if (input[i] == input[j]) {
                ++i;
                --j;
            }
            else {
                return false;
            }
        }

        return true; 
    }
};