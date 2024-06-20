/*
电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
*/

/*
index：不同于组合中的cur_index，这里是从不同的集合里取值，所以不需要控制cur_index(startindex)，让i每次从startindex开始取，而是控制现在遍历到了digits的第几位
如果index已经遍历到digits的最后一位，证明已经遍历完到达叶子节点，为递归的结束条件

for循环：遵照回溯模板，首先push_back处理当前字母，接着进入之后的递归遍历。递归完成该分支下的所有叶子节点之后，pop_back当前字母，进入同层的下一个字母进行遍历
*/
class Solution {
private:
    const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
    };

public:
    vector<string> result;
    string str;
    void backtracking(const string& digits, int index)
    {
        if (index == digits.size())
        {
            result.push_back(str);
            return;
        }

        int digit = digits[index] - '0';
        string letter = letterMap[digit];

        for (int i = 0; i < letter.size(); i++)
        {
            str.push_back(letter[i]);
            backtracking(digits, index + 1);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};