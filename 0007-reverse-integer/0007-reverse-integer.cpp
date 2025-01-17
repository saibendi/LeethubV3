class Solution {
public:
    int reverse(int x) {
        stack<int> digits; 
        int rem = 0;
        while (x != 0) {
            // remainder
            rem = x % 10;
            digits.push(rem);
            // next 
            x = x / 10;
        }
        long long reverse = 0, size = digits.size(); 
        for (int i = 0; i < size; ++i) {
            reverse += digits.top() * pow(10, i);
            digits.pop();
        }
        return reverse >= INT_MIN && reverse <= INT_MAX ? (int)reverse : 0;
    }
};