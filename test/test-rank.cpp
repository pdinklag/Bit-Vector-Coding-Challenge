#include "test.hpp"

#include <bit_vector.hpp>
#include <bit_vector_rank.hpp>

TEST_CASE("rank", "[bv_rank]")
{
    NK_test([](size_t N, size_t K){
        bit_vector bv(N);

        // set every K-th bit
        for(size_t i = 0; i < N; i += K) bv.bitset(i, 1);

        // construct rank data structure
        bit_vector_rank bvr(bv);

        // rank1
        REQUIRE((N/K) == bvr.rank1(N-1));
        for(size_t i = 1; i <= N/K; i++) REQUIRE(i  == bvr.rank1(K*i-1));

        // rank0
        REQUIRE((N-N/K) == bvr.rank0(N-1));
        for(size_t i = 1; i <= N/K; i++) REQUIRE((K-1)*i == bvr.rank0(K*i-1));
    });
}
