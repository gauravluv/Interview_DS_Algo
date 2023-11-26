


/*

   link:https://leetcode.com/problems/3sum/

   

    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
    Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

intution : first thought we think is we take three for loop and add the all three number .whose number is equal to target we store in vector.

 second we thought  return the value of input not index .so we sort the input and solve by three pointer approach 

 Approach: we sort the input and fixed the one input index and rest of input index we the two pointer approach.
   nums[i]+nums[j]+nums[k]==0
   nums[j]+nums[k]=0-nums[i];

 in two pointer first pointer is fixed index+1 and second pointer is last index-1;
 if(fixed index+first pointer +second pointer =target) then we add into vector ,else if(fixed index+first pointer +second pointer >target)  then we decrease the sum value by decreasing second pointer else   we increaing the first pointer 
 
 we do that until we reached (last index - 3) .

 second one is also handle the duplicate.

 time complextity: we sort the input  then  O(nlogn) and  we iterate over input O(n^2) maximum . Time complexity at maximum input size is O(nLogn);

 Space complexity: O(1);

*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
      
     vector<vector<int>>ans;
     sort(nums.begin(),nums.end());

       for(int k=0;k<nums.size()-2;k++){

             if(k==0 || (k>0 && nums[k]!=nums[k-1])){
                   int i=k+1,j=nums.size()-1;
                   int target= 0-nums[k];

                 while(i<j){

                        if(nums[i]+nums[j]==target){
                             while( i<j && nums[i]==nums[i+1])i++;
                             while(i<j && nums[j]==nums[j-1])j--;
                             vector<int>temp;
                             temp.push_back(nums[k]);
                             temp.push_back(nums[i]);
                             temp.push_back(nums[j]);
                             ans.push_back(temp);
                             i++;
                             j--;
                        }else if(nums[i]+nums[j]>target)j--;
                          else i++;
                   }
             }

       }

       return ans ;

    }
};

