// fisrt, First, recursion is a viable and typical idea
// But Timeout
// Then try DP, work.
// O(n)

// What if we want to solve the problem in O(logn)?

// Matrix Fast Power

#include<iostream>
#include<vector>
#include<cmath>

class Solution {
public:
    const int MOD = 1000000007; // The question requires modulo operation.

    int fib(int n) {
        if (n < 2) {
            return n;
        }
        vector<vector<long>> q{{1, 1}, {1, 0}};
        vector<vector<long>> res = pow(q, n - 1);
        // Compute the (n-1)th power of the matrix and then take the first number as the result.
        return res[0][0];
    }

    vector<vector<long>> pow(vector<vector<long>>& a, int n) {
        vector<vector<long>> ret{{1, 0}, {0, 1}}; // identity matrix
        while (n > 0) {
            if (n & 1) { 
                // The binary representation of the current exponent will have a redundant '1' bit
                ret = multiply(ret, a);
            }
            n >>= 1;
            a = multiply(a, a); // square
            // Note that 'a' is not the final result to be returned, 'ret' is.
            // Therefore, squaring 'a' is just to obtain the candidate value.
        }
        return ret;
    }

    vector<vector<long>> multiply(vector<vector<long>>& a, vector<vector<long>>& b) {
        vector<vector<long>> c{{0, 0}, {0, 0}}; // 2x2 matrix multiplication
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
            }
        }
        return c;
    }
};