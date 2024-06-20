/*
�绰�������ĸ���
����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�
https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
*/

/*
index����ͬ������е�cur_index�������ǴӲ�ͬ�ļ�����ȡֵ�����Բ���Ҫ����cur_index(startindex)����iÿ�δ�startindex��ʼȡ�����ǿ������ڱ�������digits�ĵڼ�λ
���index�Ѿ�������digits�����һλ��֤���Ѿ������굽��Ҷ�ӽڵ㣬Ϊ�ݹ�Ľ�������

forѭ�������ջ���ģ�壬����push_back����ǰ��ĸ�����Ž���֮��ĵݹ�������ݹ���ɸ÷�֧�µ�����Ҷ�ӽڵ�֮��pop_back��ǰ��ĸ������ͬ�����һ����ĸ���б���
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