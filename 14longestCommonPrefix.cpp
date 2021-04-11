#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int i = 0;
		int j;
		int shortest = 2147483647;
		string res;
		if(strs.size() == 0) {
			return res;
		}
		if(strs.size() == 1) {
			return strs[0];
		}
		for(auto s : strs) {
			if (s.size() < shortest) {
				shortest = s.size();
			}
		}
		for(j=0;j < shortest;j++) {
			bool flag = true;
			int size = strs.size();
			for(int k=0;k < size-1;k++) {
				if(strs[k][j] != strs[k+1][j]) {
					flag = false;
					break;
				}
			}
			if(flag == false) {
				break;
			}
		}

		return strs[0].substr(0,j);
	}
		
};

int main() {

}
