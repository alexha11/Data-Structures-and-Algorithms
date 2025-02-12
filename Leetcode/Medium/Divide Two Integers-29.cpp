class Solution {
public:
    int divide(int dividend, int divisor) {
         if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; 
        }

        bool isNegative = (dividend < 0) != (divisor < 0);
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        
        string str = to_string(a);
        cout << str << endl;

        int rem = 0;
        long long ans = 0;

        for (int i = 0; i < str.length(); i++) {
            long long number = str[i] - '0' ;
            number += rem;
            rem = 0;
            cout << number << " testing ";

            long long count = 0;
            while (number >= b) {
                number -= b;
                count++; 
            }
            rem = number + number + number + number + number + number + number + number + number + number;
            cout << count << endl;
            ans = ans + ans + ans + ans + ans + ans + ans + ans + ans + ans + count;
        }
        cout << ans;
        return isNegative ? -ans : ans;

    }
};

//better way to take a look 
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Handle overflow case
        }

        bool isNegative = (dividend < 0) != (divisor < 0); // XOR to check if signs are different
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        
        long long quotient = 0;
        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            quotient += multiple;
        }
        
        return isNegative ? -quotient : quotient;
    }
};
