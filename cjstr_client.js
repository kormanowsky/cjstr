const fs = require('node:fs');
const cjstrFactory = require('./cjstr.js');

async function main(cjstr) {
    class CJSStr {
        constructor(ptr) {
            this.ptr = ptr;
        }

        get length() {
            return cjstr._cjstr_length(this.ptr);
        }

        concat(...strs) {
            const ptr = cjstr._malloc(strs.length);
            let ptrCpy = ptr;

            for (let i = 0; i < strs.length; ++i) {
                cjstr.setValue(ptrCpy, strs[i].getPtr(), '*');

                ptrCpy += cjstr.POINTER_SIZE;
            }

            const out = new CJSStr(cjstr._cjstr_concat(this.ptr, ptr, strs.length));

            cjstr._free(ptr);

            return out;
        }

        getPtr() {
            return this.ptr;
        }

        toString() {
            return cjstr.UTF32ToString(cjstr._cjstr_to_wchar_ptr(this.ptr));
        }

        static fromString(str) {
            const ptr = cjstr._cjstr_create(str.length);

            const string_ptr = cjstr._cjstr_to_wchar_ptr(ptr);

            cjstr.stringToUTF32(str, string_ptr, 4 * (str.length + 1));

            return new CJSStr(ptr);
        }
    }

    const s = [CJSStr.fromString("Test!"), CJSStr.fromString("Test2!"), CJSStr.fromString("Test3!")];
    console.log(s[0].length, s[1].length, s[2].length);
    console.log(s[2].toString());
    console.log(s[2].concat(s[1]).concat(s[0], s[2]).toString());
}

cjstrFactory().then(main);