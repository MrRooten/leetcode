#include <string>
#include <map>
#include <iostream>
#include <stdlib.h>
using namespace std;

map<char,int> dictRoman = {
    {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
};

map<string,int> dictRoman2 = {
        {"I",1},{"IV",4},{"V",5},{"IX",9},{"X",10},{"XL",40},{"L",50},{"XC",90},{"C",100},{"CD",400},{"D",500},{"CM",900},{"M",1000}
};
class Solution {
public:
    int romanToInt(string s) {
        int length = s.size();
        int i = length - 1;
        int res = 0;
        while(i >= 0) {
            int bit = dictRoman[s[i]];
            if (i != length - 1&&dictRoman[s[i]] < dictRoman[s[i+1]]) {
                bit = -1 * bit;
            }
            res += bit;
            i--;
        }

        return res;
    }
};

int main(int argc,char** argv) {
    string a = argv[1];
    Solution s;
    cout << s.romanToInt(a) << endl;
}