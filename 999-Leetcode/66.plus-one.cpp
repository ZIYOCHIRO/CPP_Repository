/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

#include <iostream>
#include <vector>
using namespace std;
// @lc code=starts
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        for (int i = n; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i] += 1;
                return digits;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        
        return digits;
    }

    int sum(int a, int b) {
        return a + b;
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
    cout << "hello there" << endl;
    vector<int> d = {9,9,9};
    Solution solution;
    vector<int> v = solution.plusOne(d);
    printVector(v);
    return 0;
}
