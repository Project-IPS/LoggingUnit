#include<catch2/catch_test_macros.hpp>
#include<cstdio>
//Defining it here overrides all previous settings. It is guarenteed to work
#define LOG_SETTINGS "events"

#include <logger.h>
// #define SET_LOG
TEST_CASE("DEFAULT TEST"){
    SECTION("Let's see how LOGV performs"){
        //Implement the test.
        LOGV("Verbose %d",10);
    }
    
    LOGI("Event %d",10);
    LOGW("Warning %d",10);
    LOGE("Error %d",10);
    REQUIRE(1==1);
}