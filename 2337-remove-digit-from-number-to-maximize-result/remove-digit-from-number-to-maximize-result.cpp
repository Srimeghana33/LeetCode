class Solution {
public:
    string removeDigit(string number, char digit) {
        for(int i=0;i<number.size();i++){
            if(number[i]==digit && number[i]<number[i+1]){
                number.erase(i,1);
                return number;
            }
        }
        for(int i=number.size()-1;i>=0;i--){
            if(number[i]==digit && number[i]>number[i+1]){
                number.erase(i,1);
                break;
            }
        }
        return number;
    }
};