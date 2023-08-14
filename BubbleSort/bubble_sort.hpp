#pragma once

#include <vector>

using namespace std;

// https://leetcode.com/problems/sort-an-array/
class Solution {
public:
  std::vector<int> sortArray(std::vector<int> &nums) {
        int i, j;
        bool swapped;
        auto n = nums.size();
        for (i = 0; i < n - 1; i++) {
            swapped = false;
            for (j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }
            if (swapped == false)
                break;
        }
        return nums;
  }
};