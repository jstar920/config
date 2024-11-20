#pragma once
#include <string>
#include <functional>
#include <memory>
#include <map>


namespace assure
{
    using TestFunc = std::function<void()>;
    class AssureTestSuite;
    using AssureConfigPtr = std::shared_ptr<class AssureConfig>;
    class AssureTestCase
    {
    public:
        AssureTestCase(const std::string& name, const TestFunc& func, const AssureConfigPtr& config);

        void excute();
        const std::string& caseName();
    private:
        void log(const std::string& info);
    private:
        std::string caseName_;
        TestFunc testFunc_;
        AssureConfigPtr config_;
    };
    using AssureTestCasePtr = std::shared_ptr<AssureTestCase>;

    class AssureTestSuite
    {
    public:
        AssureTestSuite(const std::string& name, const AssureConfigPtr& config);
        void excute();
        void addTest(const AssureTestCasePtr& testCase);
    public:
        void log(const std::string& info);
    private:
        std::string suiteName_;
        std::map<std::string, AssureTestCasePtr> testCases_;
        AssureConfigPtr config_;
    };
}

