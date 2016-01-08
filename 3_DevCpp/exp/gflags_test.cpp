#include <iostream>
#include <string>

#include <gflags.h>

using namespace std;
using namespace google;

static bool ValidateNum(const char* flagname, int32 value) {
    if (value>0 && value<325) return true;
    cout << "Invalid value for " << flagname << ": " << (int) value << endl;
    return false;
}

DEFINE_int32( arg_val, 28, "A random integer" );
static const bool valid1 = RegisterFlagValidator(&FLAGS_arg_val, &ValidateNum);

int main(int argc, char** argv)
{
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    cout << "Integer Flag: " << FLAGS_arg_val << endl;
    return 0;
}
