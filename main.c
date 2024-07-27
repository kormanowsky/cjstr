#include <stdio.h>
#include <locale.h>

#include "cjstr.h"

int main()
{
    setlocale(LC_ALL, "");

    cjstr_t js_string = cjstr_from_wchar_ptr(L"Мама, привет!");

    printf("%ls\n", cjstr_to_wchar_ptr(js_string));

    cjstr_t digit_js_string = cjstr_from_wchar_ptr(L"123");

    printf("%d\n", cjstr_char_code_at(digit_js_string, 0));
    printf("%d\n", cjstr_char_code_at(digit_js_string, 1));
    printf("%d\n", cjstr_char_code_at(digit_js_string, 2));

    int16_t char_codes[] = {49, 50, 51};

    cjstr_t from_codes_js_string = cjstr_from_char_code(char_codes, sizeof(char_codes));

    printf("%d\n", cjstr_char_code_at(from_codes_js_string, 0));
    printf("%d\n", cjstr_char_code_at(from_codes_js_string, 1));
    printf("%d\n", cjstr_char_code_at(from_codes_js_string, 2));

    cjstr_destroy(js_string);
    cjstr_destroy(digit_js_string);
    cjstr_destroy(from_codes_js_string);

    cjstr_t mom = cjstr_from_wchar_ptr(L"Мама");
    cjstr_t and = cjstr_from_wchar_ptr(L" и ");
    cjstr_t dad = cjstr_from_wchar_ptr(L"Папа");
    cjstr_t strs[] = {and, dad};

    cjstr_t mom_and_dad = cjstr_concat(mom, strs, 2);

    printf("%llu\n", cjstr_length(mom_and_dad));
    printf("%ls\n", cjstr_to_wchar_ptr(mom_and_dad));

    cjstr_destroy(mom);
    cjstr_destroy(and);
    cjstr_destroy(dad);
    cjstr_destroy(mom_and_dad);

    return 0;
}