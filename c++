#include <iostream>
#include <string>
using namespace std;

class Gym {
private:
    int id[50], age[50], months[50];
    string name[50];
    bool attendance[50];
    int count = 0;

public:
    void addMember() {
        if (count >= 50) {
            cout << "Gym is full!\n";
            return;
        }

        cout << "Enter Member ID: ";
        cin >> id[count];

        cout << "Enter Name: ";
        cin >> name[count];

        cout << "Enter Age: ";
        cin >> age[count];

        cout << "Enter Membership Months: ";
        cin >> months[count];

        if (age[count] <= 0 || months[count] <= 0) {
            cout << "Invalid age or membership duration!\n";
            return;
        }

        attendance[count] = false;

        cout << "Member Added Successfully!\n";
        cout << "Membership Fee: Rs. "
             << months[count] * 1000 << "\n";

        count++;
    }

    void displayMembers() {
        if (count == 0) {
            cout << "No members registered.\n";
            return;
        }

        for (int i = 0; i < count; i++) {
            cout << "\nID: " << id[i]
                 << "\nName: " << name[i]
                 << "\nAge: " << age[i]
                 << "\nMonths: " << months[i]
                 << "\nFee: Rs. " << months[i] * 1000
                 << "\nAttendance: "
                 << (attendance[i] ? "Present" : "Absent")
                 << "\n";
        }
    }

    void searchMember() {
        int searchID;
        cout << "Enter Member ID: ";
        cin >> searchID;

        for (int i = 0; i < count; i++) {
            if (id[i] == searchID) {
                cout << "Member Found!\n";
                cout << "Name: " << name[i] << "\n";
                cout << "Age: " << age[i] << "\n";
                cout << "Months: " << months[i] << "\n";
                return;
            }
        }

        cout << "Member Not Found!\n";
    }

    void markAttendance() {
        int searchID;
        cout << "Enter Member ID: ";
        cin >> searchID;

        for (int i = 0; i < count; i++) {
            if (id[i] == searchID) {
                attendance[i] = true;
                cout << "Attendance Marked!\n";
                return;
            }
        }

        cout << "Member Not Found!\n";
    }

    void totalIncome() {
        int total = 0;

        for (int i = 0; i < count; i++) {
            total += months[i] * 1000;
        }

        cout << "Total Membership Fees: Rs. "
             << total << "\n";
    }
};

int main() {
    Gym g;
    int choice;

    do {
        cout << "\n--- Gym Management System ---\n";
        cout << "1. Add Member\n";
        cout << "2. Display Members\n";
        cout << "3. Search Member\n";
        cout << "4. Mark Attendance\n";
        cout << "5. Total Income\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.addMember();
                break;
            case 2:
                g.displayMembers();
                break;
            case 3:
                g.searchMember();
                break;
            case 4:
                g.markAttendance();
                break;
            case 5:
                g.totalIncome();
                break;
            case 0:
                cout << "Exiting Program...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 0);

    return 0;
}
