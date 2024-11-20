#pragma once
#include <functional>
#include <string>

namespace assure
{
    using LogCallback = std::function<void(const std::string&)>;
    class AssureConfig
    {
    public:
        void setLogCallback(const LogCallback& callback);
        LogCallback logCallback() const;
    private:
        LogCallback logCallback_;
    };
}