#include "test.hpp"

#include <bit_vector.hpp>
#define N 1'000

TEST_CASE("bit_vector: init", "[bv]")
{
    bit_vector bv(N);
    for(size_t i = 0; i < N; i++) {
        REQUIRE(bv.bitread(i) == 0);
    }
}

TEST_CASE("bit_vector: incremental set and reset", "[bv]")
{
    bit_vector bv(N);

    // set
    {
        for(size_t i = 0; i < N; i++) {
            REQUIRE(bv.bitread(i) == 0);
            bv.bitset(i, 1);
            REQUIRE(bv.bitread(i) == 1);
        }
    }

    // reset
    {
        for(size_t i = 0; i < N; i++) {
            REQUIRE(bv.bitread(i) == 1);
            bv.bitset(i, 0);
            REQUIRE(bv.bitread(i) == 0);
        }
    }
}

TEST_CASE("bit_vector: set and test", "[bv]")
{
    bit_vector bv(N);

    for(size_t k = 2; k < 7; k++) {
        // set every k-th bit
        {
            for(size_t i = 0; i < N; i++) {
                bv.bitset(i, i % k == 0);
            }
        }

        // verify
        {
            for(size_t i = 0; i < N; i++) {
                REQUIRE((i%k == 0) == bv.bitread(i));
            }
        }
    }
}

TEST_CASE("bit_vector: decode and encode 64-bit Fibonacci numbers", "[bv]")
{
    for(size_t k = 0; k < FIB_MAX; k++) {
        bit_vector bv(64);

        // encode
        {
            uint64_t v = fib[k];
            for(size_t i = 0; i < 64; i++) {
                bv.bitset(i, v & 1ULL);
                v >>= 1ULL;
            }
        }

        // decode
        {
            uint64_t v = fib[k];
            for(size_t i = 0; i < 64; i++) {
                REQUIRE(bv.bitread(i) == bool(v & 1ULL));
                v >>= 1ULL;
            }
        }
    }
}
