
#include "doctest.h"
#include "Board.hpp"
#include <string>
using namespace std;
using namespace ariel;

TEST_CASE("Write out of range") {

    //במהלך הכתיבה חורג מחוץ ללוח
    CHECK();
    CHECK();
    CHECK();

    //לגמרי מחוץ ללוח
}

TEST_CASE("Read out of range") {

    //במהלך הקריאה חורגים מחוץ לגודל הלוח
    CHECK_THROWS();                                     
    CHECK_THROWS(); 
    
    //לגמרי מחוץ לגבולות הלוח
}