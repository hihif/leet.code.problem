#include <iostream>

using namespace std;

class Solution {
public:
    int longestDecomposition(string text) {
        size_t t1 = 0;
        size_t t2 = text.size() - 1;
        size_t size = 1, count = 1;
        
        while (t1 < t2) {
            if (text.substr(t1, size) == text.substr(t2, size)) {
                count += 2;
                t1+= size;
                t2--;
                if (t1 - t2 == 1)
                    count--;
                size = 1;
            } else {
                size++;
                t2--;
            }
        }
        return count;
    }
};