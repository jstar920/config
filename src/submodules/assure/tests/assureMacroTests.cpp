#include "assure.h"

TEST_CASE("test1", "testsuites1")
{
    int a = 3, b = 2;
    ASSURE_EQ(a, b);
}

class Test_Fixture
{
public:
    int initValue {0};
};

TEST_CASE_FIXTURE(Test_Fixture, "test2", "testsuites1")
{
    ASSURE_EQ(initValue, 10);
}

TEST_CASE_FIXTURE(Test_Fixture, "test3", "testsuites1")
{
    ASSURE_NEQ(initValue, 11);
}

TEST_CASE_FIXTURE(Test_Fixture, "test4", "testsuites1")
{
    ASSURE_TRUE(initValue == 10);
}

TEST_CASE_FIXTURE(Test_Fixture, "test5", "testsuites1")
{
    ASSURE_FALSE(initValue == 11);
}