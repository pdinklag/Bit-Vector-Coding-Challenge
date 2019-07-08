#include <bit_vector.hpp>

class bit_vector_rank {
private:
    const bit_vector* m_bv;

public:
    inline bit_vector_rank(const bit_vector& bv) : m_bv(&bv) {
        /* BVCC - Konstruktion */
    }

    inline size_t rank1(size_t i) const {
        return 0; /* BVCC - rank1(i) */
    }

    inline size_t rank0(size_t i) const {
        return 0; /* BVCC - rank0(i) */
    }
};
