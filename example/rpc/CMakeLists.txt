set(CALLEE_LIST ./callee/userservice.cc user.pb.cc)
add_executable(provider ${CALLEE_LIST})
target_link_libraries(provider apollo)

set(CALLER_LIST ./caller/calluserservice.cc user.pb.cc)
add_executable(consumer ${CALLER_LIST})
target_link_libraries(consumer apollo)