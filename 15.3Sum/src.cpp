#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector< vector<int> > arr;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int t = nums[i] + nums[l] + nums[r];
                if (t == 0) {
                    arr.push_back({nums[i], nums[r], nums[l]});
                    while (l < r && nums[l] == nums[l+1])
                        l++;
                    while (l < r && nums[r] == nums[r-1])
                        r--;
                    l++;
                    r--;
                } else if (t < 0) {
                        l++;
                } else {
                        r--;
                }
            }
        }
        return arr;
    }
};