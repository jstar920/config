#include "assureSession.h"
#include "assureTestCase.h"
#include "assureConfig.h"
#include "assertInfo.h"
namespace assure
{
    AssureSession&  AssureSession::getInstance()
    {
        static AssureSession session;
        return session;
    }

    AssureSession::AssureSession()
    : config_(std::make_shared<AssureConfig>())
    {
    }

    std::shared_ptr<AssureConfig> AssureSession::config()
    {
        return config_;
    }

    bool AssureSession::excute()
    {
        for (auto it = testSuites_.cbegin(); it != testSuites_.cend(); ++it)
        {
            it->second->excute();
        }
        const auto log = config_->logCallback();

        if (assertInfos_.empty())
        {
            log("all tests are passed");
        }
        else
        {
            log("\n\nFailed tests:");
            for (const auto& info : assertInfos_)
            {
                const auto& para = info->getParameter();
                log("=================================================================");
                log("testsuits:" + para.testSuiteName + ", testcase:" + para.caseName);
                log(para.fileName + ", line:" + std::to_string(para.lineNo));
                log("--------->Expected:" + info->getExpectedInfo());
                log("=========>Actually:" + info->getActualInfo());
                log("\n");
            }
        }

        return (assertInfos_.size() == 0);
    }

    void AssureSession::addTest(const std::string& testCaseName, const std::string& testSuiteName, const TestFunc& func)
    {
        const auto testCase = std::make_shared<AssureTestCase>(testCaseName, func, config_);
        const auto it = testSuites_.find(testSuiteName);
        const auto testSuite = (it != testSuites_.end()) ?  it->second : std::make_shared<AssureTestSuite>(testSuiteName, config_);
        testSuite->addTest(testCase);

        if (it == testSuites_.end())
        {
            testSuites_.emplace(testSuiteName, testSuite);
        }
    }

    void AssureSession::addAssertInfo(const AssertInfoPtr& assertInfo)
    {
        assertInfos_.push_back(assertInfo);
    }
}