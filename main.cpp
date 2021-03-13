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
  Rot13(std::string msg = ""){
    unsigned int idx{0};
    for (idx = 0; idx < msg.length(); idx++){
      if ((((static_cast<int>(msg[idx]) <= 122) && (static_cast<int>(msg[idx]) >= 97)) || (static_cast<int>(msg[idx]) == 32)) )
        text += msg[idx];
      else{
        text.erase(0,idx);
        break;
      }
    }
  }

  bool operator!(){
    return text.length() == 0;
  }

  void operator>>(std::string& out){
    int code;
    for (unsigned int j = 0; j < text.length(); j++){
      code = static_cast<int>(text[j]);
      if (code == 32){
        out += static_cast<char>(code);
        continue;
      }
      code += rotation;
      if (code > 122){
        code -= 122;
        code += 96;
      }
      out += static_cast<char>(code);
    }
  }
  
  friend void operator<<(std::string&, Rot13&);
};

void operator<<(std::string& abc, Rot13& d){
  int back;
  for (unsigned int k = 0; k < d.text.length(); k++){
    back = static_cast<int>(d.text[k]);
    if (back == 32){
      abc += static_cast<char>(back);
      continue;
    }
    back = back - d.rotation;
    if (back < 97){
      back = 97 - back;
      back = 123 - back;
    }
    abc += static_cast<char>(back);
  }
}


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
