#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> arr;
    int robed(vector<int>& nums, int i) {
        if (i < 0)
            return 0;
        if (arr[i] >= 0)
            return arr[i];
        arr[i] = max(robed(nums, i - 2) + nums[i], robed(nums, i - 1));
        return arr[i];
    }

public:
    int rob(vector<int>& nums) {
        arr = vector<int>(nums.size());
        fill(arr.begin(), arr.end(), -1);
        return robed(nums, nums.size() - 1);
    }
}; 