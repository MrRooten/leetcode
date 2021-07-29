#include <bits/stdc++.h>
using namespace std;
int lenWords(vector<string> &words,int i,int j) {
    int len = 0;
    while(i <= j) {
        len += words[i].size();
        i++;
    }
    return len;
}

string strSpace(int num) {
    string res;
    for(int i=0;i < num;i++) {
        res += " ";
    }
    return res;
}
string insertSpace(vector<string>&words,int i,int j,vector<int>&spaces) {
    string res;
    int k = 0;
    int n = j-i;
    while(i <= j) {
        res += words[i];
        if (k < n)
            res += strSpace(spaces[k]);
        k++;
        i++;
    }
    return res;
}
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        stack<string> s;
        for(int i=0;i < words.size();i++) {
            int leastLength = 0;
            for(int j=i;j < words.size();j++) {
                leastLength = lenWords(words,i,j) + j-i;
                if (j == words.size()-1 && leastLength <= maxWidth) {
                    int numSpace = j - i;
                    vector<int> spaces;
                    for(int k=0;k < numSpace;k++) {
                        spaces.push_back(1);
                    }
                    string str = insertSpace(words,i,j,spaces);
                    for(int k=0;k < maxWidth - leastLength;k++) {
                        str += " ";
                    }
                    ans.push_back(str);
                    i = j;
                }
                if (leastLength > maxWidth) {
                    j -= 1;
                    
                    int numSpaces = maxWidth - lenWords(words,i,j);
                    int numIntern = j - i;
                    if (numIntern == 0) {
                        string str = words[i];
                        for(int i=0;i < numSpaces;i++) {
                            str += " ";
                        }
                        ans.push_back(str);
                        i = j;
                        break;
                    }
                    vector<int> spaces;
                    int leftSpaces = numSpaces % numIntern;
                    for(int k=0;k < numIntern;k++) {
                        spaces.push_back(numSpaces/numIntern);
                    }

                    for(int k=0;k < leftSpaces;k++) {
                        spaces[k] += 1;
                    }

                    ans.push_back(insertSpace(words,i,j,spaces));
                    i = j;
                    break;
                }

            }
        }
        return ans;
    }
};


int main() {
    vector<string> test = {"shall","be"};
    Solution s;
    vector<string> ans = s.fullJustify(test,16);
    return 0;
}