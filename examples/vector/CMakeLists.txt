project(c/examples/vector C)

set(CMAKE_CXX_STANDARD 99)

include_directories(.)

#add_executable(c test-framework/unity.c)
#add_executable(c test_vector.c
#                 test.h
#        test.c)
#add_executable(c vector.c)
add_executable(c
#        ../unions.c
#        ../../exercises/exercise0/doublyLinkedList/list.c
#        ../../exercises/exercise0/doublyLinkedList/main.c
        ../../exercises/exercise1/mygrep/main.c
        ../../exercises/exercise1/mygrep/mygrep.c
        ../../exercises/exercise1/mygrep/mygrep.h)