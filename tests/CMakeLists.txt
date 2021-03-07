set(test_calcli_exe test-calcli)

set(test_calcli_sources 
	test_cmap.cpp
	test_operator.cpp
	test_function.cpp
	test_tokenization.cpp
	test_infix_to_postfix.cpp
	test_postfix_evaluation.cpp
	test_calcli.cpp
)

add_executable(${test_calcli_exe} ${test_calcli_sources})

target_include_directories(${test_calcli_exe} PRIVATE 
	${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/src
)

target_compile_features(${test_calcli_exe} PRIVATE cxx_std_20)

target_compile_options(${test_calcli_exe} PRIVATE 
	"-Wall"
	"-Wextra"
	"-pedantic"
)

include(${CMAKE_SOURCE_DIR}/tools/cmake/OutputDirectories.cmake)
make_lib_directory(lib_directory)
make_bin_directory(bin_directory)

target_link_libraries(${test_calcli_exe} PRIVATE
	${lib_directory}/libcalcli-core.a
	${lib_directory}/libcalcli-processing.a
)

set_target_properties(${test_calcli_exe} PROPERTIES 
	LINKER_LANGUAGE CXX
	CXX_EXTENSIONS OFF
	RUNTIME_OUTPUT_DIRECTORY ${bin_directory}/tests
)
