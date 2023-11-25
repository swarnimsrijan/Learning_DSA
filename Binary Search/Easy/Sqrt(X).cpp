class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int low = 0, high = x / 2, mid = -1;
        while (low <= high) {
            mid = low + (high - low) / 2;

            long long square = (long long)mid * mid;

            if (square == x) {
                return mid;
            } else if (square > x) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        long long square = (long long)high * high;
        if (square > x) {
            return high - 1;
        }

        return high;
    }
};
