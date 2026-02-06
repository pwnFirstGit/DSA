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


*******SOLUTION 3 : *********

    Moore's voting algorithm.
    algo : 
    Traverse the array:

    If votes == 0, set candidate = arr[i] and votes = 1.
    If arr[i] == candidate, increment votes.
    Otherwise, decrement votes.

explaination : Imagine people in a room raising cards with numbers.
You walk through the room keeping one card (the candidate) and a small counter:

If your counter is zero, you pick the current person’s card as your candidate and set counter = 1.

If the next person has the same card, you increase the counter (that’s more votes for the candidate).

If they have a different card, you decrease the counter (one vote cancels one of the candidate’s votes).
At the end of the walk, whatever card you’re holding is the candidate. If one number truly appears more than half the time, that card will survive.





    class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
    int count = 0;
    int candidate = -1;
    for( int i=0; i<nums.size(); i++ ){
        if( count == 0 ){
            candidate = nums[i];
            count = 1;
        }
        else if( nums[i] == candidate ){
            count++;
        }
        else{
            count--;
        }
    }

    return candidate;


    }
};
