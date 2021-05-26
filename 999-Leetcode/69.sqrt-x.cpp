/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        long long left = 0, right = x / 2 + 1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (mid * mid <= x && (mid + 1) * (mid + 1) > x) {
                return mid;
            }
            if (mid * mid > x) {
                // 在左边找
                right = mid;
            } else {
                // 在右边找
                left = mid + 1;
            }
        }
        
        return 0;
    }
};
// @lc code=end



void printVector(vector<int>& v)
{
    cout << "{ ";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "} " << endl;
}

int main() {
    Solution solution;
    int a = solution.mySqrt(626); //15
    cout << a << endl;
    return 0;
}

