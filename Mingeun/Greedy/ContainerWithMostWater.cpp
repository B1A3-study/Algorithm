class Solution {
public:
    
    int getArea(const vector<int>& height, int start, int end){
        return std::min(height[start], height[end]) * abs(start - end);
    }
    
    int maxArea(vector<int>& height) {
        int maxV = -1, start = 0, end = height.size() - 1;
        int i = start, j = end;
        
        while (i < j){
            if (height[i] > height[j])      j--;
            else if (height[j] >= height[i]) i++;
            
            
            // if (i > height.size() - 1 || i < 0) break;
            
            if (getArea(height, i, j) > getArea(height, start, end)) {
                start = i;
                end = j;
            }
            
            
            
            // cout << "start: " << start << ' ' << "end: " << end << endl;
            // cout << "i: " << i << ' ' << "j: " << j << endl;
        }
        
        return getArea(height, start, end);
    }
};