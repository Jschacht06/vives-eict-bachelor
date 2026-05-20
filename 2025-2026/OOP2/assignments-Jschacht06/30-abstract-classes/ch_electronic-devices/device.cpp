#include "device.h"
#include <string>

Device::Device(const std::string& brand, const std::string& model, const std::string& OS, double screen_size, int memory)
    : brand(brand), model(model), OS(OS), screen_size(screen_size), memory(memory) 
{
}

std::string Device::Start() const {
    return "The device " + brand + " " + model + " is starting up.";
}

std::string Device::Shutdown() const {
    return "The device " + brand + " " + model + " is shutting down.";
}

std::string Device::ShowInfo() const {
    return "Device Info:\n Brand: " + brand + 
           "\n Model: " + model + 
           "\n OS: " + OS +
           "\n Screen Size: " + std::to_string(screen_size) + " inches" +
           "\n Memory: " + std::to_string(memory) + " GB";
}