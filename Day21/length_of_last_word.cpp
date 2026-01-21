/*
Problem: Length of Last Word
Approach: Traverse from end and count characters
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.size() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count characters of last word
        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }

        return len;
    }
};
