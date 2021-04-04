# Lists of hearders and sources
set(pinky-headers
	application.hpp
)

set(pinky-sources
	application.cpp
	main.cpp
)

# Static analyzer
include(${CMAKE_SOURCE_DIR}/tools/cmake/StaticAnalyzers.cmake)

# Executable compilation
set(exe_name pinky-cli)
add_executable(${exe_name} ${pinky-hearders} ${pinky-sources})

target_include_directories(${exe_name} PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_compile_features(${exe_name} PRIVATE cxx_std_20)

include(${CMAKE_SOURCE_DIR}/tools/cmake/CompilerWarnings.cmake)
set_project_warnings(${exe_name})

include(${CMAKE_SOURCE_DIR}/tools/cmake/OutputDirectories.cmake)
make_lib_directory(lib_directory)
make_bin_directory(bin_directory)

target_link_libraries(${exe_name}
	${lib_directory}/libpinky.a
)

set_target_properties(${exe_name} PROPERTIES 
	LINKER_LANGUAGE CXX
	CXX_EXTENSIONS OFF
	RUNTIME_OUTPUT_DIRECTORY ${bin_directory}
)
