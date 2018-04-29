/**
* Given a 32-bit signed integer, reverse digits of an integer.
*/

class Solution
{
  public:
    int reverse(int x)
    {
        int y = 0;
        int n;
        while (x != 0)
        {
            n = x % 10;
            if (y > INT_MAX / 10 || y < INT_MIN / 10)
                return 0;
            y = y * 10 + n;
            x /= 10;
        }
        return y;
    }
};
