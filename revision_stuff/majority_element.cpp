*******SOLUTION 1 : *********

explanation :  this is brute solution using unordered_map 
T.C. -> O(N)
S.C. -> O(N)

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int,int>map;
        for( int i=0; i<nums.size(); i++ ){
            map[nums[i]]++;
        }

        int i=0;
        int largest = INT_MIN;
        int ans = 0;
        for( auto i :  map  ){
            if( i.second > largest ){
                largest = i.second;
                ans = i.first;
            }
        }

        return ans;
        
    }
};


*******SOLUTION 2 : *********

This solution consist of sorting first using sort() stl function , then traversing an array in O(N) t.c.
  T.C. -> O(NlogN)
  S.C. -> O(logN)

  class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort ( nums.begin(), nums.end() );
        int count = 1;
        int n = nums.size();
        for( int i=1; i<n; i++){
            if( nums[i] == nums[i-1] ){
                count++;
            }
            else{
                if( count > n/2 ){
                    return nums[i-1];
                }
                else{
                    count = 1;
                }
            }
        }
        return nums[n-1];
    }
};
