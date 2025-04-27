#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "romanos.hpp"


TEST_CASE( "Números romanos - algarismos únicos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("I") == 1 );
    REQUIRE( romanos_para_decimal("V") == 5 );
    REQUIRE( romanos_para_decimal("X") == 10 );
    REQUIRE( romanos_para_decimal("L") == 50 );
    REQUIRE( romanos_para_decimal("C") == 100 );
    REQUIRE( romanos_para_decimal("D") == 500 );
    REQUIRE( romanos_para_decimal("M") == 1000 );   
}
TEST_CASE( "Numeros romanos - algarismos inválidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("G") == -1 );
    REQUIRE( romanos_para_decimal("i") == -1 );
    REQUIRE( romanos_para_decimal("1") == -1 );
    REQUIRE( romanos_para_decimal("{") == -1 );
}
TEST_CASE("Número romanos - número com mais de um digito", "[romanos]"){
    REQUIRE (romanos_para_decimal("XV") == 15);
    REQUIRE (romanos_para_decimal("XVI") == 16);
    REQUIRE (romanos_para_decimal("XIII") == 13);
    REQUIRE (romanos_para_decimal("VII") == 7);
    REQUIRE (romanos_para_decimal("III") == 3);
    REQUIRE (romanos_para_decimal("MMDCL") == 2650);
}
TEST_CASE("Número romanos - número com mais de um dígito, no qual um dos números que o compõem é menor que seu sucessor", "[romanos]"){
    REQUIRE (romanos_para_decimal("IX") == 9);
    REQUIRE (romanos_para_decimal("XIV") == 14);
    REQUIRE(romanos_para_decimal("CMXCIX") == 999);
    REQUIRE(romanos_para_decimal("CDXLIV") == 444);
    REQUIRE(romanos_para_decimal("XLIV") == 44);
}
