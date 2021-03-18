
#include "doctest.h"
#include "Board.hpp"
#include <string>
using namespace std;
using namespace ariel;

TEST_CASE("Reading from empty board"){
    Board b;

    //--------Horizontal----------//

    CHECK(b.read(0,0,Direction::Horizontal, 2) == "__");
    CHECK(b.read(10,20,Direction::Horizontal, 10) == "__________");
    CHECK(b.read(100,200,Direction::Horizontal, 5) == "_____");

    //--------Vertical----------//
    CHECK(b.read(0,0,Direction::Vertical, 2) == "__");
    CHECK(b.read(10,20,Direction::Vertical, 10) == "__________");
    CHECK(b.read(100,200,Direction::Vertical, 5) == "_____");
}

TEST_CASE("Adding msg to empty board horizontal"){
    Board b;

    string s="test msg";
    b.post(0,0,Direction::Horizontal, s );
    CHECK(b.read(0,0, Direction::Horizontal, 8)==s);

}

TEST_CASE("Adding msg to empty board vertical"){
    Board b;

    string s="test msg";
    b.post(0,0,Direction::Vertical, s );
    CHECK(b.read(0,0, Direction::Vertical, 8)==s);

}

TEST_CASE("Post out of range") {

    Board b;
    
    /*
      Check that does not throw 
      an error out of range
    */

    //--------Horizontal----------//

    //board size is: 5 X 5
    CHECK_NOTHROW(b.post(0,10,Direction::Horizontal, "  "));

    //board size is: 5 X 10
    CHECK_NOTHROW(b.post(0,100,Direction::Horizontal, "  "));
   
   //board size is: 5 X 100
    CHECK_NOTHROW(b.post(0,1000,Direction::Horizontal, "  "));
   
   //board size is: 5 X 1000
    CHECK_NOTHROW(b.post(0,10000,Direction::Horizontal, "  "));


    //--------Vertical----------//

    //board size is: 5 X 10000
    CHECK_NOTHROW(b.post(10,10000,Direction::Horizontal, "  "));

    //board size is: 10 X 10000
    CHECK_NOTHROW(b.post(100,10000,Direction::Horizontal, "  "));

    //board size is: 100 X 10000
    CHECK_NOTHROW(b.post(1000,10000,Direction::Horizontal, "  "));

    //board size is: 1000 X 10000
    CHECK_NOTHROW(b.post(10000,10000,Direction::Horizontal, "  "));

    /*
     Finally the size of the board is 10000 X 10000,
     we can see that no errors were thrown.
    */
    
}

TEST_CASE("Read out of range") {

    Board b;

    /*
      Reading characters outside the board size.
      Check that does not throw 
      an error out of range
    */

    //--------Horizontal----------//

    CHECK_NOTHROW(b.read(0,10,Direction::Horizontal, 3));
    CHECK_NOTHROW(b.read(0,100,Direction::Horizontal, 3));
    CHECK_NOTHROW(b.read(0,1000,Direction::Horizontal, 3));
    CHECK_NOTHROW(b.read(0,10000,Direction::Horizontal, 3));


    //--------Vertical----------//
    CHECK_NOTHROW(b.read(10, 0,Direction::Horizontal, 3));
    CHECK_NOTHROW(b.read(100,0,Direction::Horizontal, 3));
    CHECK_NOTHROW(b.read(1000,0,Direction::Horizontal, 3));
    CHECK_NOTHROW(b.read(10000,0,Direction::Horizontal, 3));

    /*
     Add words and then read out of range
    */

    //--------Horizontal----------//
    b.post(0,0,Direction::Horizontal, "abcd");
    b.post(2,8,Direction::Horizontal, "hi");
    b.post(12,33,Direction::Horizontal, "out");

    CHECK(b.read(0,0,Direction::Horizontal, 7)=="abcd___");
    CHECK(b.read(2,6,Direction::Horizontal,4)=="__hi");
    CHECK(b.read(12,31,Direction::Horizontal,8)=="__out___");

    //--------Vertical----------//
    b.post(9,0,Direction::Vertical, "hello");
    b.post(4,6,Direction::Vertical, "bye");
    b.post(53,8,Direction::Vertical, "see you");

    CHECK(b.read(9,0,Direction::Vertical, 7)=="hello__");
    CHECK(b.read(1,6,Direction::Vertical,6)=="___bye");
    CHECK(b.read(50,8,Direction::Vertical,14)=="___see you____");

}

TEST_CASE("Read a word of length zero") {

    Board b;

    CHECK(b.read(0,0,Direction::Horizontal, 0)=="");
    CHECK(b.read(0,0,Direction::Vertical, 0)==""); 

    //There is no string in these numbers
    CHECK(b.read(20,30,Direction::Horizontal, 0)=="");
    CHECK(b.read(20,30,Direction::Vertical, 0)==""); 

    //Adding a string to check that it is still in size 0 we get ""
    b.post(20,30,Direction::Horizontal, "test");
    b.post(20,30,Direction::Vertical, "test");

    CHECK(b.read(20,30,Direction::Horizontal, 0)=="");
    CHECK(b.read(20,30,Direction::Vertical, 0)==""); 

}

TEST_CASE("Overriding existing strings"){
    Board b;

    b.post(0,0,Direction::Horizontal, "test");
    b.post(0,0,Direction:: Vertical, "banana");

    CHECK(b.read(0,0,Direction::Horizontal,4 )== "best");
    CHECK(b.read(0,0,Direction::Vertical,6 )== "banana");

    b.post(3,0, Direction::Vertical, "gkok");
    CHECK(b.read(0,0,Direction::Vertical, 7)=="bangkok");   

    b.post(8,0,Direction::Horizontal, "I love my mom");
    CHECK(b.read(8,0,Direction::Horizontal,13)=="I love my mom");

    b.post(8,10,Direction::Horizontal, "sister");
    CHECK(b.read(8,0,Direction::Horizontal,16)=="I love my sister");

    b.post(8,10, Direction::Vertical, "by");
    CHECK(b.read(8,10,Direction::Horizontal,6)=="bister");
}
