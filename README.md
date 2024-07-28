# cjstr_client

A fun project to implement ES2023 String in C23.

ES2023 standard: https://tc39.es/ecma262/2023/#sec-text-processing

Build cjstr.js: 

```bash
emcc -o cjstr.js -sMODULARIZE -sEXPORTED_RUNTIME_METHODS=stringToUTF32,POINTER_SIZE,setValue,UTF32ToString -sEXPORTED_FUNCTIONS=_malloc,_free -DUSE_EMSCRIPTEN cjstr.c
```

Run client: 
```bash
node cjstr_client.js
```