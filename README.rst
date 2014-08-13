============
String-Cpp
============

---------------------------------------------------------------------------------
A C++ string object specifically designed for embedded applications.
---------------------------------------------------------------------------------

.. image:: https://api.travis-ci.org/gbmhunter/String-Cpp.png?branch=master   
	:target: https://travis-ci.org/gbmhunter/String-Cpp

- Author: gbmhunter <gbmhunter@gmail.com> (http://www.cladlab.com)
- First Ever Commit: 2014-08-12
- Last Modified: 2014-08-13
- Version: v1.7.0.0
- Company: CladLabs
- Project: Free Code Libraries
- Language: C++
- Compiler: GCC	
- uC Model: n/a
- Computer Architecture: n/a
- Operating System: n/a
- Documentation Format: Doxygen
- License: GPLv3

Description
===========

String-Cpp is a C++ string object specifically designed for embedded applications.

Features:

- Dynamic allocation and resize capabilities (with data preservation)
- Embedded (microcontroller) support
- Small flash/RAM memory footprint (no depedance on the C++ std::string class)
- Unit tests
- Doxygen-style well-documented API.
- Portability

External Dependencies
=====================

Nothing here yet.

Issues
======

See GitHub Issues.

Limitations
===========

Nothing here yet.

Usage
=====

See the unit tests in the 'test/' directory for basic examples.
	
Changelog
=========

======== ========== ===================================================================================================
Version  Date       Comment
======== ========== ===================================================================================================
v1.7.0.0 2014-08-13 Added equality and inequaltiy operator overloads so that we can compare two string objects with one another and also compare one string object to one C-style string, closes #20. Also added associated unit tests.
v1.6.0.0 2014-08-13 Added 'String::Erase()' method and associated unit tests, closes #15. Changed 'delete' to 'delete[]' in 'String::Append()', closes #16. Add no-parameter constructor which creates a string with just a null char present, closes #17. Added unit tests that make sure String constructors work correctly, closes #18.
v1.5.0.0 2014-08-13 Added 'String::Append()' method. Added overloaded '+' operator so that it concatenates two strings together, closes #11. Added 'String::GetLength()' method, closes #13. Added 'const' qualifier to String variable reference passed into 'String::Find()', closes #12.
v1.4.1.0 2014-08-13 Added startPos variable to 'int32_t Find(char charToFind, uint32_t startPos = 0)', closes #10.
v1.4.0.0 2014-08-13 Added ability to search for a string within string using overloads of the 'Find()' method and associated unit tests, closes #9. Renamed 'test/FindTests.cpp' to 'test/FindCharTests.cpp'. 
v1.3.5.0 2014-08-13 Added copy-assignment unit test in 'test/CopyTests.cpp', closes #5. Replaced memcpy() in String constructor with strncpy(), closes #8. Made sure memory for string is null terminated in constructor, closes #7.
v1.3.4.0 2014-08-12 Fifth attempt at fixing TravisCI issue.
v1.3.3.0 2014-08-12 Fourth attempt at fixing TravisCI issue.
v1.3.2.0 2014-08-12 Third attempt at fixing TravisCI issue.
v1.3.1.0 2014-08-12 Second attempt at fixing TravisCI issue.
v1.3.0.0 2014-08-12 Added assignment operator overload for String class, and added associated unit test, closes #4. Modified .travis.yml file in the hope of compiling with GCC version v4.7 or later to fix TravisCI bug.
v1.2.0.0 2014-08-12 Added copy constructor for String class, and added associated unit test that makes sure the deep copy works correctly, closes #3.
v1.1.0.0 2014-08-12 Added 'String::Find()' method which allows you to search for a particular character in the sting, and added associated unit tests, closes #1. Destructor now deletes memory that was allocated in the constructor, closes #2.
v1.0.0.0 2014-08-12 Initial commit, basic constructor of string object from C-style string has been implemented with one unit test.
======== ========== ===================================================================================================