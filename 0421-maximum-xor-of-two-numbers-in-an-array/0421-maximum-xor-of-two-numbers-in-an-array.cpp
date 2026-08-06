class TrieNode {
public:
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Solution {
public:
    void insert(TrieNode* root, int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int query(TrieNode* root, int num) {
        TrieNode* node = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int want = 1 - bit;
            if (node->child[want]) {
                ans |= (1 << i);
                node = node->child[want];
            } else {
                node = node->child[bit];
            }
        }
        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();

        for (int x : nums)
            insert(root, x);

        int ans = 0;
        for (int x : nums)
            ans = max(ans, query(root, x));

        return ans;
    }
};