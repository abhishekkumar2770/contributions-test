class Solution {
public:
    int kthDigit(long long k) {
        if (k <= 9)
            return (int)k;

        k -= 9;

        long long pow10 = 1;
        int digits = 2;

        while (true) {
            // For d digits:
            // b ranges from 10^(d-2) to 10^(d-1)-1
            long long firstBlock = pow10;
            long long blocks = 9 * pow10;

            long long groupDigits = blocks * 10LL * digits;

            if (k > groupDigits) {
                k -= groupDigits;
                pow10 *= 10;
                digits++;
            } else {
                break;
            }
        }

        long long firstBlock = pow10;

        // Which block contains the kth digit
        long long blockIndex = (k - 1) / (10LL * digits);
        long long b = firstBlock + blockIndex;

        // Position inside this block
        long long pos = (k - 1) % (10LL * digits);

        long long numberIndex = pos / digits;
        int digitIndex = pos % digits;

        long long number;

        if (b % 2 == 0)
            number = b * 10 + numberIndex;
        else
            number = b * 10 + (9 - numberIndex);

        string s = to_string(number);

        return s[digitIndex] - '0';
    }
};