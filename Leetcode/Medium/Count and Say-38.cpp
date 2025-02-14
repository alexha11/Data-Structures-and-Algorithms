class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string st = "1";

        for (int i = 1; i < n; i++) {
            string ans = "";
            int size = st.size();

            for(int j = 0; j < size; j++) {
                int count = 1;
                while (j < size - 1 && st[j] == st[j + 1]) count++, j++;
                ans += to_string(count) + st[j];
            }
            st = ans;
            cout << st << endl;
        }
        return st;
    }
};