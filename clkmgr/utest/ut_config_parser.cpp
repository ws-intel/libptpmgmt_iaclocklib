/* SPDX-License-Identifier: BSD-3-Clause
   SPDX-FileCopyrightText: Copyright © 2025 Intel Corporation. */

/** @file
 * @brief JSON Config Parser class unit tests
 *
 * @author Goh Wei Sheng <wei.sheng.goh@@intel.com>
 * @copyright © 2025 Intel Corporation.
 *
 */

#include "proxy/config_parser.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>

__CLKMGR_NAMESPACE_USE;

// seems like not at pub folder can't access to it definition)
// JsonConfigParser &JsonConfigParser::getInstance()
// {
//     static JsonConfigParser instance;
//     return instance;
// }

// Mock jsonObject class
class MockJsonObject {
   public:
     MOCK_METHOD(bool, getInt, (const std::string &key, uint8_t &res), ());
     MOCK_METHOD(bool, getString, (const std::string &key, std::string &res), ());
};

 // Test fixture for JsonConfigParser
 class JsonConfigParserTest : public ::testing::Test {
  protected:
    void SetUp() override {
         // Create a sample JSON file for testing
         std::ofstream jsonFile("test_config.json");
         jsonFile << R"({
             "timeBaseCfgs": [
                 {
                     "base": {},
                     "udsAddrChrony": "/var/run/chrony.sock",
                     "udsAddrPtp4l": "/var/run/ptp4l.sock"
                 }
             ]
         })";
         jsonFile.close();
     }
 
     void TearDown() override {
         // Clean up the sample JSON file
         std::remove("test_config.json");
     }
 };

 // Test fixture for ClientState
// Study class object public private protected friend
// class JsonConfigParser : public ::testing::Test {
//     protected:
//       JsonConfigParser instance; // Instance of ClientState for testing
//   };

//  // Test singleton instance retrieval
TEST(JsonConfigParserTest, GetInstance) {
    JsonConfigParser &instance1 = JsonConfigParser::getInstance();
    JsonConfigParser &instance2 = JsonConfigParser::getInstance();
    EXPECT_EQ(&instance1, &instance2); // Both instances should be the same
}

// // Test JSON processing
// TEST_F(JsonConfigParserTest, ProcessJson) {
//     JsonConfigParser &parser = JsonConfigParser::getInstance();
//     EXPECT_TRUE(parser.process_json("test_config.json"));
//     EXPECT_EQ(parser.size(), 1); // Ensure one configuration is loaded
// }
