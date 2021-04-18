set(test_pinky_exe test-pinky)

add_executable(${test_pinky_exe} 
	test_cmap.cpp
	test_operator.cpp
	test_function.cpp
	test_extraction.cpp
	test_tokenization.cpp
	test_infix_to_postfix.cpp
	test_postfix_evaluation.cpp
	test_pinky.cpp
)

target_include_directories(${test_pinky_exe} PRIVATE 
	${CMAKE_SOURCE_DIR}/vendor
	${CMAKE_SOURCE_DIR}/src
)

target_compile_features(${test_pinky_exe} PRIVATE cxx_std_20)

include(${CMAKE_SOURCE_DIR}/tools/cmake/CompilerWarnings.cmake)
set_project_warnings(${test_pinky_exe})

include(${CMAKE_SOURCE_DIR}/tools/cmake/OutputDirectories.cmake)
make_lib_directory(lib_directory)
make_bin_directory(bin_directory)

target_link_libraries(${test_pinky_exe} PRIVATE
	${lib_directory}/libpinky-core.a
)

set_target_properties(${test_pinky_exe} PROPERTIES 
	LINKER_LANGUAGE CXX
	CXX_EXTENSIONS OFF
	RUNTIME_OUTPUT_DIRECTORY ${bin_directory}/tests
)
