//!
//! @file 			ABitOfEverythingTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-20
//! @last-modified 	2014-08-21
//! @brief 			Includes units tests that test a wide range of String object functionality all at once.
//! @details
//!					See README.rst in root dir for more info.

// System libraries
#include <cstdint>	// uint32_t, e.t.c

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User source
#include "../api/StringApi.hpp"


namespace StringTestsNs
{
	SUITE(ABitOfEverythingTests)
	{

		TEST(ABitOfEverythingTest1)
		{
			//std::cerr << "ABitOfEverythingTest1() called." << std::endl;
			StringNs::String myStr1("Hello, world!");

			// Erase everything after "Hello"
			myStr1.Erase(5);

			CHECK_EQUAL("Hello", myStr1.cStringPtr);

			// Copy to new string
			StringNs::String myStr2 = myStr1;

			CHECK_EQUAL("Hello", myStr2.cStringPtr);
			CHECK_EQUAL(5, myStr2.GetLength());

			// Add some more letters
			myStr2 = myStr2 + ", you!";

			CHECK_EQUAL(11, myStr2.GetLength());
			CHECK_EQUAL("Hello, you!", myStr2.cStringPtr);
		}

		TEST(ABitOfEverythingTest2)
		{
			StringNs::String myStr1("Hello, world!");

			CHECK_EQUAL("Hello, world!", myStr1.cStringPtr);

			// Erase everything after "Hello"
			myStr1.Append(" And hello you!");

			CHECK_EQUAL("Hello, world! And hello you!", myStr1.cStringPtr);

		}

		TEST(ABitOfEverythingTest3)
		{
			StringNs::String myStr1("Hello, world!");

			CHECK_EQUAL("Hello, world!", myStr1.cStringPtr);

			// Erase everything after "Hello"
			myStr1 = myStr1 + " And hello you!";

			CHECK_EQUAL("Hello, world! And hello you!", myStr1.cStringPtr);

			StringNs::String myStr2;

			myStr2 = myStr1 + " And hello me!";

			CHECK_EQUAL("Hello, world! And hello you! And hello me!", myStr2.cStringPtr);

			StringNs::String * myStr3;

			myStr3 = &myStr2;

			CHECK_EQUAL("Hello, world! And hello you! And hello me!", myStr3->cStringPtr);

			myStr3->Erase(2);

			CHECK_EQUAL("He", myStr2.cStringPtr);
			CHECK_EQUAL("He", myStr3->cStringPtr);

			*myStr3 = "";

			CHECK_EQUAL("", myStr2.cStringPtr);
			CHECK_EQUAL("", myStr3->cStringPtr);

			StringNs::String myStr4;

			myStr4 = *myStr3;

			CHECK_EQUAL("", myStr4.cStringPtr);

			myStr4 = StringNs::String("A replacement.");

			CHECK_EQUAL("", myStr3->cStringPtr);
			CHECK_EQUAL("A replacement.", myStr4.cStringPtr);

		}

		TEST(ABitOfEverythingTest4)
		{
			// This performs tests to simulate an AT command decoding scenario

			StringNs::String rxBuffStr = "blahblahATE1\r\nTestPayload\r\nOK\r\nblahblah";

			uint32_t startOfEcho = rxBuffStr.Find("ATE1");

			CHECK_EQUAL(8, startOfEcho);

			uint32_t endOfEcho = rxBuffStr.Find("\n", startOfEcho);

			CHECK_EQUAL(13, endOfEcho);

			uint32_t startOfResponseCode = rxBuffStr.Find("OK", endOfEcho);

			CHECK_EQUAL(27, startOfResponseCode);

			rxBuffStr.Erase(0, endOfEcho + 1);

			CHECK_EQUAL("TestPayload\r\nOK\r\nblahblah", rxBuffStr.cStringPtr);

			//std::cerr << "Erase start pos = '" << startOfResponseCode - endOfEcho - 1 << "'." << std::endl;

			// Erase response code and everything after it
			rxBuffStr.Erase(startOfResponseCode - endOfEcho - 1);

			CHECK_EQUAL("TestPayload\r\n", rxBuffStr.cStringPtr);

		}

	} // SUITE(ABitOfEverythingTests)
} // namespace StringTestsNs
