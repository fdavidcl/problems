// https://leetcode.com/problems/arithmetic-slices/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        
        int count = 0;
        
        unsigned p0 = 0, p1 = 2;
        const unsigned n = A.size();
        
        while (p0 < n - 2) {
            if (A[p0] - A[p0 + 1] == A[p1 - 1] - A[p1]) {
                count += (p1 - p0) - 1;
                if (p1 < n - 1) {
                    p1 += 1;
                } else {
                    p0 = n - 2;
                }
            } else {
                if (p1 - p0 < 3) {
                    p1 += 1;
                }
                p0 = p1 - 2;
            }
        }
        
        return count;
    }
};
