class ProductOfNumbers {
public:
    vector<long long> prefix;

    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            // Reset because any product containing this zero is 0
            prefix.clear();
            prefix.push_back(1);
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        // If k numbers are not available after the last zero,
        // the answer contains a zero.
        if (k >= prefix.size())
            return 0;

        return prefix.back() / prefix[prefix.size() - 1 - k];
    }
};