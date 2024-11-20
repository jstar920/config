#pragma once
#include <memory>
#include <map>
#include <string>
#include <functional>
#include <list>

namespace assure
{
    using AssureTestCasePtr = std::shared_ptr<class AssureTestCase>;
    using AssureTestSuitePtr = std::shared_ptr<class AssureTestSuite>;
    using AssureConfigPtr = std::shared_ptr<class AssureConfig>;
    using AssertInfoPtr = std::shared_ptr<class AssertInfo>;
    using TestFunc = std::function<void()>;

    class AssureSession
    {
    public:
        static AssureSession& getInstance();
    private:
        AssureSession();
    public:
        AssureConfigPtr config();
        bool excute();
        void addTest(const std::string& testCaseName, const std::string& testSuiteName, const TestFunc& func);
        void addAssertInfo(const AssertInfoPtr& assertInfo);
    private:
        AssureConfigPtr config_;
        std::map<std::string, AssureTestSuitePtr> testSuites_;
        std::list<AssertInfoPtr> assertInfos_;
    };
}