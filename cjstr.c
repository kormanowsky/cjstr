#include "cjstr.h"

cjstr_t cjstr_create(wchar_t *initializer, uint64_t length)
{
    if (initializer == NULL)
    {
        return NULL;
    }

    cjstr_t str = malloc((length + 1) * sizeof(cjstr_t));

    if (str == NULL)
    {
        return NULL;
    }

    wmemcpy(str, initializer, length);

    return str;
}

void cjstr_destroy(cjstr_t str)
{
    free(str);
}

cjstr_t cjstr_from_char_code(int16_t *code_units, uint64_t length)
{
    // TODO
    return NULL;
}