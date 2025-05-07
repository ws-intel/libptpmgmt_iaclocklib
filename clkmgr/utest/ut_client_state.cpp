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

__CLKMGR_NAMESPACE_USE;

// Q1: Do we need to test the copy constructor?

// Test fixture for ClientState
// Study class object public private protected friend
class ClientStateTest : public ::testing::Test {
  protected:
    ClientState clientState; // Instance of ClientState for testing
};

// Test default constructor
TEST_F(ClientStateTest, DefaultConstructor) {
    EXPECT_FALSE(clientState.get_connected());
    EXPECT_EQ(clientState.get_sessionId(), InvalidSessionId);
    EXPECT_EQ(clientState.get_clientID(), TransportClientId{});
}

// Test set and get connection status
TEST_F(ClientStateTest, SetAndGetConnected) {
   clientState.set_connected(true);
   EXPECT_TRUE(clientState.get_connected());

   clientState.set_connected(false);
   EXPECT_FALSE(clientState.get_connected());
}

// Test set and get session ID
TEST_F(ClientStateTest, SetAndGetSessionId) {
   // Test with a valid session ID
   sessionId_t testSessionId = 12345;
   clientState.set_sessionId(testSessionId);
   EXPECT_EQ(clientState.get_sessionId(), testSessionId);

   // Test the min boundary
   sessionId_t minSessionId = std::numeric_limits<sessionId_t>::min();
   clientState.set_sessionId(minSessionId);
   EXPECT_EQ(clientState.get_sessionId(), minSessionId);

   // Test the max boundary
   sessionId_t maxSessionId = std::numeric_limits<sessionId_t>::max();
   clientState.set_sessionId(maxSessionId);
   EXPECT_EQ(clientState.get_sessionId(), maxSessionId);

   // Not able to test out of boundary values
   // clkmgr/utest/ut_client_state.cpp:60: Failure
   // Expected: (clientState.get_sessionId()) != (maxSessionId), actual: 65535 vs 65535

}

// Test set and get client ID
TEST_F(ClientStateTest, SetAndGetClientID) {
   TransportClientId testClientId = {1, 2, 3, 4};
   clientState.set_clientID(testClientId);
   EXPECT_EQ(clientState.get_clientID(), testClientId);
}

// Test set client state
TEST_F(ClientStateTest, SetClientState) {
   ClientState newState;
   newState.set_connected(true);
   newState.set_sessionId(54321);
   TransportClientId newClientId = {5, 6, 7, 8};
   newState.set_clientID(newClientId);

   clientState.set_clientState(newState);

   EXPECT_TRUE(clientState.get_connected());
   EXPECT_EQ(clientState.get_sessionId(), 54321);
   EXPECT_EQ(clientState.get_clientID(), newClientId);
}
