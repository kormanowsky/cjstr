const cjstr = require('../c_js');

module.exports = class CJSStr {
    constructor(ptr) {
        this.ptr = ptr;
    }

    get length() {
        return cjstr._cjstr_length(this.ptr);
    }

    concat(...strs) {
        const stackPtr = cjstr.stackSave();

        const ptr = cjstr.stackAlloc(strs.length * cjstr.POINTER_SIZE);

        cjstr.stackRestore(stackPtr);

        let ptrCpy = ptr;

        for (let i = 0; i < strs.length; ++i) {
            cjstr.setValue(ptrCpy, strs[i].getPtr(), '*');

            ptrCpy += cjstr.POINTER_SIZE;
        }

        return new CJSStr(cjstr._cjstr_concat(this.ptr, ptr, strs.length));
    }

    getPtr() {
        return this.ptr;
    }

    toString() {
        return cjstr.UTF32ToString(cjstr._cjstr_to_wchar_ptr(this.ptr));
    }

    destroy() {
        cjstr._cjstr_destroy(this.ptr);
    }

    static fromString(str) {
        const ptr = cjstr._cjstr_create(str.length);

        const string_ptr = cjstr._cjstr_to_wchar_ptr(ptr);

        cjstr.stringToUTF32(str, string_ptr, 4 * (str.length + 1));

        return new CJSStr(ptr);
    }
}
