#include "test.hpp"

#include <bit_vector.hpp>
#include <bit_vector_select.hpp>

TEST_CASE("select", "[bv_select]")
{
    NK_test([](size_t N, size_t K){
        // select1
        {
            bit_vector bv(N);

            // set every K-th bit
            for(size_t i = 0; i < N; i += K) bv.bitset(i, 1);

            // construct select data structure
            bit_vector_select bvs(bv);

            // test
            REQUIRE(N == bvs.select1(1+N/K));
            for(size_t i = 1; i <= N/K; i++) REQUIRE(K*(i-1) == bvs.select1(i));
        }
        // select0
        {
            bit_vector bv(N);

            // set all, then unset every K-th bit
            for(size_t i = 0; i < N; i++)    bv.bitset(i, 1);
            for(size_t i = 0; i < N; i += K) bv.bitset(i, 0);

            // construct select data structure
            bit_vector_select bvs(bv);

            // test
            REQUIRE(N == bvs.select0(1+N/K));
            for(size_t i = 1; i <= N/K; i++) REQUIRE(K*(i-1) == bvs.select0(i));
        }
    });
}
