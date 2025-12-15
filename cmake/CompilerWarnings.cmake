set(CLANG_WARNINGS
      -Wall
      -Wextra 
      -Wshadow 
      -Wnon-virtual-dtor 
      # catch memory related errors
      -Wold-style-cast 
      -Wcast-align 
      -Wunused 
      -Woverloaded-virtual 
      -Wpedantic 
      -Wconversion
      -Wsign-conversion 
      -Wnull-dereference 
      -Wdouble-promotion
      -Wformat=2 
      -Wimplicit-fallthrough 
  )

set(PROJECT_WARNINGS ${CLANG_WARNINGS})
# target_compile_options(${project_name} INTERFACE ${PROJECT_WARNINGS})
