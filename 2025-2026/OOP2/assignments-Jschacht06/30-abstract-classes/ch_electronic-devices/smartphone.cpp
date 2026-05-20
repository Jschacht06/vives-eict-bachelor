#include "smartphone.h"
#include <string>

Smartphone::Smartphone(const std::string& brand, const std::string& model, const std::string& OS, double screen_size, int memory, double battery_capacity, const std::string& isp)
    : Device(brand, model, OS, screen_size, memory), battery_capacity(battery_capacity), isp(isp) 
{
    this->current_battery = battery_capacity; 
}

std::string Smartphone::ShowInfo() const {
    return Device::ShowInfo() + 
           "\n Battery: " + std::to_string((int)current_battery) + "/" + std::to_string((int)battery_capacity) + " mAh" +
           "\n ISP: " + isp;
}

std::string Smartphone::Start() const {
    return "The Smartphone " + getBrand() + " is turning on. Searching for " + isp + " network...";
}

std::string Smartphone::Shutdown() const {
    return "The Smartphone is turning off.";
}

std::string Smartphone::ChargeBattery(double amount) {
    current_battery += amount;
    if (current_battery >= battery_capacity) {
        current_battery = battery_capacity;
        return "Battery fully charged at " + std::to_string((int)battery_capacity) + " mAh.";
    }
    return "Charging... Current level: " + std::to_string((int)current_battery) + " mAh.";
}

std::string Smartphone::MakeCall() {
    double drain = 200.0; 
    if (current_battery < drain) {
        return "Battery too low to make a call!";
    }
    
    current_battery -= drain;
    std::string msg = "Calling... Call ended.";
    
    if (current_battery < (battery_capacity * 0.2)) {
        msg += "\n WARNING: Battery low (" + std::to_string((int)current_battery) + " mAh).";
    }
    return msg;
}