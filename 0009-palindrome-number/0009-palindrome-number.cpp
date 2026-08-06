class Solution {
public:
    bool isPalindrome(int x) {
        string digits = to_string(x);

        if(digits.size()==1) return true;
        if(digits[0] == '-') return false;
        int left = 0;
        int right = digits.size()-1;

        while(left<right){

            if(digits[left] != digits[right]){
              return false;
            }
            left++;
            right--;

        }

        return true;


    
        
    }
};