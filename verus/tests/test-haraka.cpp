#include <catch.hpp>

extern "C" {
#include "haraka.h"  // load_constants(), rc, u128
}

TEST_CASE("load_constants() function", "[haraka]") {
  SECTION("loads constants") {
    // act
    load_constants();

    // assert
    size_t len = sizeof(rc) / sizeof(u128);
    for (int i = 0; i < len; ++i) {
      uint32_t *p = (uint32_t *) &rc[i];
      REQUIRE(*p != 0);

      ++p;
      REQUIRE(*p != 0);

      ++p;
      REQUIRE(*p != 0);

      ++p;
      REQUIRE(*p != 0);
    }
  }

  SECTION("sets first element correctly") {
    // act
    load_constants();

    // assert
    uint32_t *p = (uint32_t *) &rc[0];
    REQUIRE(*p == 0x75817b9d);

    ++p;
    REQUIRE(*p == 0xb2c5fef0);

    ++p;
    REQUIRE(*p == 0xe620c00a);

    ++p;
    REQUIRE(*p == 0x0684704c);
  }

  SECTION("sets last element correctly") {
    // act
    load_constants();

    // assert
    size_t len = sizeof(rc) / sizeof(u128);
    uint32_t *p = (uint32_t *) &rc[len - 1];
    REQUIRE(*p == 0xe9c59da1);

    ++p;
    REQUIRE(*p == 0x4ad6bdfd);

    ++p;
    REQUIRE(*p == 0x02288288);

    ++p;
    REQUIRE(*p == 0x756acc03);
  }
}
