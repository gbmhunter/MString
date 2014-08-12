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
- Last Modified: 2014-08-12
- Version: v1.1.0.0
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
v1.1.0.0 2014-08-12 Added 'String::Find()' method which allows you to search for a particular character in the sting, and added associated unit tests, closes #1. Destructor now deletes memory that was allocated in the constructor, closes #2.
v1.0.0.0 2014-08-12 Initial commit, basic constructor of string object from C-style string has been implemented with one unit test.
======== ========== ===================================================================================================