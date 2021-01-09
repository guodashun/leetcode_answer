class ExamRoom {
public:
    ExamRoom(int N) {
        this->N = N;
    }

    int seat() {
        int seat = 0;
        if (seats.size() > 0) {
            // Try first seat
            int dist = *seats.begin();
            int pre = -1;
            for (const auto& s : seats) {
                if (pre != -1) {
                    int d = (s - pre) / 2;
                    // Find a seat that farther
                    if (d > dist) {
                        dist = d;
                        seat = pre + d;
                    }
                }
                pre = s;
            }

            // Consider the right most seat
            if (N - 1 - *seats.rbegin() > dist) {
                seat = N - 1;
            }
        }

        seats.insert(seat);
        return seat;
    }
    
    void leave(int p) {
        seats.erase(p);
    }

private:
    int N;
    set<int> seats;
};

// 小便池问题
