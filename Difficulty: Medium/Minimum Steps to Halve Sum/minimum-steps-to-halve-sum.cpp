class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        double sum = 0;
        priority_queue<double>pq;
        for(int it : arr){
            pq.push(it);
            sum += it;
        }
        double half = sum / 2;
        int steps=0;
        while (!pq.empty()){
            if(sum <= half) break;
            steps++;
            double num = pq.top();
            pq.pop();
            sum -= num;
            num /= 2;
            sum += num;
            pq.push(num);
        }
        return steps;
    }
};