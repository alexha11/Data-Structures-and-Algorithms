class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() != 2) {
            string st = "";
            int first = s[0] - '0';
            int second;
            for (int i = 1; i < s.length(); i++) {
                int temp = s[i] - '0';
                second = temp;
                int sum = (first + second) % 10;
                st += to_string(sum);
                cout << first << ' ' << second << " test ";
                first = second;
            }
            s = st;
            cout << st << ' ' << second << endl;
        }
        return s[0] == s[1];
    }
};