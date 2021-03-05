//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Implement the class methods
class Rot13 {
    const int rotation{13};
    std::string text;

public:
    Rot13(std::string msg = "");
    bool operator!();
    void operator>>(std::string&);
    friend void operator<<(std::string&, Rot13&);
};


//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "v1" ) {
        Rot13 cipher;
        REQUIRE( !cipher );
    }
    SECTION( "v2" ) {
        Rot13 cipher{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        REQUIRE( !cipher );
    }
    SECTION( "v3" ) {
        Rot13 cipher{"slkgjskjg  akjf Adkfjd fsdfj"};
        REQUIRE( !cipher );
    }
    SECTION( "v4" ) {
        Rot13 cipher{"abcdefghijkl mnopqrst uvwxyz"};
        REQUIRE( !!cipher );
    }
    SECTION( "e1" ) {
        Rot13 cipher{"abcdefghijkl mnopqrst uvwxyz"};
        REQUIRE( !!cipher );
        std::string secret;
        cipher >> secret;
        REQUIRE( secret == "nopqrstuvwxy zabcdefg hijklm" );
    }
    SECTION( "e2" ) {
        Rot13 cipher{"nopqrstuvwxy zabcdefg hijklm"};
        REQUIRE( !!cipher );
        std::string msg;
        msg << cipher;
        REQUIRE( msg == "abcdefghijkl mnopqrst uvwxyz" );
    }
}
//------------------------------
