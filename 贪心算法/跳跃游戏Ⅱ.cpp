//��Ծ��Ϸ II
//https://leetcode.cn/problems/jump-game-ii/
//��ʱ����Ҫ����cover��ѡ������ߵ��ò�������cover��λ�ã�֮ǰ����node��cover���������յ㣬��ô����Ҫ�ƶ�һ��
//����������ˣ�̰�ĵ���һ����ѡ���ܹ��������Զλ��
class Solution {
public:
    int jump(vector<int>& nums) {
        int result = 0;
        int curCover = 0;
        int nextCover = 0;
        if (nums.size() == 1) return 0; //ע��߽�����
        for (int i = 0; i < nums.size(); i++)
        {
            nextCover = max(nextCover, i + nums[i]);
            //��ʼ���Ҳ���� ͬʱ����ߵ���ǰ�����ߵ���ĩβ
            if (i == curCover)
            {
                result++;
                curCover = nextCover;
            }
            if (curCover >= nums.size() - 1) break;
        }
        return result;
    }
};