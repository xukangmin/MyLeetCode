/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/


#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int t_size = nums1.size() + nums1.size();
        int median_num = 0;
        int m1 = 0, m2 =0;
        if (t_size % 2 == 0) {
            median_num = 2;
            m1 = t_size / 2;
            m2 = m1 + 1;
        } else {
            median_num = 1;
            m1 = t_size / 2 + 1;
        }

        for(auto i : nums1) {
            
        }
    }
};

int main() {
    Solution sol;

    vector<int> num1 = {1,3};
    vector<int> num2 = {2};

    cout << sol.findMedianSortedArrays(num1, num2) << endl;

    return 0;
}
