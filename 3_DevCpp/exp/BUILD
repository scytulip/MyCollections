cc_binary(
    name = "cJSON_test",
    srcs = ["cJSON_test.c"],
    deps = [
        "//cJSON",
    ],
)

cc_binary(
    name = "ImgOCV_test",
    srcs = ["ImgOCV_test.cpp"],
    deps = [
        "//third_party:opencv2",
    ],
    copts = [
        "-Ithird_party/usr/local/include",
	"-Ithird_party/usr/include/c++/4.8",
	"-Ithird_party/usr/include/x86_64-linux-gnu/c++/4.8",
    ],
)

cc_binary(
    name = "gflags_test",
    srcs = ["gflags_test.cpp"],
    deps = [
        "//third_party:gflags",
    ],
    copts = [
        "-Ithird_party/gflags_hdr",
    ],
)
