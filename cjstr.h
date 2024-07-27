#ifndef CJSTR_LIBRARY_H
#define CJSTR_LIBRARY_H

#include <stdlib.h>
#include <stdint.h>
#include <wchar.h>

typedef wchar_t cjstr_char_t;

typedef struct cjstr_struct
{
    uint64_t length;
    cjstr_char_t data[];
} cjstr_struct_t;

typedef cjstr_struct_t *cjstr_t;

// "Constructor" / "destructor"

cjstr_t cjstr_create(uint64_t length);

void cjstr_destroy(cjstr_t this);

// "Instance methods"
wchar_t *cjstr_to_wchar_ptr(cjstr_t this);

uint16_t cjstr_char_code_at(cjstr_t this, uint64_t pos);

uint64_t cjstr_length(cjstr_t this);

cjstr_t cjstr_at(cjstr_t this, int64_t pos);

cjstr_t cjstr_concat(cjstr_t this, cjstr_t *strs, uint64_t length);

// "Static methods"

cjstr_t cjstr_from_wchar_ptr(wchar_t *ptr);

cjstr_t cjstr_from_char_code(int16_t *code_units, uint64_t length);

#endif //CJSTR_LIBRARY_H
