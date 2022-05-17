# Copyright 2022 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# A minimal WORKSPACE file showing how to use the Access Approval API C++
# client library in Bazel-based projects.
workspace(name = "accessapproval_quickstart")

# Add the necessary Starlark functions to fetch google-cloud-cpp.
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Fetch the Google Cloud C++ libraries.
# NOTE: Update this version and SHA256 as needed.
http_archive(
    name = "com_github_googleapis_google_cloud_cpp",
    sha256 = "fb62f0e7dc964c5d3cd0d85977b85f3e0e7dce97e9029abf9c32ecc29db07043",
    strip_prefix = "google-cloud-cpp-1.40.1",
    url = "https://github.com/googleapis/google-cloud-cpp/archive/v1.40.1.tar.gz",
)

# Load indirect dependencies due to
#     https://github.com/bazelbuild/bazel/issues/1943
load("@com_github_googleapis_google_cloud_cpp//bazel:google_cloud_cpp_deps.bzl", "google_cloud_cpp_deps")

google_cloud_cpp_deps()

load("@com_google_googleapis//:repository_rules.bzl", "switched_rules_by_language")

switched_rules_by_language(
    name = "com_google_googleapis_imports",
    cc = True,
    grpc = True,
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")

grpc_extra_deps()
