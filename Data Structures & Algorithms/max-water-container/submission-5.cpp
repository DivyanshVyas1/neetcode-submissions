class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int area=0;
        int ans=0;
        while(i<j){
            area=min(heights[i],heights[j])*(j-i);
            if(heights[j]>heights[i]){
                i++;
                
            }else{
                j--;
            }
            ans=max(ans,area);  
        }
        return ans;
        
    }
};
