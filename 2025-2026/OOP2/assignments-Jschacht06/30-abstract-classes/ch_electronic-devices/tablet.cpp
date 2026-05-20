#include "Tablet.h"
#include <string>

Tablet::Tablet(const std::string& brand, const std::string& model, const std::string& OS, double screen_size, int memory, double battery_capacity)
    : Device(brand, model, OS, screen_size, memory), battery_capacity(battery_capacity)
{
    this->current_battery = battery_capacity;
}

std::string Tablet::ShowInfo() const {
    return Device::ShowInfo() + "\n Battery: " + std::to_string((int)current_battery) + " mAh (Tablet)";
}

std::string Tablet::ChargeBattery(double amount) {
    current_battery += amount;
    if (current_battery >= battery_capacity) {
        current_battery = battery_capacity;
        return "Tablet battery fully charged.";
    }
    return "Tablet charging. Level: " + std::to_string((int)current_battery);
}

std::string Tablet::WatchMovie() {
    double drain = 500.0; 
    if (current_battery < drain) {
        return "Not enough battery to watch a movie.";
    }
    
    current_battery -= drain;
    std::string msg = "Watching movie... Entertaining!";
    
    if (current_battery < (battery_capacity * 0.2)) {
        msg += "\n WARNING: Low battery!";
    }
    return msg;
}