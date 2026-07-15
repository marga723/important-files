#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Patient {
private:
    int patientID;
    string name;
    string address;
    
public:
    Patient(int id, const string& name, const string& address)
        : patientID(id), name(name), address(address) {}
    
    int getID() const { return patientID; }
    string getName() const { return name; }
    string getAddress() const { return address; }
    
    void display() const {
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }
};

class Bill {
private:
    int patientID;
    double amount;
    string description;
    
public:
    Bill(int id, double amount, const string& description)
        : patientID(id), amount(amount), description(description) {}
    
    int getPatientID() const { return patientID; }
    double getAmount() const { return amount; }
    string getDescription() const { return description; }
    
    void display() const {
        cout << "Patient ID: " << patientID << endl;
        cout << "Amount: $" << amount << endl;
        cout << "Description: " << description << endl;
    }
};

class BillingSystem {
private:
    vector<Patient> patients;
    vector<Bill> bills;
    
public:
    void addPatient(const Patient& patient) {
        patients.push_back(patient);
    }
    
    void addBill(const Bill& bill) {
        bills.push_back(bill);
    }
    
    void displayPatient(int id) const {
        for (const auto& patient : patients) {
            if (patient.getID() == id) {
                patient.display();
                return;
            }
        }
        cout << "Patient not found!" << endl;
    }
    
    void displayBillsForPatient(int id) const {
        bool found = false;
        for (const auto& bill : bills) {
            if (bill.getPatientID() == id) {
                bill.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No bills found for this patient!" << endl;
        }
    }
};

int main() {
    BillingSystem system;
    
    // Adding some patients
    system.addPatient(Patient(1, "John Doe", "123 Elm Street"));
    system.addPatient(Patient(2, "Jane Smith", "456 Oak Avenue"));
    
    // Adding some bills
    system.addBill(Bill(1, 150.75, "Consultation"));
    system.addBill(Bill(1, 200.00, "X-Ray"));
    system.addBill(Bill(2, 75.50, "Routine Check-up"));
