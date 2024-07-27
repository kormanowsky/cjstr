#ifndef CJSTR_LIBRARY_H
#define CJSTR_LIBRARY_H

#include <stdlib.h>
#include <stdint.h>
#include <wchar.h>

typedef wchar_t cjstr_char_t;
typedef cjstr_char_t *cjstr_t;

cjstr_t cjstr_create(wchar_t *initializer, uint64_t length);

void cjstr_destroy(cjstr_t str);

cjstr_t cjstr_from_char_code(int16_t *code_units, uint64_t length);

#endif //CJSTR_LIBRARY_H
