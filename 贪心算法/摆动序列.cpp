/*
�ڶ����� ̰���㷨/��̬�滮
https://leetcode.cn/problems/wiggle-subsequence/description/
*/

//ͬʱ��ֻ������Ԫ�ص�������ǽ�ȥ - ������չΪ����Ԫ��
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//���в��ְ����޷�ͨ�����������
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int prediff = 0;
        int backdiff = 0;
        int result = 1;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            backdiff = nums[i + 1] - nums[i];
            if ((prediff <= 0 && backdiff > 0) || (prediff >= 0 && backdiff < 0)) result += 1;
            prediff = backdiff;
        }
        return result;
    }
};

//������������¶���ƽ��
//���ڶ�prediff�ĸ��²���ȷ����
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int prediff = 0;
        int backdiff = 0;
        int result = 1;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            backdiff = nums[i + 1] - nums[i];
            if ((prediff <= 0 && backdiff > 0) || (prediff >= 0 && backdiff < 0))
            {
                result += 1;
                prediff = backdiff;
            }
        }
        return result;
    }
};
int main()
{
    Solution solution;
    vector<int> vec2 = { 1, 7,4,9,2,5 };
    cout << solution.wiggleMaxLength(vec2) << endl;
}
