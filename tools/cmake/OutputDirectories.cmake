# Function to get binaries output directory according to built type
function(make_bin_directory bin_directory)
	set(bin_base_directory ${CMAKE_SOURCE_DIR}/bin)

	string(COMPARE EQUAL ${CMAKE_BUILD_TYPE} Debug is_debug_mode)
	string(COMPARE EQUAL ${CMAKE_BUILD_TYPE} Release is_release_mode)

	string(FIND ${CMAKE_CXX_COMPILER} g++ is_gcc)
	string(FIND ${CMAKE_CXX_COMPILER} clang++ is_clang)

	if(is_debug_mode)
		if(NOT (is_clang EQUAL -1))
			string(CONCAT bin_directory_tmp ${bin_base_directory} "/debug-clang")
		elseif(NOT (is_gcc EQUAL -1))
			string(CONCAT bin_directory_tmp ${bin_base_directory} "/debug-gcc")
		else()
			string(CONCAT bin_directory_tmp ${bin_base_directory} "/debug")
		endif()
	elseif(is_release_mode)
		if(NOT (is_clang EQUAL -1))
			string(CONCAT bin_directory_tmp ${bin_base_directory} "/release-clang")
		elseif(NOT (is_gcc EQUAL -1))
			string(CONCAT bin_directory_tmp ${bin_base_directory} "/release-gcc")
		else()
			string(CONCAT bin_directory_tmp ${bin_base_directory} "/release")
		endif()
	else()
		if(NOT (is_clang EQUAL -1))
			string(CONCAT bin_directory_tmp ${bin_base_directory} "/any-clang")
		elseif(NOT (is_gcc EQUAL -1))
			string(CONCAT bin_directory_tmp ${bin_base_directory} "/any-gcc")
		else()
			string(CONCAT bin_directory_tmp ${bin_base_directory} "/any")
		endif()
	endif()

	set(${bin_directory} ${bin_directory_tmp} PARENT_SCOPE)
endfunction()

# Function to get libraries output directory according to built type
function(make_lib_directory lib_directory)
	set(lib_base_directory ${CMAKE_SOURCE_DIR}/lib)

	string(COMPARE EQUAL ${CMAKE_BUILD_TYPE} Debug is_debug_mode)
	string(COMPARE EQUAL ${CMAKE_BUILD_TYPE} Release is_release_mode)

	string(FIND ${CMAKE_CXX_COMPILER} g++ is_gcc)
	string(FIND ${CMAKE_CXX_COMPILER} clang++ is_clang)

	if(is_debug_mode)
		if(NOT (is_clang EQUAL -1))
			string(CONCAT lib_directory_tmp ${lib_base_directory} "/debug-clang")
		elseif(NOT (is_gcc EQUAL -1))
			string(CONCAT lib_directory_tmp ${lib_base_directory} "/debug-gcc")
		else()
			string(CONCAT lib_directory_tmp ${lib_base_directory} "/debug")
		endif()
	elseif(is_release_mode)
		if(NOT (is_clang EQUAL -1))
			string(CONCAT lib_directory_tmp ${lib_base_directory} "/release-clang")
		elseif(NOT (is_gcc EQUAL -1))
			string(CONCAT lib_directory_tmp ${lib_base_directory} "/release-gcc")
		else()
			string(CONCAT lib_directory_tmp ${lib_base_directory} "/release")
		endif()
	else()
		if(NOT (is_clang EQUAL -1))
			string(CONCAT lib_directory_tmp ${lib_base_directory} "/any-clang")
		elseif(NOT (is_gcc EQUAL -1))
			string(CONCAT lib_directory_tmp ${lib_base_directory} "/any-gcc")
		else()
			string(CONCAT lib_directory_tmp ${lib_base_directory} "/any")
		endif()
	endif()

	set(${lib_directory} ${lib_directory_tmp} PARENT_SCOPE)
endfunction()
