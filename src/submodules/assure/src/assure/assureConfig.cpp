#include "assureConfig.h"
#include <iostream>

namespace assure
{
    void AssureConfig::setLogCallback(const LogCallback& callback)
    {
        logCallback_ = callback;
    }

    LogCallback AssureConfig::logCallback() const
    {
        return logCallback_ ? logCallback_ : [](const std::string& logInfo){ std::cout << logInfo << std::endl;};
    }
}