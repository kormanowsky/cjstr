#include "cjstr.h"

cjstr_t cjstr_create(uint64_t length)
{
    cjstr_t str = malloc(
        sizeof(cjstr_struct_t) + length * sizeof(cjstr_char_t)
    );

    if (str == NULL)
    {
        return NULL;
    }

    str->length = length;

    wmemset(str->data, L'\0', str->length + 1);

    return str;
}

void cjstr_destroy(cjstr_t this)
{
    free(this);
}

uint64_t cjstr_length(cjstr_t this)
{
    return this->length;
}

cjstr_t cjstr_at(cjstr_t this, int64_t pos)
{
    if (pos < -this->length || pos >= this->length)
    {
        return NULL;
    }

    uint64_t rel_pos = pos < 0 ? this->length - pos : pos;

    cjstr_t out_str = cjstr_create(1);

    wmemmove(out_str->data, this->data + rel_pos, 1);

    return out_str;
}

cjstr_t cjstr_concat(cjstr_t this, cjstr_t *strs, uint64_t length)
{
    uint64_t
        out_length = this->length,
        i = 0;

    cjstr_t *strs_cur = strs;

    while (i < length)
    {
        out_length += (*strs_cur)->length;
        strs_cur++;
        i++;
    }

    cjstr_t out_str = cjstr_create(out_length);

    if (out_str == NULL)
    {
        return NULL;
    }

    wmemmove(out_str->data, this->data, this->length);

    cjstr_char_t *out_ptr = out_str->data + this->length;

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

    return out_str;
}

wchar_t *cjstr_to_wchar_ptr(cjstr_t this)
{
    return this->data;
}

uint16_t cjstr_char_code_at(cjstr_t this, uint64_t pos)
{
    return (uint16_t) *(this->data + pos);
}

cjstr_t cjstr_from_wchar_ptr(wchar_t *ptr)
{
    if (ptr == NULL)
    {
        return NULL;
    }

    uint64_t length = 0;
    wchar_t *ptr_cur = ptr;

    while (*ptr_cur != L'\0')
    {
        ++length;
        ++ptr_cur;
    }

    cjstr_t str = cjstr_create(length);

    if (str == NULL)
    {
        return NULL;
    }

    str->length = length;

    wmemmove(str->data, ptr, str->length);

    return str;
}

cjstr_t cjstr_from_char_code(int16_t *code_units, uint64_t length)
{
    cjstr_t str = cjstr_create(length);

    if (str == NULL)
    {
        return NULL;
    }

    cjstr_char_t *str_cur = str->data;

    while (--length > 0)
    {
        *str_cur = *code_units;
        ++str_cur;
        ++code_units;
    }

    return str;
}
