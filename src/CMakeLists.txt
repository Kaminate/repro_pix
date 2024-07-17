

add_library( Renderer )
target_sources( Renderer
  PUBLIC
  repro_renderer.h

  PRIVATE
  repro_renderer.cpp
)

add_executable( Repro WIN32 )


target_sources( Repro PRIVATE
  repro_main.cpp
  repro_assert.cpp
  repro_assert.h
  repro_globals.cpp
  repro_globals.h
  repro_window.cpp
  repro_window.h
)

target_link_libraries( Repro Renderer )

include( ${CMAKE_SOURCE_DIR}/cmake/pix.cmake )
add_pix_target()
target_link_libraries( Renderer PIX )

add_custom_command( TARGET Repro
                    PRE_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different
                            ${PIX_DLL_PATH}
                            $<TARGET_FILE_DIR:Repro> )

