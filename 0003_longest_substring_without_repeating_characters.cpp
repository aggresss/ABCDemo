/**
* Given a string, find the length of the longest substring without repeating characters.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> lastAppearIndex;
        int subStringStart = 0, maxLength = 0;
        map<char, int>::iterator it;
        for (int i = 0; i < s.length(); i++) {
            it = lastAppearIndex.find(s[i]);
            if (it != lastAppearIndex.end() && it->second >= subStringStart) {
                subStringStart = it->second+1;
            }
            lastAppearIndex[s[i]] = i;
            maxLength = max(maxLength, i - subStringStart + 1);
        }
        return maxLength;
    }
};
