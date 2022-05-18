class Solution {
public:
    int maxArea(vector<int>& height) {
        int m = -1;
        for (int i = 0, j = height.size() - 1; i < j;) {
            m = max(m, (j - i) * min(height[i], height[j]));
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return m;
    }
};