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
    visibility = ["//visibility:public"],
)

cc_library(
    name = "gflags",
    visibility = ["//visibility:public"],
    includes = [
      "gflags_hdr/",
    ],
    srcs = [
      "gflags/src/gflags.cc",
      "gflags/src/gflags_completions.cc",
      "gflags/src/gflags_reporting.cc",
    ],
    hdrs = [
      "gflags_hdr/config.h",
      "gflags_hdr/gflags.h",
      "gflags_hdr/gflags_completions.h",
      "gflags_hdr/gflags_declare.h",
      "gflags_hdr/gflags_gflags.h",
      "gflags/src/util.h",
      "gflags/src/mutex.h",
    ],
    copts = [
      "-Ithird_party/gflags_hdr/",
    ],
    linkopts = [
      "-pthread",
    ],
)

