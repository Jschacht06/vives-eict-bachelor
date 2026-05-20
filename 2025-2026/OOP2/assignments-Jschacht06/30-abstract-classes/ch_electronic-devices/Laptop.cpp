#include "Laptop.h"
#include <string>

Laptop::Laptop(const std::string& brand, const std::string& model, const std::string& OS, double screen_size, int memory, int storage)
    : Device(brand, model, OS, screen_size, memory), storage(storage) 
{
}

std::string Laptop::ShowInfo() const {
    return Device::ShowInfo() + "\n Storage: " + std::to_string(storage) + " GB";
}

std::string Laptop::Start() const {
    return "The Laptop " + getBrand() + " " + getModel() + " is booting Windows/Linux/MacOS.";
}

std::string Laptop::Shutdown() const {
    return "The Laptop " + getBrand() + " " + getModel() + " is shutting down.";
}

std::string Laptop::InstallSoftware(int size) {
    if (size > storage) {
        return "Error: Not enough storage to install " + std::to_string(size) + " GB software.";
    }
    
    storage -= size;
    std::string msg = "Software installed. Remaining storage: " + std::to_string(storage) + " GB.";
    
    if (storage < 10) {
        msg += "\n WARNING: Storage is running low!";
    }
    return msg;
}