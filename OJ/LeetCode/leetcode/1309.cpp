#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/* Leetcode */
/* Type: string */
/* 题目信息 */
/*
 *1309. Decrypt String from Alphabet to Integer Mapping

Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.

 

Example 1:

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
Example 2:

Input: s = "1326#"
Output: "acz"
Example 3:

Input: s = "25#"
Output: "y"
Example 4:

Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
Output: "abcdefghijklmnopqrstuvwxyz"
 

Constraints:

1 <= s.length <= 1000
s[i] only contains digits letters ('0'-'9') and '#' letter.
s will be valid string such that mapping is always possible.
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        for (int i = 0; i < s.size();)
        {
            if ((i + 2) < s.size() && s[i + 2] == '#')
            {
                int ss = (s[i] - '0') * 10 + (s[i + 1] - '0');
                res += char(ss + 'a' - 1);
                i += 3;
            }
            else
            {
                res += char(s[i] -'0' + 'a' - 1);
                i++;
            }
        }
        return res;
    }
};

/* 一些总结 */
// 1. 题意: decode, 给定数字串，转换为字符串
// 每三个对比
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

