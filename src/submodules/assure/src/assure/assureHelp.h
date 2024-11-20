#pragma once
#include <sstream>
#include <functional>

namespace assure
{
    using TestFunction = std::function<void(const std::string&, const std::string&)>;

    static inline std::string bool2str(bool value)
    {
        return value ? "true" : "false";
    }

    template<typename T>
    static inline std::stringstream& operator<< (std::stringstream&& ss, T value)
    {
        ss << "(...)";
        return ss;
    }

    static inline void print(const std::string& info);

    int createTestCase(const std::string& caseName, const std::string& suiteName, TestFunction func);
    using AssertInfoPtr = std::shared_ptr<class AssertInfo>;
    void handleAssertInfo(const AssertInfoPtr& info);
    void handleSuccess();
}
