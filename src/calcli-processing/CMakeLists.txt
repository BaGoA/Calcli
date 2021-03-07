# Lists of hearders and sources
set(calcli-processing-headers
	parse.hpp
	evaluation.hpp
)

set(calcli-processing-sources
	parse.cpp
	evaluation.cpp
)

# Library compilation
set(lib_name calcli-processing)
add_library(${lib_name} STATIC ${calci-processing-hearders} ${calcli-processing-sources})

target_include_directories(${lib_name} PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_compile_features(${lib_name} PRIVATE cxx_std_20)

target_compile_options(${lib_name} PRIVATE 
	"-Wall"
	"-Wextra"
	"-pedantic"
)

include(${CMAKE_SOURCE_DIR}/tools/cmake/OutputDirectories.cmake)
make_lib_directory(lib_directory)

target_link_libraries(${lib_name}
	${lib_directory}/libcalcli-core.a
)

set_target_properties(${lib_name} PROPERTIES 
	LINKER_LANGUAGE CXX
	CXX_EXTENSIONS OFF
	ARCHIVE_OUTPUT_DIRECTORY ${lib_directory}
)
