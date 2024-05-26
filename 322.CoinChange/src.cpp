#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    map<int, int> memo;
    const int IMPOSSIBLE = INT_MAX - 1;
    int myMin(int a, int b) {
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        return min(a, b);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = INT_MAX;
        int sub;
        memo[0] = 0;
        for (int i = 1; i < amount + 1; ++i) {
            memo[i] = IMPOSSIBLE;
            for (int coin: coins) {
                sub = i - coin;
                if (sub < 0)
                    continue;
                memo[i] = myMin(memo[i], memo[sub] + 1);
            }
        }
        if (memo[amount] == IMPOSSIBLE)
            return -1;
        return memo[amount];
    }
};