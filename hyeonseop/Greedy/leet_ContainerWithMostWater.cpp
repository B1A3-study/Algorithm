class Solution {
public:
    int maxArea(vector<int>& height) {
        int start, end, w, h, area, max = 0;
        for(int i = 0; i < height.size() - 1; i++){
            if(start > height[i]) continue;
            start = height[i];
            for(int j = i + 1; j < height.size(); j++){
                end = height[j];
                h = start;
                w = j - i;
                if(start > end) h = end;
                area = h*w;
                if(max < area) max = area;
            }
        }
        return max;
    }
};