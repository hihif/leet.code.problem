#include <iostream>

using namespace std;

class Solution {
public:
    int    multiplyChar(char c1, char c2) {
        return (c1 - 48) * (c2 - 48);
    }

    void removeLeadingZeros(string& str) {
        int i = 0;
        while (str[i] == '0') i++;
        str.erase(0, i);
    }

    string    addStrings(string res, string tmp) {
        int k = 0, r = 0, i = tmp.size() - 1,j = res.size() - 1;
        string result;
    
        while (i > -1 || j > -1) {

            if (i > -1 && j > -1) {
                r = (res[j--] - 48) + (tmp[i--] - 48) + k;
            } else if (i > -1) {
                r = (tmp[i--] - 48) + k;
            } else if (j > -1) {
                r = (res[j--] - 48) + k;
            }

            if (r < 10) {
                result.insert(0, 1, r + 48);
                k = 0;
            } else {
                result.insert(0, 1, (r % 10) + 48);
                k = r / 10;
            }
        }
    
        if (k != 0)
            result.insert(0, 1, k + 48);

        removeLeadingZeros(result);
        return result;
    }

    string multiply(string num1, string num2) {
        int k, r = 0, zeros = 0;
        string res, tmp;
    
        if (num1 == "0" || num2 == "0")
            return "0";
        
        for (int i = num2.size() - 1; i >= 0; i--, zeros++) {
            k = 0;
            tmp.clear();
            tmp.append(zeros, '0');
            for (int j = num1.size() - 1; j >= 0; j--) {
                r = multiplyChar(num1[j], num2[i]);
                r += k;
                if (r < 10) {
                    tmp.insert(0, 1, r + 48);
                    k = 0;
                } else {
                    tmp.insert(0, 1, (r % 10) + 48);
                    k = r / 10;
                }
            }
            if (k != 0)
                tmp.insert(0, 1, k + 48);
            res = addStrings(res,tmp);
        }
        return res;
    }
};