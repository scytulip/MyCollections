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
      "-Iexternal/" + LOCAL_INC,
      "-Iexternal/" + SYS_INC + "c++/4.8",
      "-Iexternal/" + SYS_INC + "x86_64-linux-gnu/c++/4.8",
    ],
)

