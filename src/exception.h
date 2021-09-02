#ifndef EXCEPTION
#define EXCEPTION

class Exception {
    public:
        Exception(int code) {this->code = code;};
        int getCode() {return this->code;};
    private:
        int code;
};

#endif