/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
         int maxIndex = max(a.length(), b.length());
        int tem = 0;
        string result = "";
        for (int i = maxIndex - 1; i >= 0; i--) {
            int x = 0, y = 0;
            int j = i - maxIndex + a.length();
            if (j  >= 0) {
                x = a[j] - '0';
            }
            int k = i - maxIndex + b.length();
            if ( k >= 0) {
                y = b[k] - '0';
            }
            int temSum = x + y + tem;
            if (temSum == 1 || temSum == 0) {
                result += to_string(temSum);
                tem = 0;
                // result 这一位等于0
            } else if (temSum == 2){
                result += to_string(0);
                tem = 1;
            } else {
                result += to_string(1);
                tem = 1;
            }
        }
        reverse(result.begin(), result.end());
        if (tem == 1) {
            //  在最前面插入1
            result = "1" + result;
        }
        
        return result;
    }
};
// @lc code=end

int main() {
    Solution solution;
    string a = solution.addBinary("10111", "11");
    printf("%s", a.c_str());
    return 0;
}
