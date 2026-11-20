class Solution {
public:
    bool caneatall(vector<int>& piles, int mid,int h){
        int max_hour=0;
        for(int i=0;i<piles.size();i++){
            max_hour+=piles[i]/mid;
            if(piles[i]%mid!=0){
                max_hour++;
            }
        }
        return max_hour<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      int l=1,r=INT_MIN;
      for(int i=0;i<piles.size();i++){
        if(piles[i]>r){
            r=piles[i];
        }
      }
      while(l<r){
        int mid=(l+r)/2;
        if(caneatall(piles,mid,h)){
            r=mid;
        }
        else{
            l=mid+1;
        }
      }
      return l;  
    }
};