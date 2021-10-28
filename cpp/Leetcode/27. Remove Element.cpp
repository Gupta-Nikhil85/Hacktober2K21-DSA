//https://leetcode.com/problems/remove-element/
//Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.

#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return method1(nums, val);
    }
private:
    int method1(vector<int>& nums, int val) {
        printArray(nums);
        int k = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != val) {
                swap(nums, i, k);
                k++;
            } else {
            }
        }
        printArray(nums);
        printf("result--> %d\n", k);
        return k;
    }

    int method2(vector<int>& nums, int val) {
        int k = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != val) {
                swap(nums, i, k);
                k++;
            } else {
            }
        }
        return k;
    }

    void swap(vector<int>& nums, int i, int k) {
        int temp = nums[k];
        nums[k] = nums[i];
        nums[i] = temp;
    }

    void printArray(vector<int>& nums) {
        for (int i=0; i<nums.size(); ++i) {
            printf("%d,", nums[i]);
        }
        printf("\n");
    }
};

int main() {
    Solution sln;
    int array[8] = {1, 0, 0, 2, 3, 5, 0, 4};
    vector<int> nums(array, array+8);

    sln.removeElement(nums, 0);

    return 0;
}

