#pragma once
#include "device.h"

class Laptop : public Device {
private:
    int storage; // in GB

public:
    Laptop(const std::string& brand, const std::string& model, const std::string& OS, double screen_size, int memory, int storage);

    std::string ShowInfo() const override;
    std::string Start() const override;
    std::string Shutdown() const override;
    
    std::string InstallSoftware(int size);

    int getStorage() const { return storage; }
};