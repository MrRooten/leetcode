#include <string>
#include <map>
#include <iostream>
#include <stdlib.h>
using namespace std;
map<int,string> dict = {
            {1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}
        };
class Solution {
public:
    
    string intToRoman(int num) {
        string res = "";
        int tmphelp = 1;
        
        while(num != 0) {
            int bit = num % 10;
            
            num = num/10;
            if (bit < 4) {
                if (bit == 0) {
                    tmphelp *= 10;
                    continue;
                }
                for(int i=0;i < bit;i++) {
                    res = dict[tmphelp]+res;
                }
            } else if (bit == 4) {
                res = dict[4*tmphelp] + res;
            } else if (bit > 4) {
                if (bit == 9) {
                    res = dict[9*tmphelp] + res;
                } else {
                    string tmp = dict[5*tmphelp];
                    for (int i=0;i < bit-5;i++) {
                        tmp += dict[tmphelp];
                    }
                    res = tmp + res;
                }
            }
            tmphelp *= 10;
        }

        return res;
    }
};

int main(int argc,char** argv) {
    int a = atoi(argv[1]);
    Solution s;
    cout << s.intToRoman(a) << endl;
}