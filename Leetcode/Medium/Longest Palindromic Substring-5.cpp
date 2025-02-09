class Solution {
private:
    int start = 0;     
    int maxLength = 1;   
    int n;               
    string s;          
    
    void expand(int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            int length = right - left + 1;
            if (length > maxLength) {
                maxLength = length;
                start = left;
            }
            left--; 
            right++;
        }
    }
    
public:
    string longestPalindrome(string str) {
        if (str.empty() || str.size() == 1) return str; 
        
        s = str;
        n = s.size();
        
        for (int i = 0; i < n; i++) {
            expand(i, i);       
            expand(i, i + 1);  
        }
        
        return s.substr(start, maxLength); 
    }
};
