1)Brute approach : 
using stl sort() function 
class Solution{
public:
    int missingNumber(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        int i=0;
        for( ; i<nums.size(); i++ ){
            if( nums[i] != i ) 
                return i;
        }
        return i;
    }
};


2) Optimal Approach :
 Intuition : find sum of first n natural number 
 and then find sum of array 
then difference between the two sums is the missing number .


class Solution{
public:
    int missingNumber(vector<int>& nums) {
       int n = nums.size();
       int sum1 = (n*(n+1)) / 2;
       int sum2 = 0;
       for( int i=0; i<n; i++ ){
           sum2 += nums[i];
       }
       return sum1 - sum2;
    }
};

