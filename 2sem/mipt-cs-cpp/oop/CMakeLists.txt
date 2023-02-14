project("bank")

include (CTest)
add_executable(bank main.cpp bank.cpp)
set_property(TARGET bank PROPERTY CXX_STANDARD 20)
add_test(example bank)