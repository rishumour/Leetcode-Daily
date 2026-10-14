class Solution {
public:
    bool threeFibonacciSum(int n) {
        if (n % 2 != 0) {
            return false;
        }
        
        long long target = n / 2;
        long long a = 0;
        long long b = 1;
        
        while (b < target) {
            long long next_fib = a + b;
            a = b;
            b = next_fib;
        }
        
        return b == target;
    }
};