package(default_visibility = ["//visibility:public"])

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

# gflags
# https://github.com/gflags/gflags
cc_library(
    name = "gflags",
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
      "gflags_hdr/gflags_completions.h",
      "gflags_hdr/gflags_declare.h",
      "gflags_hdr/gflags_gflags.h",
      "gflags_hdr/gflags.h",
      "gflags/src/util.h",
      "gflags/src/mutex.h",
    ],
    linkopts = [
      "-pthread",
    ],
)

# Google Test
# https://github.com/google/googletest
cc_library(
    name = "googletest",
    includes = [
      "googletest/googletest/include",
    ],
    srcs = [
      "googletest/googletest/src/gtest.cc",
      "googletest/googletest/src/gtest-death-test.cc",
      "googletest/googletest/src/gtest-filepath.cc",
      "googletest/googletest/src/gtest-port.cc",
      "googletest/googletest/src/gtest-printers.cc",
      "googletest/googletest/src/gtest-test-part.cc",
      "googletest/googletest/src/gtest-typed-test.cc",
    ],
    hdrs = glob(
      ["googletest/googletest/include/**/*.h"]
    ) + [
      "googletest/googletest/src/gtest-internal-inl.h",
    ],
    copts = [
      "-Ithird_party/googletest/googletest",
    ],
    linkopts = [
      "-pthread",
    ],
)

[cc_library(
    name = "googletest_sample%s" % num,
    srcs = [
      "googletest/googletest/samples/sample%s.cc" % num,
    ],
    hdrs = [
      "googletest/googletest/samples/sample%s.h" % num,
    ],
) for num in ["1", "2", "4"]]

cc_library(
    name = "googletest_sample3",
    hdrs = [
      "googletest/googletest/samples/sample3-inl.h",
    ],
)

[cc_test(
    name = "googletest_sample%d_unittest" % num,
    srcs = [
      "googletest/googletest/samples/prime_tables.h",
      "googletest/googletest/samples/sample%d_unittest.cc" % num,
      "googletest/googletest/src/gtest_main.cc",
    ],
    deps = [
      ":googletest",
      ":googletest_sample1",
      ":googletest_sample2",
      ":googletest_sample3",
      ":googletest_sample4",
    ],
) for num in range(1, 9)]

[cc_test(
    name = "googletest_sample%d_unittest" % num,
    srcs = [
      "googletest/googletest/samples/prime_tables.h",
      "googletest/googletest/samples/sample%d_unittest.cc" % num,
    ],
    deps = [
      ":googletest",
      ":googletest_sample1",
      ":googletest_sample2",
      ":googletest_sample3",
      ":googletest_sample4",
    ],
) for num in range(9, 11)]