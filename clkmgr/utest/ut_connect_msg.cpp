/* SPDX-License-Identifier: BSD-3-Clause
   SPDX-FileCopyrightText: Copyright © 2025 Intel Corporation. */

/** @file
 * @brief ClientState class unit tests
 *
 * @author Goh Wei Sheng <wei.sheng.goh@@intel.com>
 * @copyright © 2025 Intel Corporation.
 *
 */

#include "client/client_state.hpp"
#include <gtest/gtest.h>

//__CLKMGR_NAMESPACE_USE;

#include "client/connect_msg.hpp"

// Mock dependencies
// class MockClientState : public ClientState {
// 	// Add mock methods if needed
// };
//clkmgr/utest/ut_connect_msg.cpp:20:44: error: expected class-name before ‘{’ token
// 20 | class MockClientState : public ClientState {

// class MockCommonConnectMessage : public CommonConnectMessage {
// 	// Add mock methods if needed
// };

// class MockClientMessage : public ClientMessage {
// 	// Add mock methods if needed
// };

// // Test fixture for ClientConnectMessage
// class ClientConnectMessageTest : public ::testing::Test {
// protected:
// 	ClientConnectMessage clientConnectMessage;
// 	MockClientState mockClientState;

// 	void SetUp() override {
// 		// Setup code if needed
// 	}

// 	void TearDown() override {
// 		// Cleanup code if needed
// 	}
// };

// // Test setClientState
// TEST_F(ClientConnectMessageTest, SetClientState) {
// 	clientConnectMessage.setClientState(mockClientState);
// 	// Verify that the currentClientState is updated
// 	ASSERT_EQ(ClientConnectMessage::currentClientState, &mockClientState);
// }

// // Test initMessage
// TEST_F(ClientConnectMessageTest, InitMessage) {
// 	bool result = ClientConnectMessage::initMessage();
// 	// Verify that initMessage returns true
// 	ASSERT_TRUE(result);
// }

// // Test buildMessage
// TEST_F(ClientConnectMessageTest, BuildMessage) {
// 	CommonConnectMessage::Message msg;
// 	bool result = ClientConnectMessage::buildMessage(msg, nullptr);
// 	// Verify that buildMessage returns true
// 	ASSERT_TRUE(result);
// 	// Add additional checks for the msg object if needed
// }

// // Main function for running tests
// int main(int argc, char **argv) {
// 	::testing::InitGoogleTest(&argc, argv);
// 	return RUN_ALL_TESTS();
// }
