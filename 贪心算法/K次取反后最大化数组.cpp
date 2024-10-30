/*
K ��ȡ������󻯵������  https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/
��һ���������鰴�վ���ֵ��С�Ӵ�С����ע��Ҫ���վ���ֵ�Ĵ�С
�ڶ�������ǰ���������������������Ϊ������ͬʱK--
�����������K������0����ô����ת����ֵ��С��Ԫ�أ���K����
���Ĳ������
*/
class Solution {
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        //step1
        sort(nums.begin(), nums.end(), cmp);

        //step2 abs�ϴ������������󣬴����ʼ��������abs�ϴ�����ķ���
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0 && k > 0)
            {
                nums[i] *= -1;
                k--;
            }
        }
        //step3 ע�������滻ѭ�����ӵı�ֻ��Ҫһֱѭ���ı�abs��С���Ǹ����ķ��ż��ɣ��������ڸı����λ�ص�ԭ�ȵ�ֵ������ֻ��Ҫ�ж���ż��
        if (k % 2 == 1) nums[nums.size() - 1] *= -1;

        //step4
        int result = 0;
        for (int num : nums) result += num;

        return result;
    }
};