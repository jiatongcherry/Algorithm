//��Ծ��Ϸ https://leetcode.cn/problems/jump-game/
//��ô��Ծ��ÿ�������ٲ�������Ҫ����Ҫ������Ծ���Ƿ�Χ
//������ת��Ϊ��Χ�Ƿ���Ը������һ����
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0; //�����Ը��ǵ����±�
        for (int i = 0; i <= cover; i++) //ע��cover���±꣬���Կ���ȡ��
        {
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size() - 1) return true;
        }
        return false;
    }
};