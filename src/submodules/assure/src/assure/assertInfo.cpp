#include "assertInfo.h"
namespace assure
{
    AssertInfo::AssertInfo(const AssureParameter& parameter)
    : parameter_(parameter)
    {
    }

    void AssertInfo::setExpectedInfo(const std::string& info)
    {
        expectedInfo_ = info;
    }

    std::string AssertInfo::getExpectedInfo() const
    {
        return expectedInfo_;
    }

    void AssertInfo::setActualInfo(const std::string& info)
    {
        actualInfo_ = info;
    }

    std::string AssertInfo::getActualInfo() const
    {
        return actualInfo_;;
    }

    const AssureParameter& AssertInfo::getParameter() const
    {
        return parameter_;
    }
}
