/*
A string S of lowercase English letters is given.We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output : [9, 7, 8]
Explanation :
	The partition is "ababcbaca", "defegde", "hijhklij".
	This is a partition so that each letter appears in at most one part.
	A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

*/
//Solutions

#include<iostream>
#include<vector>
#include<string>
#include<map>
//using namespace std;
class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::map<char, int> m;
        for (int i = 0; i < s.size(); i++)
            m[s[i]] = i;
        int i = 0, j = 0, start = 0;
        std::vector<int>a;
        while (i < s.size()) {
            j = std::max(j, m[s[i]]);
            if (i == j) {
                a.push_back(i - start + 1);
                start = i + 1;
            }
            i++;

        }
        
            return a;
    }
};

int main() {
    Solution obj;
    std::string s;
   //s = "ababcbacadefegdehijhklij";
    std::cin >> s;
    std::vector<int>ans = obj.partitionLabels(s);
    for (auto a : ans)
        std::cout << a<<" ";
  
    
}