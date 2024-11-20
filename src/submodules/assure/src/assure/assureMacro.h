#pragma once
#include "assureHelp.h"
#include <sstream>
#include <string>

#define ASSURE_PARAMETER assure::AssureParameter assureParameter{__TEST_CASE_NAME__, __TEST_SUITE_NAME__, __FILE__, __LINE__, __FUNCTION__}
#define ASSERTINFO_TWO_ARGS(arg1, arg2, op) ASSURE_PARAMETER; \
                                            std::stringstream ssExpect; \
                                            ssExpect << "[(" << #arg1 << ") " << op << " (" << #arg2 << ")]"; \
                                            const std::string expectedInfo(ssExpect.str()); \
                                            std::stringstream ssActual; \
                                            ssActual << "[" << (arg1) << " " << op << " " << (arg2) << "]"; \
                                            const std::string actualInfo(ssActual.str()); \
                                            const auto assertInfo = std::make_shared<assure::AssertInfo>(assureParameter); \
                                            assertInfo->setExpectedInfo(expectedInfo); \
                                            assertInfo->setActualInfo(actualInfo);

#define ASSERTINFO_ONE_ARGS(arg, boolValue) ASSURE_PARAMETER; \
                                            std::stringstream ssExpect; \
                                            ssExpect << "[(" << #arg << ") is " << boolValue << "]"; \
                                            const std::string expectedInfo(ssExpect.str()); \
                                            std::stringstream ssActual; \
                                            ssActual << "[" << assure::bool2str(arg) << " == " << boolValue << "]"; \
                                            const std::string actualInfo(ssActual.str()); \
                                            const auto assertInfo = std::make_shared<assure::AssertInfo>(assureParameter); \
                                            assertInfo->setExpectedInfo(expectedInfo); \
                                            assertInfo->setActualInfo(actualInfo);



#define ASSURE_EQ(arg1, arg2) if ((arg1) != (arg2)) \
                              { \
                                  ASSERTINFO_TWO_ARGS(arg1, arg2, "=="); \
                                  assure::handleAssertInfo(assertInfo); \
                              }
#define ASSURE_NEQ(arg1, arg2) if ((arg1) == (arg2))\
                               { \
                                   ASSERTINFO_TWO_ARGS(arg1, arg2, "=="); \
                                   assure::handleAssertInfo(assertInfo); \
                               }
#define ASSURE_TRUE(arg) if (!(arg)) \
                         { \
                            ASSERTINFO_ONE_ARGS(arg, "true"); \
                            assure::handleAssertInfo(assertInfo); \
                         }
#define ASSURE_FALSE(arg) if ((arg)) \
                          { \
                              ASSERTINFO_ONE_ARGS(arg, "true"); \
                              assure::handleAssertInfo(assertInfo); \
                          }
#define TEST_CASE_FUNCTION_NAME_TAG2(name, tag) name##tag
#define TEST_CASE_FUNCTION_NAME_TAG(name, tag) TEST_CASE_FUNCTION_NAME_TAG2(name, tag)

#ifdef __COUNTER__
#define TEST_CASE_FUNCTION_NAME(name) TEST_CASE_FUNCTION_NAME_TAG(name, __COUNTER__)
#else
#define TEST_CASE_FUNCTION_NAME(name) TEST_CASE_FUNCTION_NAME_TAG(name, __LINE__)
#endif

#define TEST_CASE_UNUSED_VARIABLE_TAG2(name, tag) name##tag
#define TEST_CASE_UNUSED_VARIABLE_TAG(name, tag) TEST_CASE_UNUSED_VARIABLE_TAG2(name, tag)
#ifdef __COUNTER__
#define TEST_CASE_UNUSED_VARIABLE(name) TEST_CASE_UNUSED_VARIABLE_TAG(name, __COUNTER__)
#else
#define TEST_CASE_UNUSED_VARIABLE(name) TEST_CASE_UNUSED_VARIABLE_TAG(name, __LINE__)
#endif

#define ASSURE_REGESTER_TEST(testFuncionName, unusedVariable, testName, testSuiteName) \
        static void testFuncionName(const std::string& __TEST_CASE_NAME__, const std::string& __TEST_SUITE_NAME__); \
        int unusedVariable = assure::createTestCase(testName, testSuiteName, testFuncionName); \
        static void testFuncionName(const std::string& __TEST_CASE_NAME__, const std::string& __TEST_SUITE_NAME__)

#define TEST_CASE(testName, testSuiteName) ASSURE_REGESTER_TEST(TEST_CASE_FUNCTION_NAME( ASSURE_TEST_CASE_ ), TEST_CASE_UNUSED_VARIABLE(unused_), testName, testSuiteName)                                      


#define FIXTURE_CLASS_NAME_TAG2(name, tag) name##tag
#define FIXTURE_CLASS_NAME_TAG(name, tag) FIXTURE_CLASS_NAME_TAG2(name, tag)
#ifdef __COUNTER__
#define FIXTURE_CLASS_NAME(name) FIXTURE_CLASS_NAME_TAG(name, __COUNTER__)
#else
#define FIXTURE_CLASS_NAME(name) FIXTURE_CLASS_NAME_TAG(name, __LINE__)
#endif

#define ASSURE_REGESTER_TEST_FIXTURE(parentClassName, className, functionName, unusedVariable, testName, testSuiteName) \
        struct className: public parentClassName \
        { \
             void functionName(const std::string& __TEST_CASE_NAME__, const std::string& __TEST_SUITE_NAME__); \
        }; \
        int unusedVariable = assure::createTestCase(testName, testSuiteName, [sharedThis = std::make_shared<className>()](const std::string& caseName, const std::string& suiteName){ \
            sharedThis->functionName(caseName, suiteName); \
        }); \
        void className::functionName(const std::string& __TEST_CASE_NAME__, const std::string& __TEST_SUITE_NAME__)

#define TEST_CASE_FIXTURE(className, testName, testSuiteName) \
       ASSURE_REGESTER_TEST_FIXTURE(className, FIXTURE_CLASS_NAME(FIXTURE_CLASS_), TEST_CASE_FUNCTION_NAME( ASSURE_TEST_CASE_ ), TEST_CASE_UNUSED_VARIABLE(unused_), testName, testSuiteName)
