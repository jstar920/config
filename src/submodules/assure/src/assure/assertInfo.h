#pragma once
#include <string>

namespace assure
{
    struct AssureParameter
    {
      std::string caseName;
      std::string testSuiteName;
      std::string fileName;
      int lineNo {0};
      std::string functionName;
    };

    class AssertInfo
    {
    public:
        AssertInfo() = delete;
        AssertInfo(const AssureParameter& parameter);
        void setExpectedInfo(const std::string& info);
        std::string getExpectedInfo() const;
        void setActualInfo(const std::string& info);
        std::string getActualInfo() const;
        const AssureParameter& getParameter() const;
    private:
        AssureParameter parameter_;
        std::string expectedInfo_;
        std::string actualInfo_;
    };
}
