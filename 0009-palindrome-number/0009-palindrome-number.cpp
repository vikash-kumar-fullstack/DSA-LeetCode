class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return 0;
        int res = 0;
        int test=x;
        while (test != 0) {
            int temp = test % 10;
            if (res > INT_MAX / 10 || res < INT_MIN / 10)
                return false;
            res = res * 10 + temp;
            test /= 10;
        }
        if (res != x)
            return false;
        else
            return true;
    }
};