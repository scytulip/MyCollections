cc_library(
    name = "opencv2",
    srcs = glob([
        "usr/local/lib/libopencv_*.so"
    ]),
    hdrs = glob([
        "usr/local/include/opencv2/**/*.h*",
        "usr/local/include/opencv/*.h*",
        "usr/include/c++/4.8/**/*",
        "usr/include/x86_64-linux-gnu/c++/4.8/**/*.h*"
    ]),
    copts = [
        "-Ithird_party/usr/local/include",
	"-Ithird_party/usr/include/c++/4.8",
	"-Ithird_party/usr/include/x86_64-linux-gnu/c++/4.8",
    ],
    visibility = ["//visibility:public"],
)
