# Lists of hearders and sources
set(pinky-headers
	cmap.hpp
	constant.hpp
	error.hpp
	function.hpp
	operator.hpp
	token.hpp
	parse.hpp
	evaluation.hpp
)

set(pinky-sources
	function.cpp
	operator.cpp
	parse.cpp
	evaluation.cpp
)

# Library compilation
set(lib_name pinky)
add_library(${lib_name} STATIC ${pinky-hearders} ${pinky-sources})

target_include_directories(${lib_name} PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_compile_features(${lib_name} PRIVATE cxx_std_20)

target_compile_options(${lib_name} PRIVATE 
	"-Wall"
	"-Wextra"
	"-pedantic"
)

include(${CMAKE_SOURCE_DIR}/tools/cmake/OutputDirectories.cmake)
make_lib_directory(lib_directory)

set_target_properties(${lib_name} PROPERTIES 
	LINKER_LANGUAGE CXX
	CXX_EXTENSIONS OFF
	ARCHIVE_OUTPUT_DIRECTORY ${lib_directory}
)
