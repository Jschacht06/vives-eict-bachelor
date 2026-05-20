#pragma once
#include <string>

class Device {
private:
    std::string brand;
    std::string model;
    std::string OS;
    double screen_size;
    int memory; 

public:
    // Constructor
    Device(const std::string& brand, const std::string& model, const std::string& OS, double screen_size, int memory);
    
    // destructor
    virtual ~Device() = default;

    
    virtual std::string Start() const;
    virtual std::string ShowInfo() const;
    virtual std::string Shutdown() const;

    
    const std::string& getBrand() const { return brand; }
    const std::string& getModel() const { return model; }
    const std::string& getOS() const { return OS; }
    double getScreenSize() const { return screen_size; }
    int getMemory() const { return memory; }
};
