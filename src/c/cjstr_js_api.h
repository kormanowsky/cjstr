#ifndef CJSTR_JS_API_H
#define CJSTR_JS_API_H

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#define JS_API_FUNCTION EMSCRIPTEN_KEEPALIVE
#else
#define JS_API_FUNCTION
#endif

#endif