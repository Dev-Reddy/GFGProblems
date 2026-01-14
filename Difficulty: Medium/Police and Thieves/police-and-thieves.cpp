class Solution {
  public:
     int catchThieves(vector<char> &arr, int k) {
        vector<int> police; //create new array to store index of police
        vector<int> thief;
        
        //dono ke indexes alag alg array me store kar liya
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 'P'){
                police.push_back(i);
            }else{
                thief.push_back(i);
            }
        }
        
        //ab dono list ko traverse krenge
        int x = 0, y = 0;
        int caught = 0;
        
        while(x < police.size() && y < thief.size()){
            if(abs(police[x] - thief[y]) <= k){//agar distance <= k hai toh pakad lo
                caught++;
                x++;
                y++;
            }else if(thief[y] < police[x]){// thief police se pehle hai aur door hai -> thief pointer aage badhao
                y++;
            }else{//// police thief se pehle hai aur door hai -> police pointer aage badhao
                x++;
            }
        }
        return caught;
    }
};