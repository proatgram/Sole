# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(SoleTests LANGUAGES CXX)

# ---- Tests ----

add_executable(Sole_test source/Sole_test.cpp)
target_compile_features(Sole_test PRIVATE cxx_std_17)

add_test(NAME Sole_test COMMAND Sole_test)

# ---- End-of-file commands ----

add_folders(Test)
