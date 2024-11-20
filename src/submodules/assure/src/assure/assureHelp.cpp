#include "assureHelp.h"
#include "assureSession.h"
#include "assureConfig.h"
#include "assertInfo.h"
#include "assureException.h"

namespace assure
{

    void print(const std::string& info)
    {
    }

    int createTestCase(const std::string& caseName, const std::string& suiteName, TestFunction func)
    {
        AssureSession::getInstance().addTest(caseName, suiteName, [caseName, suiteName, func](){ func(caseName, suiteName);});
        return 0;
    }

    void handleAssertInfo(const AssertInfoPtr& info)
    {
         AssureSession::getInstance().config()->logCallback()(info->getExpectedInfo());
         AssureSession::getInstance().config()->logCallback()(info->getActualInfo());
         AssureSession::getInstance().addAssertInfo(info);
         throw AssureTestCaseFailed();
    }

    void handleSuccess()
    {
        AssureSession::getInstance().config()->logCallback()(">>>>>>>>>>>>> Success! <<<<<<<<<<<<<<");
    }
}
