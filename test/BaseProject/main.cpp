
#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
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
    int a = solution.climbStairs(45); // 1~45
    cout << a << endl;
    return 0;
}
