
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
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
    vector<int>num1 = {1,2,3,0,0,0};
    vector<int>num2 = {2,5,6};
    solution.merge(num1, 3, num2, 3);
    printVector(num1);
    printVector(num2);
    return 0;
}
