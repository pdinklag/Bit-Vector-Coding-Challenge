#include "test.hpp"

#include <bit_vector.hpp>
#include <bit_vector_rank.hpp>
#include <bit_vector_select.hpp>

TEST_CASE("rank/select: inversion property", "[bv_rank_select]") {
    NK_test([](size_t N, size_t K){
        //1
        {
            bit_vector bv(N);

            // set every K-th bit
            for(size_t i = 0; i < N; i += K) bv.bitset(i, 1);

            // construct rank and select data structures
            bit_vector_rank   bvr(bv);
            bit_vector_select bvs(bv);

            for(size_t i = 1; i <= N/K; i++) REQUIRE(i == bvr.rank1(bvs.select1(i)));
            for(size_t i = 0; i < N; i++)    REQUIRE(i >= bvs.select1(bvr.rank1(i)));
        }
        //0
        {
            bit_vector bv(N);

            // set all, then unset every K-th bit
            for(size_t i = 0; i < N; i++)    bv.bitset(i, 1);
            for(size_t i = 0; i < N; i += K) bv.bitset(i, 0);

            // construct rank and select data structures
            bit_vector_rank   bvr(bv);
            bit_vector_select bvs(bv);

            for(size_t i = 1; i <= N/K; i++) REQUIRE(i == bvr.rank0(bvs.select0(i)));
            for(size_t i = 0; i < N; i++)    REQUIRE(i >= bvs.select0(bvr.rank0(i)));
        }
    });
}
