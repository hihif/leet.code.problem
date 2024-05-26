#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
	string numberToWords(int num) {
		long long n = num;
		map<int, std::string> words;
    	words.insert(make_pair(0, "Zero"));
    	words.insert(make_pair(1, "One"));
    	words.insert(make_pair(2, "Two"));
    	words.insert(make_pair(3, "Three"));
    	words.insert(make_pair(4, "Four"));
    	words.insert(make_pair(5, "Five"));
    	words.insert(make_pair(6, "Six"));
    	words.insert(make_pair(7, "Seven"));
    	words.insert(make_pair(8, "Eight"));
    	words.insert(make_pair(9, "Nine"));
    	words.insert(make_pair(10, "Ten"));
    	words.insert(make_pair(11, "Eleven"));
    	words.insert(make_pair(12, "Twelve"));
    	words.insert(make_pair(13, "Thirteen"));
    	words.insert(make_pair(14, "Fourteen"));
    	words.insert(make_pair(15, "Fifteen"));
    	words.insert(make_pair(16, "Sixteen"));
    	words.insert(make_pair(17, "Seventeen"));
    	words.insert(make_pair(18, "Eighteen"));
    	words.insert(make_pair(19, "Nineteen"));
    	words.insert(make_pair(20, "Twenty"));
    	words.insert(make_pair(30, "Thirty"));
    	words.insert(make_pair(40, "Forty"));
    	words.insert(make_pair(50, "Fifty"));
    	words.insert(make_pair(60, "Sixty"));
    	words.insert(make_pair(70, "Seventy"));
    	words.insert(make_pair(80, "Eighty"));
    	words.insert(make_pair(90, "Ninety"));

	    if (n < 20) {
	        return words[n];
	    }

	    if (n < 100) {
	        return words[n / 10 * 10] + (n % 10 > 0 ? " " + numberToWords(n % 10) : "");
	    }

	    if (n < 1000) {
	        return numberToWords(n / 100) + " Hundred" + (n % 100 > 0 ? " " + numberToWords(n % 100) : "");
	    }

		if (n < 1000000) {
			return  numberToWords(n / 1000) + " Thousand" +  (n % 1000 > 0 ? " " + numberToWords(n % 1000) : "");
		}

		if (n < 1000000000) {
			return  numberToWords(n / 1000000) + " Million" +  (n % 1000000 > 0 ? " " + numberToWords(n % 1000000) : "");
		}

		if (n < 1000000000000) {
			return  numberToWords(n / 1000000000) + " Billion" +  (n % 1000000000 > 0 ? " " + numberToWords(n % 1000000000) : "");
		}

		return  "";
	}

};