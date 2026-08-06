class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char , int > map;
        int left = 0;


        for(char x : s){
            map[x]++;
            left++;
        }


        for(char a : t ){
            if(map[a] >0) {
                map[a]--;
                left--;
            }
            else {
                return false;
            }
        }

        

        return   (left>0) ? false : true;





        
    }
};