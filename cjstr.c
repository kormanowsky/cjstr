#include "cjstr.h"

cjstr_t cjstr_create(wchar_t *initializer, uint64_t length)
{
    cjstr_t str = malloc((length + 1) * sizeof(cjstr_t));

    if (str == NULL)
    {
        return NULL;
    }

    if (initializer == NULL)
    {
        wmemset(str, 0, length);
    }
    else
    {
        wmemcpy(str, initializer, length);
    }

    return str;
}

void cjstr_destroy(cjstr_t str)
{
    free(str);
}

uint16_t cjstr_char_code_at(cjstr_t str, uint64_t pos)
{
    return (uint16_t) *(str + pos);
}

cjstr_t cjstr_from_char_code(int16_t *code_units, uint64_t length)
{
    cjstr_t
        str = cjstr_create(NULL, length),
        str_cur = str;

    if (str_cur == NULL)
    {
        return NULL;
    }

    while (--length > 0)
    {
        *str_cur = *code_units;
        ++str_cur;
        ++code_units;
    }

    return str;
}
