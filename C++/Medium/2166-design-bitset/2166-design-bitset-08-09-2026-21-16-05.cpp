class Bitset {
public:
    vector<int> bits;
    int ones;
    bool flipped;

    Bitset(int size) {
        bits.assign(size, 0);
        ones = 0;
        flipped = false;
    }

    void fix(int idx) {
        int actual = bits[idx] ^ flipped;

        if (actual == 0) {
            bits[idx] ^= 1;
            ones++;
        }
    }

    void unfix(int idx) {
        int actual = bits[idx] ^ flipped;

        if (actual == 1) {
            bits[idx] ^= 1;
            ones--;
        }
    }

    void flip() {
        flipped = !flipped;
        ones = bits.size() - ones;
    }

    bool all() {
        return ones == bits.size();
    }

    bool one() {
        return ones > 0;
    }

    int count() {
        return ones;
    }

    string toString() {
        string ans;

        for (int i = 0; i < bits.size(); i++) {
            ans += char('0' + (bits[i] ^ flipped));
        }

        return ans;
    }
};