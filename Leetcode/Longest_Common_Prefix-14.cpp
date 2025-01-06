class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        string tempt = "";
        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j < ans.length(); j++) {
                //cout << "test" << ans[j] << ' ' << strs[i][j] << endl;
                if (strs[i][j] == ans[j]) {
                    tempt += ans[j];
                    cout << tempt << ' ';
                }
                else {
                    ans = tempt;
                    break;
                }
            }
            tempt = "";
        }
        
        return ans;
    }
};