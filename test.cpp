// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 5/12/2022

#include <iostream>
#include <string>

#include "FibLFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>
using boost::test_tools::output_test_stream;
BOOST_AUTO_TEST_CASE(testStepInstr1) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testStepInstr2) {
  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE_EQUAL(l2.generate(9), 51);
}
BOOST_AUTO_TEST_CASE(testStepInstr3)
{
  FibLFSR test_object("1011011000110110");
  BOOST_REQUIRE_EQUAL(test_object.get_seed(),"1011011000110110");
  //check to see if get_seed function works as intended.
}
BOOST_AUTO_TEST_CASE(testStepInstr4)
{
  
  output_test_stream output;
  FibLFSR test_object("Hello world");
  output<<test_object;
  BOOST_TEST( !output.is_empty( false ) );
  BOOST_TEST( output.check_length(11, false ) );
  BOOST_TEST( output.is_equal("Hello world") );
  
//tests to see if the overloaded ostream operator works as intended.
}