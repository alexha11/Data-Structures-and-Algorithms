class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        long result = 0; 
        int sign = 1; 
        
        while (i < n && s[i] == ' ') {
            i++;
        }
        
       
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        
        while (i < n && isdigit(s[i])) {
            
            result = result * 10 + (s[i] - '0');
            
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return result * sign;
    }
};