#include <cstdio>
#include <limits.h>
class Solution {
public:
    int divide(int dividend, int divisor) {
        long a = dividend;
        long b = divisor;
        if (a == b) {
            return 1;
        }
        if (a == INT_MIN && b == -1) {
            return INT_MAX;
        }
        if (a == INT_MIN && b == 1) {
            return INT_MIN;
        }
        if (b == -1) {
            return -1 * a;
        }

        if (a == 0) {
            return 0;
        }


        bool sign = true;
        if (a > 0&&b >0) {
            sign = true;
        } else if (a < 0 && b <0) {
            sign = true;
        } else if (a > 0 && b < 0) {
            sign = false;
        } else if (a <0 && b > 0) {
            sign = false;
        }

        if (a < 0) {
            a = -a;
        }

        if (b < 0) {
            b = -b;
        }

        long l = 0;
        long r = INT_MAX;
        long res;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if (mul(mid,b)<=a) {
                l = mid;
            } else {
                r = mid-1;
            } 
        }

        long ans = sign? l : -l;
        if (ans > INT_MAX || ans < INT_MIN) return INT_MAX;
        return (int)ans;
    }

    long mul(long a,long k) {
        long ans = 0;
        while (k) {
            if (k&1==1) ans += a;
            k = k >> 1;
            a += a;
        }

        return ans;
    }
};

int main() {
    Solution s;
    printf("%d\n",s.divide(2147483647,-1));
}