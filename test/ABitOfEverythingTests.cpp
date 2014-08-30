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
#include "../api/MStringApi.hpp"


namespace StringTestsNs
{
	SUITE(ABitOfEverythingTests)
	{

		TEST(ABitOfEverythingTest1)
		{
			//std::cerr << "ABitOfEverythingTest1() called." << std::endl;
			MbeddedNinja::MString myStr1("Hello, world!");

			// Erase everything after "Hello"
			myStr1.Erase(5);

			CHECK_EQUAL("Hello", myStr1.cStr);

			// Copy to new string
			MbeddedNinja::MString myStr2 = myStr1;

			CHECK_EQUAL("Hello", myStr2.cStr);
			CHECK_EQUAL(5, myStr2.GetLength());

			// Add some more letters
			myStr2 = myStr2 + ", you!";

			CHECK_EQUAL(11, myStr2.GetLength());
			CHECK_EQUAL("Hello, you!", myStr2.cStr);
		}

		TEST(ABitOfEverythingTest2)
		{
			MbeddedNinja::MString myStr1("Hello, world!");

			CHECK_EQUAL("Hello, world!", myStr1.cStr);

			// Erase everything after "Hello"
			myStr1.Append(" And hello you!");

			CHECK_EQUAL("Hello, world! And hello you!", myStr1.cStr);

		}

		TEST(ABitOfEverythingTest3)
		{
			MbeddedNinja::MString myStr1("Hello, world!");

			CHECK_EQUAL("Hello, world!", myStr1.cStr);

			// Erase everything after "Hello"
			myStr1 = myStr1 + " And hello you!";

			CHECK_EQUAL("Hello, world! And hello you!", myStr1.cStr);

			MbeddedNinja::MString myStr2;

			myStr2 = myStr1 + " And hello me!";

			CHECK_EQUAL("Hello, world! And hello you! And hello me!", myStr2.cStr);

			MbeddedNinja::MString * myStr3;

			myStr3 = &myStr2;

			CHECK_EQUAL("Hello, world! And hello you! And hello me!", myStr3->cStr);

			myStr3->Erase(2);

			CHECK_EQUAL("He", myStr2.cStr);
			CHECK_EQUAL("He", myStr3->cStr);

			*myStr3 = "";

			CHECK_EQUAL("", myStr2.cStr);
			CHECK_EQUAL("", myStr3->cStr);

			MbeddedNinja::MString myStr4;

			myStr4 = *myStr3;

			CHECK_EQUAL("", myStr4.cStr);

			myStr4 = MbeddedNinja::MString("A replacement.");

			CHECK_EQUAL("", myStr3->cStr);
			CHECK_EQUAL("A replacement.", myStr4.cStr);

		}

		TEST(ABitOfEverythingTest4)
		{
			// This performs tests to simulate an AT command decoding scenario

			MbeddedNinja::MString rxBuffStr = "blahblahATE1\r\nTestPayload\r\nOK\r\nblahblah";

			uint32_t startOfEcho = rxBuffStr.Find("ATE1");

			CHECK_EQUAL(8, startOfEcho);

			uint32_t endOfEcho = rxBuffStr.Find("\n", startOfEcho);

			CHECK_EQUAL(13, endOfEcho);

			uint32_t startOfResponseCode = rxBuffStr.Find("OK", endOfEcho);

			CHECK_EQUAL(27, startOfResponseCode);

			rxBuffStr.Erase(0, endOfEcho + 1);

			CHECK_EQUAL("TestPayload\r\nOK\r\nblahblah", rxBuffStr.cStr);

			//std::cerr << "Erase start pos = '" << startOfResponseCode - endOfEcho - 1 << "'." << std::endl;

			// Erase response code and everything after it
			rxBuffStr.Erase(startOfResponseCode - endOfEcho - 1);

			CHECK_EQUAL("TestPayload\r\n", rxBuffStr.cStr);

		}

		TEST(ABitOfEverythingTest5)
		{
			MbeddedNinja::MString myStr1;

			myStr1 += "a";

			CHECK_EQUAL("a", myStr1.cStr);

			myStr1 << 1 << "b" << 2;

			CHECK_EQUAL("a1b2", myStr1.cStr);

			myStr1 = "c";

			CHECK_EQUAL("c", myStr1.cStr);

			myStr1 << "=" << 2.314;

			CHECK_EQUAL("c=2.314", myStr1.cStr);
		}

	} // SUITE(ABitOfEverythingTests)
} // namespace StringTestsNs
