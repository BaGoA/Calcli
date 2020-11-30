# Lists of hearders and sources
set(calcli-core-headers
	token.hpp
	error.hpp
	cmap.hpp
	operator.hpp
	function.hpp
	lexer.hpp
	evaluator.hpp
)

set(calcli-core-sources
	lexer.cpp
	evaluator.cpp
)

# Executable compilation
set(lib_name calcli-core)
add_library(${lib_name} STATIC ${calci-core-hearders} ${calcli-core-sources})

target_include_directories(${lib_name} PRIVATE ${CMAKE_SOURCE_DIR})

target_compile_features(${lib_name} PRIVATE cxx_std_20)

target_compile_options(${lib_name} PRIVATE 
	"-Wall"
	"-Wextra"
	"-pedantic"
)

include(${CMAKE_SOURCE_DIR}/cmake/OutputDirectories.cmake)
make_lib_directory(lib_directory)

set_target_properties(${lib_name} PROPERTIES 
	LINKER_LANGUAGE CXX
	CXX_EXTENSIONS OFF
	ARCHIVE_OUTPUT_DIRECTORY ${lib_directory}
)
