#pragma once
#include <sstream>

#include <string>
#include "assertInfo.h"
#include "assureHelp.h"


#define ASSURE_PARAMETER assure::AssureParameter assureParameter(__TEST_CASE_NAME__, __FILE__, __LINE__, __FUNCTION__)
#define ASSERTINFO_TWO_ARGS(arg1, arg2, op) ASSURE_PARAMETER; \
                                            std::stringstream ss; \
                                            ss << "[" << #arg1 << " " << op << " " << #arg2 << "]"; \
                                            const std::string expectedInfo(ss.str()); \
                                            ss.flush(); \
                                            ss << "[" << arg1 << " " << op << " " << arg2 << "]"; \
                                            const std::string actualInfo(ss.str()); \
                                            assure::AssertInfo assertInfo(assureParameter); \
                                            assertInfo.setExpectedInfo(expectedInfo); \
                                            assertInfo.setActualInfo(actualInfo);

#define ASSERTINFO_ONE_ARGS(arg, boolValue) ASSURE_PARAMETER; \
                                            std::stringstream ss; \
                                            ss << "[" << #arg << " == " << boolValue << "]"; \
                                            const std::string expectedInfo(ss.str()); \
                                            ss.flush(); \
                                            ss << "[" << bool2str(arg) << " == " << boolValue << "]"; \
                                            const std::string actualInfo(ss.str()); \
                                            assure::AssertInfo assertInfo(assureParameter); \
                                            assertInfo.setExpectedInfo(expectedInfo); \
                                            assertInfo.setActualInfo(actualInfo);



#define ASSURE_EQ(arg1, arg2) if (arg1 != arg2) \
                              { \
                                  ASSERTINFO_ONE_ARGS(arg1, arg2, "=="); \
                                  assure::handleAssertInfo(assertInfo); \
                              }
#define ASSURE_NEQ(arg1, arg2) if (arg1 == arg2)\
                               { \
                                   ASSERTINFO_ONE_ARGS(arg1, arg2, "=="); \
                                   assure::handleAssertInfo(assertInfo); \
                               }
#define ASSURE_TRUE(arg) if (!arg) \
                         { \
                            ASSERTINFO_ONE_ARGS(arg "true"); \
                            assure::handleAssertInfo(assertInfo); \
                         }
#define ASSURE_FALSE(arg) if (arg) \
                          { \
                              ASSERTINFO_ONE_ARGS(arg "true"); \
                              assure::handleAssertInfo(assertInfo); \
                          }

