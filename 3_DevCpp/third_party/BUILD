package(default_visibility = ["//visibility:public"])

# OpenCV (external)
LOCAL_INC = "usr/local/include/"
SYS_INC = "usr/include/"

cc_library(
    name = "opencv2",
    srcs = glob([
      "usr/local/lib/libopencv_*.so"
    ]),
    hdrs = glob([
        LOCAL_INC + "opencv2/**/*.h*",
        LOCAL_INC + "opencv/*.h*",
        SYS_INC + "c++/4.8/**/*",
        SYS_INC + "x86_64-linux-gnu/c++/4.8/**/*.h*"
    ]),
    copts = [
      "-Ithird_party/" + LOCAL_INC,
      "-Ithird_party/" + SYS_INC + "c++/4.8",
      "-Ithird_party/" + SYS_INC + "x86_64-linux-gnu/c++/4.8",
    ],
)

# Openssl - libssl (external)
# sudo apt-get install libssl-dev

cc_library(
    name = "libssl",
    srcs = [
      "usr/lib/x86_64-linux-gnu/libssl.so",
    ],
    hdrs = glob([
      "usr/include/openssl/*.h",
    ]),
)

# zlib
# https://github.com/madler/zlib.git

cc_library(
    name = "zlib",
    srcs = glob([
      "zlib/*.c"
    ]),
    hdrs = glob([
      "zlib/*.h"
    ]),
    includes = ["zlib/"],
    linkopts = [
      "-pthread",
    ],
)
