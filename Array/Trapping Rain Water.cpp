
/*
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

 Intution behind this question is find area between leftmost maximum and rightmost maximum block .

# Approach
<!-- Describe your approach to solving the problem. -->

approach behind this question is how much water stored between the blocks. On first block and last block does not store water .so,find the stored water beetween them .
to find stored water between block we find the minimum of leftmost max block and rightmost block and substract the height of block;


w(i)= min(leftmostmax(i),rightmostmax(i))-height(i);

to leftmostmax and rightmostmax we take two vector left and right ;


# Complexity

- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

we iterate over vector once so the time complexity : O(n)
n: number of element in vector

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

we take two vector of size equal to number of elemnt in vector ;
so space complexity : O(n) where n :number of element.

 */

class Solution {
public:
 
 vector<int>  leftmax(vector<int>& height){
       int n=height.size();
        int mn=INT_MIN;
        vector<int>ans (n);

        for(int i=0;i<height.size();i++){
             ans[i]=max(mn,height[i]);
             mn=ans[i];
        }

        return ans;
  }


  vector<int> rightmax(vector<int>&height){
       int n=height.size();
       vector<int>ans(n) ;
       ans[n-1]=height[n-1];

      for(int i=n-2;i>=0;i--){
          ans[i]=max(height[i],ans[i+1]);      
      }

      return ans;
 }


    int trap(vector<int>& height) {
        
        int ans=0;
        vector<int> left=leftmax(height);
        vector<int>  right=rightmax(height);

        for(int i=1;i<height.size()-1;i++){
             ans+=min(left[i],right[i])-height[i];
        }

        return ans ;
    }
};