#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm> 

using namespace std;

class Ticket {
protected:
    string passengerName;
    string ticketType;
    string destination;
    int numberOfTickets;
    float totalFare;
    float moneyInput;
    float change;
    vector<string> destinations = {"Uttara North","Uttara Center", "Uttara South", "Pallabi", "Mirpur-11", "Mirpur-10", 
                                   "Kazipara", "Shewrapara", "Agargaon", "Bijoy Sarani", "Farmgate",
                                   "Karwan Bazar ", "Shahbagh", "Dhaka University", "Bangladesh Secretariat", "Motijheel"};

public:
    virtual void calculateFare() = 0;

    void bookTicket() {
        cout << "Enter your name: ";
        getline(cin, passengerName);
         
        cout << "Choose your destination:\n";
        for (int i = 0; i < destinations.size(); ++i) {
            cout << i + 1 << ". " << destinations[i] << endl;
        }
        int choice;
        cout << "Enter the number corresponding to your destination: ";
        cin >> choice;
        if (choice < 1 || choice > destinations.size()) {
            cout << "Invalid choice. Please restart the booking process.\n";
            exit(1);
        }
        destination = destinations[choice - 1];
        
        cout << "Enter the number of tickets: ";
        cin >> numberOfTickets;
        
        calculateFare();
        cout << "Your total amount is: $" << fixed << setprecision(2) << totalFare << endl;
        cout << "Enter the amount of money you are paying: ";
        cin >> moneyInput;
        
        change = moneyInput - totalFare;
    }

    void displayTicket(){
        cout << "\n--- Metro Ticket ---\n";
        cout << "Name: " << passengerName << endl;
        cout << "Ticket Type: " << ticketType << endl;
        cout << "Destination: " << destination << endl;
        cout << "Number of Tickets: " << numberOfTickets << endl;
        cout << "Total Fare: $" << fixed << setprecision(2) << totalFare << endl;
        cout << "Money Paid: $" << fixed << setprecision(2) << moneyInput << endl;
        cout << "Change: $" << fixed << setprecision(2) << change << endl;
        cout << "--------------------\n";
    }
};

class MetroTicket : public Ticket {
public:
    MetroTicket() {
        ticketType = "Single";
    }

    void calculateFare() override {
        int index = find(destinations.begin(), destinations.end(), destination) - destinations.begin();
        float ticketPrice;

        if (index < 2) ticketPrice = 20.0;
        else if (index < 4) ticketPrice = 30.0;
        else if (index < 6) ticketPrice = 40.0;
        else if (index < 11) ticketPrice = 50.0;
        else if (index < 13) ticketPrice = 60.0;
        else if (index < 14) ticketPrice = 70.0;
        else if (index < 15) ticketPrice = 80.0;
        else ticketPrice = 100.0;

        totalFare = numberOfTickets * ticketPrice;
    }
};

class GroupTicket : public Ticket {
public:
    int groupSize;

    GroupTicket() {
        ticketType = "Group";
    }

    void book() {
        Ticket::bookTicket();
        cout << "Enter the number of group members: ";
        cin >> groupSize;
        if (groupSize > 6) {
            cout << "Group size should be less than 6.\n";
            exit(1);
        }
        calculateFare();
    }

    void calculateFare() override {
        int index = find(destinations.begin(), destinations.end(), destination) - destinations.begin();
        float ticketPrice;

        if (index < 2) ticketPrice = 20.0;
        else if (index < 4) ticketPrice = 30.0;
        else if (index < 6) ticketPrice = 40.0;
        else if (index < 11) ticketPrice = 50.0;
        else if (index < 13) ticketPrice = 60.0;
        else if (index < 14) ticketPrice = 70.0;
        else if (index < 15) ticketPrice = 80.0;
        else ticketPrice = 100.0;

        totalFare = numberOfTickets * ticketPrice * groupSize;
    }
};

int main() {
    string ticketType;
    cout << "                         WELCOME TO DHAKA METRO " << endl;
    cout << "Enter ticket type (Group/Single): ";
    cin >> ticketType;
    cin.ignore();

    Ticket* ticket;
    if (ticketType == "Group") {
        ticket = new GroupTicket();
        static_cast<GroupTicket*>(ticket)->book();
    } else {
        ticket = new MetroTicket();
        ticket->bookTicket();
    }

    ticket->displayTicket();
    delete ticket;

    return 0;
}
