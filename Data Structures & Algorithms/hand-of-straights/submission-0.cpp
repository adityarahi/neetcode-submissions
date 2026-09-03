class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        int &k = groupSize;
        if(n % k) return false;
        unordered_map<int,int> freq;
        for(int& card: hand) { freq[card]++; }
        for(int& card : hand) {
            int start_card = card;
            while(freq[start_card - 1]) start_card--;
            while(start_card <= card) {
                while(freq[start_card]) {
                    for(int next_card = start_card; next_card < start_card + k; next_card++) {
                        if(!freq[next_card]) return false;
                        freq[next_card]--;
                    }
                }
                start_card++;
            }
        }
        return true;
    }
};
