class Solution {
public:

    void sort( vector<int> &nums, int n, int start ){
        
        if( start >= n-1 ){
            return ;
        }
        
        int min_idx = start;
        for(int i=min_idx+1; i<n; i++){
            if( nums[i] < nums[min_idx] ){
                min_idx = i;
            }
        }


        swap( nums[start],nums[index] );

        sort( nums, n , start+1 );

    }

    vector<int> sortArray(vector<int>& nums) {

         //selection sort
        int size = nums.size();
        sort(nums,size,0);
        return nums;

    }
};
