#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

map<char,string> dict = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pgrs"},{'8',"tuv"},{'9',"wxyz"}};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n = digits.size();
        for(int i=0;i < n;i++) {
            string contains = dict[digits[i]];
            if (res.size() == 0) {
                for(auto c : contains) {
                    string s(1,c);
                    res.push_back(s);
                }
            } else {
                vector<string> tmp;
                for(auto item : res) {
                    for (auto c : contains) {
                        tmp.push_back(item+c);
                    }
                }
                res = tmp;
            }
        }
        return res;
    }
};
void print(vector<string> args) {
    for(int i=0;i < args.size();i++) {
        cout << args[i] << " ";
    }
    cout << endl;
}
int main(int argc,char** argv) {
    string arg = argv[1];
    Solution s;
    print(s.letterCombinations(arg));
}