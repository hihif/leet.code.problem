#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        map<int, string> roman_values = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};

        for (map<int, string>::reverse_iterator i = roman_values.rbegin(); i != roman_values.rend(); ++i) {
			while (num >= i->first) {
				roman += i->second;
				num -=  i->first;
			}
		}
		return roman;
    }
};