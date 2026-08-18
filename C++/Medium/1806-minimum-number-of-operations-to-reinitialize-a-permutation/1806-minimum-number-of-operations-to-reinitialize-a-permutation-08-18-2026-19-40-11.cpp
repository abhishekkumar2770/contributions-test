class Solution {
public:
    int reinitializePermutation(int n) {
        int curr= 1;
        int ops = 0;
        do{
            if(2* curr<n) curr = 2*curr;
            else curr = 2 * curr - n+1;
            ops++;
        
        } while (curr != 1);
        return ops;
        
    }
};