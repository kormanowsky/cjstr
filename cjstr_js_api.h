#ifndef CJSTR_JS_API_H
#define CJSTR_JS_API_H

#ifdef USE_EMSCRIPTEN
#include <emscripten/emscripten.h>
#define JS_API_FUNCTION EMSCRIPTEN_KEEPALIVE
#else
#define JS_API_FUNCTION
#endif

#endif