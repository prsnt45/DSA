class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        
        int n = word.size();
        for( char ch = 'a'; ch <= 'z'; ch++){
            for(int i = n-1; i >=0; i--){
                bool lower = false;
                bool valid = false;
                if(word[i]== ch){
                    lower = true;
                    
                    for( int j = i+1; j < n; j++){
                        if(word[j] == ch-32){
                            valid = true;
                            break;
                        }

                    }
                    if(valid){ 
                        for(int j = i-1; j >=0; j--){
                            if(word[j] == ch-32){
                                valid = false;
                                break;
                            }
                        }
                    }
                }
                if(valid){
                    count++;
                    break;
                }
                else if(lower)
                break;
            }
        }
        return count;
    }
};