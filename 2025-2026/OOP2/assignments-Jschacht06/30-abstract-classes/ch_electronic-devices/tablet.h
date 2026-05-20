#pragma once
#include "device.h"

class Tablet : public Device {
private:
    double battery_capacity;
    double current_battery;

public:
    Tablet(const std::string& brand, const std::string& model, const std::string& OS, double screen_size, int memory, double battery_capacity);

    std::string ShowInfo() const override;
    
    std::string ChargeBattery(double amount);
    std::string WatchMovie();
};