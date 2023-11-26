

/*

 link:  https://leetcode.com/problems/3sum-closest/
  


*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int mn=100000,n=nums.size();    
        sort(nums.begin(),nums.end());

        for(int k=0;k<n-2;k++){
           int i=k+1,j=n-1;

            while(i<j){
                int sum =nums[i]+nums[j]+nums[k];
                if(abs(target-sum) < abs(target-mn))mn=sum;        
                if(sum>target)j--;
                else i++;     
            }
            
        }

        return mn;

    }
};