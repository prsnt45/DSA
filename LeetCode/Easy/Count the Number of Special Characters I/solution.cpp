class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        for(char i = 'a'; i <= 'z'; i++){
            bool lower = false;
            bool upper = false;

            for( int j = 0; j < word.size(); j++){
                if(word[j] == i){
                    lower = true;   
                }
                if( word[j] == i -32)
                upper = true;

            }
            if( upper && lower)
            count ++;
        }
        return count;
        
    }
};