#include <iostream>
#include <vector>
#include "device.h"
#include "Laptop.h"
#include "smartphone.h"
#include "Tablet.h"

using namespace std;

int main() {
    
    vector<Device*> devices;

    devices.push_back(new Laptop("Dell", "XPS 15", "Windows 11", 15.6, 16, 512));
    devices.push_back(new Laptop("Apple", "MacBook Pro", "MacOS", 14.2, 32, 1000));
    
    devices.push_back(new Smartphone("Samsung", "Galaxy S23", "Android", 6.1, 8, 3900, "Telenet"));
    devices.push_back(new Smartphone("Apple", "iPhone 14", "iOS", 6.1, 6, 3279, "Proximus"));
    
    devices.push_back(new Tablet("Apple", "iPad Air", "iPadOS", 10.9, 8, 7600));
    devices.push_back(new Tablet("Samsung", "Galaxy Tab S8", "Android", 11.0, 8, 8000));

    cout << "--- ELECTRONIC DEVICES MANAGER ---" << endl;

    for (Device* d : devices) {
        cout << "\n-----------------------------------" << endl;
        
        
        cout << d->Start() << endl;
        cout << d->ShowInfo() << endl;

        
        Laptop* lap = dynamic_cast<Laptop*>(d);
        if (lap != nullptr) {
            cout << " [Action] " << lap->InstallSoftware(20) << endl;
            cout << " [Action] " << lap->InstallSoftware(1500) << endl; 
        }

        Smartphone* phone = dynamic_cast<Smartphone*>(d);
        if (phone != nullptr) {
            cout << " [Action] " << phone->MakeCall() << endl;
            cout << " [Action] " << phone->ChargeBattery(500) << endl;
        }

        Tablet* tab = dynamic_cast<Tablet*>(d);
        if (tab != nullptr) {
            cout << " [Action] " << tab->WatchMovie() << endl;
            cout << " [Action] " << tab->ChargeBattery(1000) << endl;
        }
        
        cout << d->Shutdown() << endl;
    }

    
    for (Device* d : devices) {
        delete d;
    }
    devices.clear();

    return 0;
}