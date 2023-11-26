/*

link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

intution : we add two number their sum is equal to target and Array is sorted so, we used two Pointer.

Approach: two Pointer

Time complexity:O(n),n:number of element
Space complexity:O(n),n:number of element

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int i=0,j=numbers.size()-1;

        while(i<j){
              if(numbers[i]+numbers[j]==target)return {i+1,j+1};
              else if(numbers[i]+numbers[j] >target)j--;
              else i++;
        }
        return {-1,-1};
        
    }
};