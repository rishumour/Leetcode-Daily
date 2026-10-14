class BusBooking {
    int current_total;
    int booked_count;
    vector<int> seat_cost;

public:
    BusBooking(int n) : current_total(0), booked_count(0), seat_cost(4 * (n + 1), 0) {}
    
    void toggle(string seat) {
        int col = seat[0] - 'A';
        int row = stoi(seat.substr(1));
        int idx = (row << 2) | col;
        
        if (seat_cost[idx] > 0) {
            current_total -= seat_cost[idx];
            seat_cost[idx] = 0;
            booked_count--;
        } else {
            int cost = 1;
            if (col == 0 && seat_cost[(row << 2) | 1] > 0) {
                cost = 3;
            } else if (col == 3 && seat_cost[(row << 2) | 2] > 0) {
                cost = 3;
            }
            
            seat_cost[idx] = cost;
            current_total += cost;
            booked_count++;
        }
    }
    
    int getTotalTime() {
        return current_total;
    }
    
    int getMinTime() {
        return booked_count;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */