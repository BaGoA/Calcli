set(test_calcli_exe test-calcli)

set(test_calcli_sources 
	test_toto.cpp
	test_calcli.cpp
)

add_executable(${test_calcli_exe} ${test_calcli_sources})

target_include_directories(${test_calcli_exe} PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(${test_calcli_exe}
	gtest gtest_main
	stdc++fs
)

target_compile_features(${test_calcli_exe} PRIVATE cxx_std_17)

include(${CMAKE_SOURCE_DIR}/cmake/OutputDirectories.cmake)
make_bin_directory(bin_directory)

set_target_properties(${test_calcli_exe} PROPERTIES 
	LINKER_LANGUAGE CXX
	CXX_EXTENSIONS OFF
	RUNTIME_OUTPUT_DIRECTORY ${bin_directory}/tests
)

