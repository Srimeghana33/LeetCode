class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector <int> candies(n,1);   //initially all will have one candy

        for(int i=1;i<n;i++){          //from left
            if(ratings[i]>ratings[i-1]){
                candies[i]=candies[i-1]+1;
            }
        } 
        for(int j=n-2;j>=0;j--){
            if(ratings[j]>ratings[j+1]){        //from right
                candies[j]=max(candies[j],candies[j+1]+1);    //max(left,right)
            }
        } 
        int total=0;
        for(int i=0;i<n;i++){
            total+=candies[i];
        }
        return total;
    }
};