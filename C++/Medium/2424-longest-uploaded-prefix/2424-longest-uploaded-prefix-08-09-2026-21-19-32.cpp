class LUPrefix {
    vector<bool> uploaded;
    int prefix;

public:
    LUPrefix(int n) {
        uploaded.resize(n + 1, false);
        prefix = 0;
    }

    void upload(int video) {
        uploaded[video] = true;

        while (prefix + 1 < uploaded.size() && uploaded[prefix + 1]) {
            prefix++;
        }
    }

    int longest() {
        return prefix;
    }
};