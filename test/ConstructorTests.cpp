//!
//! @file 			ConstructorTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014-08-13
//! @last-modified 	2014-08-13
//! @brief 			Contains unit tests that make sure the constructor is working correctly.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>

#include "../api/StringApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace StringTestsNs
{
	SUITE(ConstructorTests)
	{

		TEST(NoParamConstructorTest)
		{
			StringNs::String myString;

			// Check constructor worked correctly
			CHECK_EQUAL("", myString.cStringPtr);
		}

		TEST(EmptyStringConstructorTest)
		{
			StringNs::String myString("");

			// Check constructor worked correctly
			CHECK_EQUAL("", myString.cStringPtr);
		}

	} // SUITE(ConstructorTests)
} // namespace StringTestsNs
