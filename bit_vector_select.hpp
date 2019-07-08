#include <bit_vector.hpp>

class bit_vector_select {
private:
    const bit_vector* m_bv;

public:
    inline bit_vector_select(const bit_vector& bv) : m_bv(&bv) {
        /* BVCC - Konstruktion */
    }

    inline size_t select1(size_t k) const {
        return 0; /* BVCC - select1(k) */
    }

    inline size_t select0(size_t k) const {
        return 0; /* BVCC - select0(k) */
    }
};
