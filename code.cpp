/*Header Files */
#include<bits/stdc++.h>
using namespace std;

// we will be implementing the whole system using the concept of OOPS.
class SeatReservation {
private:
    // initializing the variables
    unsigned int total_seats;    // Total number of seats 
    int available_seat;          // Number of available seats
    vector<unsigned int> reserved_seats; // Array to store the initial availability of seat per row (unsigned vector)

public:
    vector<int> reserved_seats; // array to store the initial availability of seat per row.
    // using constructor to initialize the variables as per the problem
    SeatReservation() {
        total_seats = 80;
        available_seat= total_seats;
        reserved_seats.resize(13,3); // array has a total of 13 cells are all are initialized to 3.
        fill(reserved_seats.begin(),reserved_seats.end()-1,7); // each cell is filled with 7 denoting the available seats except the last cell.
    }
    // Function to display the number of available seats
    void display_seats() {
        cout << "Available Seats row-wise:" << "\n";
        // we are displaying the seats row-wise.
        for(int i=1;i<reserved_seats.size();i++)
        {
            cout<<"At row "<<i<<" Available seats are :"<<reserved_seats[i]<<"\n";
        }
    }
    void reserve_seats(int n) 
    {
        // check if seats are already occupied or not
        if (n > available_seat) {
            cout << "Sorry, there are not enough seats available." << endl;
            return;
        }   
        bool isConsecutive = false; //this will ensure if the seats are occupied or not.
        while(n>0)
        {
            for (int i = 1; i < reserved_seats.size(); i++) {
            if (reserved_seats[i] >= n) { // check if we have enough seats to allocated consecutively or not
                reserved_seats[i] = reserved_seats[i] - n;
                n=0;
                isConsecutive = true; 
                break;
            }
        }
        if (!isConsecutive) 
        { 
            // this is the condition where we can't allocate the seats consecutively in a single row so, we try to allocate the seats accoringly with space available
            for (int i = 1; i < reserved_seats.size(); i++) {
                if (reserved_seats[i] > 0 && n > reserved_seats[i]) {
                    n = n - reserved_seats[i];
                    reserved_seats[i] = 0;
                }
            }
        } else {
            cout << "Successfully allocated the seats" << "\n";
        }
        available_seat = available_seat - n; //updating the available seat

        }
    }
    void available_seats() {
        cout << "Total number of available seats are : " << available_seat << "\n";
    }
};
// Main class
int main() {
    SeatReservation reservation;
    int n;
    cout<<"Enter the number of seats that needs to be booked"<<"\n";
    cin>>n;
    reservation.reserve_seats(n);
    reservation.display_seats();

    reservation.available_seats();

    return 0;
}
