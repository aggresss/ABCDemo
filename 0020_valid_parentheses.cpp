/**
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
* determine if the input string is valid.
* An input string is valid if:
*     Open brackets must be closed by the same type of brackets.
*     Open brackets must be closed in the correct order.
*/

class Solution
{
  public:
    bool isValid(string s) {
        stack<char> result;
        int n = s.size();
        if (n == 0)
            return true;
        for (int i = 0; i < n; i++) {
            if (result.empty())
                result.push(s[i]);
            else if (result.top() == '(' && s[i] == ')' ||
                     result.top() == '[' && s[i] == ']' ||
                     result.top() == '{' && s[i] == '}')
                result.pop();
            else
                result.push(s[i]);
        }
        return result.empty();
    }
};
