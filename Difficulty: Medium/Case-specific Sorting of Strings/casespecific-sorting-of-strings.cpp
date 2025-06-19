class Solution {
  public:
    string caseSort(string& s) {
        // code here
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        
        // s= GEekS
        // sorted = EGSek;
        
        int lowerStart = 0;
        
        for(int i = 0;i < sorted.size(); i++){
            if(sorted[i]>='a'){
                lowerStart = i;
                break;
            }
        }
        
        //to keep track of where upper and lower start in sorted
        int m = 0, n = lowerStart; 
        
        
        int k = 0; //to traverse s
        
        for(int i = 0; i < s.size(); i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i] = sorted[m];
                m++;
            } else {
                s[i] = sorted[n];
                n++;
            }
        }
        
        return s;
    }
};