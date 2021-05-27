/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int last = 0;
        int result = 1;
        for (int i = 1; i <= n; i++) {
            int tem = result;
            result += last;
            last = tem;
        }
        return result;
    }
    
    /*
     爬30层阶梯的方法数f(30)
     爬29层阶梯的方法数f(29) + 1层阶梯
     爬28层阶梯的方法数f(28) + 2层阶梯
     f(30) = f(29) + f(28)
     */
};
// @lc code=end

