string(COMPARE EQUAL ${ENABLE_ANALYZER} True enable_clang_tidy)

if(enable_clang_tidy)
	find_program(CLANGTIDY clang-tidy)

	if(CLANGTIDY)
		message("-- Enable clang-tidy analizer")  
		set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY} -extra-arg=-Wno-unknown-warning-option)
	else()
		message(SEND_ERROR "clang-tidy requested but executable not found")
	endif()
endif()
