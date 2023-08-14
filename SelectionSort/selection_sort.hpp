#pragma once

#include <vector>

using namespace std;

// https://leetcode.com/problems/sort-an-array/
class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums;
    }
    int i = 1;
    while (i < nums.size()) {
      int temp = i;
      for (int j = i - 1; j >= 0; j--) {
        if (nums[j] > nums[temp]) {
          swap(nums[j], nums[temp]);
          temp = j;
        } else {
          break;
        }
      }
      i++;
    }
    return nums;
  }
};
