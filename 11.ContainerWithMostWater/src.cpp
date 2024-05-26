#include <iostream>
#include <iostream>

using namespace std;

class Solution {
private:
    int multy(int i, int j) {
        return j - i;
    }
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, tmp;
        size_t area = 0;
        while (i < j) {
            (height[i] < height[j]) ? tmp = multy(i, j) * height[i++] : tmp = multy(i, j) * height[j--];
            if (tmp > area)
                area = tmp; 
        }
        return area;
    }
};