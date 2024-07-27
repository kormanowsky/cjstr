#include "cjstr.h"

cjstr_t cjstr_create(wchar_t *initializer, uint64_t length)
{
    cjstr_t str = malloc(
        sizeof(cjstr_struct_t) + length * sizeof(cjstr_char_t)
    );

    if (str == NULL)
    {
        return NULL;
    }

    str->length = length;

    if (initializer == NULL)
    {
        wmemset(str->data, 0, length);
    }
    else
    {
        wmemcpy(str->data, initializer, length);
    }

    wmemset(str->data + str->length, L'\0', 1);

    return str;
}

void cjstr_destroy(cjstr_t str)
{
    free(str);
}

uint16_t cjstr_char_code_at(cjstr_t str, uint64_t pos)
{
    return (uint16_t) *(str->data + pos);
}

cjstr_t cjstr_from_char_code(int16_t *code_units, uint64_t length)
{
    cjstr_t str = cjstr_create(NULL, length);
    cjstr_char_t *str_cur = str->data;

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

uint64_t cjstr_length(cjstr_t str)
{
    return str->length;
}

cjstr_t cjstr_at(cjstr_t str, int64_t pos)
{
    if (pos < -str->length || pos >= str->length)
    {
        return NULL;
    }

    uint64_t rel_pos = pos < 0 ? str->length - pos : pos;

    return cjstr_create(str->data + rel_pos, 1);
}

cjstr_t cjstr_concat(cjstr_t str, cjstr_t *strs, uint64_t length)
{
    uint64_t
        out_length = str->length,
        i = 0;

    cjstr_t *strs_cur = strs;

    while (i < length)
    {
        out_length += (*strs_cur)->length;
        strs_cur++;
        i++;
    }

    cjstr_t out_str = cjstr_create(NULL, out_length);

    if (out_str == NULL)
    {
        return NULL;
    }

    wmemmove(out_str->data, str->data, str->length);

    cjstr_char_t *out_ptr = out_str->data + str->length;

    i = 0;
    strs_cur = strs;

    while (i < length)
    {
        cjstr_t strs_cur_str = *strs_cur;

        wmemmove(out_ptr, strs_cur_str->data, strs_cur_str->length);

        out_ptr += strs_cur_str->length;
        strs_cur++;
        i++;
    }

    wmemset(out_ptr, L'\0', 1);

    return out_str;
}
