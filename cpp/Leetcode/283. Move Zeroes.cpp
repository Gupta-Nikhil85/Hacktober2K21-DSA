//https://leetcode.com/problems/move-zeroes/
//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

//Note that you must do this in-place without making a copy of the array.

#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        method1(nums);
    }
private:
    void method1(vector<int>& nums) {
        int k = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != 0) {
                int temp = nums[k];
                nums[k] = nums[i];
                nums[i] = temp;
                ++k;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = [1, 0, 2, 3, 5, 0, 0];
    s.moveZeros(nums);
}


