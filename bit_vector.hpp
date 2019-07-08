#include <cstddef>

class bit_vector {
private:
    size_t m_size;

public:
    inline bit_vector(size_t size) : m_size(size) {
        /* BVCC - Allokation */
    }

    inline void bitset(size_t i, bool b) {
        /* BVCC - Bit an Position i auf b setzen */
    }

    inline bool bitread(size_t i) const {
        return false; /* BVCC - Bit aus Position i lesen */
    }

    inline size_t size() const {
        return m_size;
    }
};
