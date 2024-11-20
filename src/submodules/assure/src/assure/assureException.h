#pragma once
#include <exception>

namespace assure
{
    class AssureTestCaseFailed : public std::exception
    {
    public:
        AssureTestCaseFailed() = default;
    private:
    };
}
