class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; 
        
        vector<string> f(numRows);
        int cur = 0;
        bool goingDown = false;

        for (char c : s) {
            f[cur] += c;
            if (cur == 0 || cur == numRows - 1) 
                goingDown = !goingDown;
            cur += goingDown ? 1 : -1;
        }

        string finalAns;
        for (const string &row : f) {
            finalAns += row;
        }

        return finalAns;
    }
};
