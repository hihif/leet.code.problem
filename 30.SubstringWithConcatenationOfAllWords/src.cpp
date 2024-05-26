#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
    bool checkSubstring(unordered_map<string, int> wordCount, string sub, int k) {
        for(int j=0; j<sub.size(); j+=k) {
            string w = sub.substr(j, k);

            if(wordCount.find(w) != wordCount.end()) {

                if(--wordCount[w] == -1)
                    return false;
            } else 
                return false;
        }
        return true;
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int k = words[0].size();
        int len = s.size();
        int allen = words.size() * k;
        
        unordered_map<string, int> wordCount;
        for (int i=0; i<words.size(); i++)
            wordCount[words[i]]++;

        int i = 0;
        while(i + allen <= len) {
            if(checkSubstring(wordCount, s.substr(i, allen), k)) 
                result.push_back(i);
            i++;
        }
        return result;
    }
};
