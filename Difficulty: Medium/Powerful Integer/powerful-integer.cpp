class Solution {
    static bool comp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        priority_queue<int> pq;
        for(int i=n-1;i>=0;i--){
            while(!pq.empty() && pq.top()>intervals[i][1]){
                pq.pop();
            }
            pq.push(intervals[i][0]);
            if(pq.size()>=k) return intervals[i][1];
        }
        return -1;
    }
}; 