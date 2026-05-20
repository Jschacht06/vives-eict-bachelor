#pragma once
#include "device.h"

class Smartphone : public Device {
private:
    double battery_capacity; 
    double current_battery;  
    std::string isp; 

public:
    Smartphone(const std::string& brand, const std::string& model, const std::string& OS, double screen_size, int memory, double battery_capacity, const std::string& isp);

    std::string ShowInfo() const override;
    std::string Start() const override;
    std::string Shutdown() const override;
    
    
    std::string ChargeBattery(double amount);
    std::string MakeCall();
};