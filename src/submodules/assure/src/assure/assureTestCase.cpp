#include "assureTestCase.h"
#include "assureConfig.h"
#include <iostream>

namespace assure
{
    AssureTestCase::AssureTestCase(const std::string& name, const TestFunc& func, const AssureConfigPtr& config)
    : caseName_(name)
    , testFunc_(func)
    , config_(config)
    {}

    void AssureTestCase::excute()
    {
        try {
            log("----------------------start excute test case:[" + caseName_ + "----------------------]");
            testFunc_();
            log("----------------------end excute test case:[" + caseName_ + "----------------------]");
        } catch (...){
        }
    }

    const std::string& AssureTestCase::caseName()
    {
        return caseName_;
    }

    void AssureTestCase::log(const std::string& info)
    {
        if (auto logCallback = config_->logCallback())
        {
            logCallback(info);
        }
        else
        {
            std::cout << info << std::endl;
        }
    }

    AssureTestSuite::AssureTestSuite(const std::string& name, const AssureConfigPtr& config)
    : suiteName_(name)
    , config_(config)
    {
    }

    void AssureTestSuite::excute()
    {
        log("======================start excute test suite:[" + suiteName_ + "======================]");
        for (const auto& p : testCases_)
        {
            if (auto& testCase = p.second)
            {
                testCase->excute();
            }
        }
        log("======================end excute test suite:[" + suiteName_ + "======================]");
    }

    void AssureTestSuite::addTest(const AssureTestCasePtr& testCase)
    {
        testCases_.emplace(testCase->caseName(), testCase);
    }

    void AssureTestSuite::log(const std::string& info)
    {
        if (auto logCallback = config_->logCallback())
        {
            logCallback(info);
        }
        else
        {
            std::cout << info << std::endl;
        }
    }
}
