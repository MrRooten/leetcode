#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int si = 0;
        int pi = 0;
        int sn = s.size();
        int pn = p.size();
        
        if (sn == 0 && pn == 0) {
            return true;
        } else if (pn == 0) {
            return false;
        }

        if (pn==1&&p[0]=='*') {
            return true;
        }
        while (si < sn && pi < pn) {
            if (s[si] != p[pi] && (p[pi]!='?'&&p[pi]!='*')) {
                return false;
            } else if (p[pi] == '?' || p[pi] == s[si]) {
                si++;
                pi++;
            } else if (p[pi] == '*') {
                while(p[pi+1] == '*') {
                    pi++;
                }
                while (si < sn) {
                    if (p.substr(pi,pn-pi)=="*") {
                        return true;
                    }
                    if (isMatch(s.substr(si,sn-si),p.substr(pi+1,pn-pi))) {
                        return true;
                    }
                    si++;
                }
                return false;
            }
            
            if (pi == pn && si < sn) {
                return false;
            }

            
        }
        if (si == sn&&pi < pn) {
                int i = pi;
                while (i < pn) {
                    if (p[i] != '*') {
                        return false;
                    }
                    i++;
                }
        }
        return true;
    }
};
//"babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb"
//"b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a"
//
int main() {
    Solution s;
    //"mississippi"
    //"m??*ss*?i*pi"
    cout << s.isMatch("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb","b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a") << endl;
}