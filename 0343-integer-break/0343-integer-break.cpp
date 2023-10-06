
class Solution {
public:
    int integerBreak(int n) {
        // Base cases: for n < 4, return n-1
        if (n < 4)
            return n - 1;

        // Calculate the number of times 3 can be multiplied
        int numOfThrees = n / 3;

        // Initialize the answer with the product of 3 raised to numOfThrees
        long long productOfThrees = pow(3, numOfThrees);

        // Adjust the product based on the remainder when divided by 3
        if (n % 3 == 1) {
            // If remainder is 1, you can multiply by 4 instead of 3
            productOfThrees /= 3;
            productOfThrees *= 4;
        } else if (n % 3 == 2) {
            // If remainder is 2, multiply by 2
            productOfThrees *= 2;
        }

        // Return the maximum product
        return productOfThrees;
    }
};
