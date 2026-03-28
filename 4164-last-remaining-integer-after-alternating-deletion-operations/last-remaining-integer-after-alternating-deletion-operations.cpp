class Solution {
public:
    long long lastInteger(long long n) {
        constexpr long long MASK = 0xAAAAAAAAAAAAAAALL; 
        return ((n - 1) & MASK) + 1;
    }
};