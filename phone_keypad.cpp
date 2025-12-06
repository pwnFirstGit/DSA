class Solution {

private: 

    void solve( string digit, string op, int idx, vector<string>& ans,  string mapping[] ){

        //base case
        if( idx >= digit.length()){
            ans.push_back(op);
            return ;
        }

        //processing
        int num = digit[idx] - '0';
        string value = mapping[num];

        for(int i=0; i<value.length(); i++){
            op.push_back(value[i]);
            solve( digit, op, idx+1, ans, mapping );  //recursive call
            op.pop_back();
        }

    }

public:
    vector<string> letterCombinations(string digits) {
        
         vector<string>ans;

         if( digits.length() == 0 ){
            return ans;
        }
       

        string mapping[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
        int idx = 0;

        string op = "";

        solve( digits, op, idx, ans, mapping );

        return ans;

       
        
    }
};
