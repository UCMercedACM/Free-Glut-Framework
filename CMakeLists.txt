cmake_minimum_required (VERSION 2.8)
project (Cross_Platform_Glut_Game_Framework)

file(GLOB Cross_Platform_Glut_Game_Framework_SRC
	“src/Actors/*"
    “src/Audio/*"
    “src/Controls/*"
    “src/Core/*"
    “src/GameLogic/*"
    “src/Objects/*"
    “src/Render/*"
)

# Are we compiling on Windows?
IF (${CMAKE_SYSTEM_NAME} MATCHES "Windows")


    # Windows Libraries
    target_link_libraries(Cross_Platform_Glut_Game_Framework "opengl32.lib")

	#enable Multiprocessor build
	SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /MP" )
	
	#copy game and dlls
	file(COPY ${PROJECT_SOURCE_DIR}/assets/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
	file(COPY ${PROJECT_SOURCE_DIR}/libs/windows/_alldlls/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
	file(COPY ${PROJECT_SOURCE_DIR}/libs/windows/_alldlls/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)

	
ENDIF (${CMAKE_SYSTEM_NAME} MATCHES "Windows")

# Are we compiling on Mac OS X?
IF (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    # Make sure Xcode uses Clang set for libc++ and c++ version 2011
	set(CMAKE_XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
	set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")
	set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")

	# Needed for performing Makefile build on OS X, as above parameters are Xcode specific
	set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -stdlib=libc++ -g -Wall")

	# Setup the names for things
    set( EXE_NAME "Cross_Platform_Glut_Game_Framework")
    set( MACOSX_BUNDLE_INFO_STRING "@EXE_NAME@ - Version 0.0.1" )
    set( MACOSX_BUNDLE_BUNDLE_VERSION 0.0.1 )
    set( MACOSX_BUNDLE_GUI_IDENTIFIER "com.letsrtfm.Cross_Platform_Glut_Game_Framework" )
    set( MACOSX_BUNDLE_BUNDLE_NAME "@EXE_NAME@")

    # Find libraries
	find_library(OPENGL_FRAMEWORK     NAMES OpenGL     PATHS ${PROJECT_SOURCE_DIR}/libs/osx/frameworks)

	# Copy the resources into the app bundle
	file(GLOB MACOSX_RESOURCES ${PROJECT_SOURCE_DIR}/assets/* )
	set_source_files_properties(${MACOSX_RESOURCES} PROPERTIES MACOSX_PACKAGE_LOCATION Resources)

	# Copy the frameworks into the app bundle
	file(GLOB MACOSX_FRAMEWORKS ${PROJECT_SOURCE_DIR}/libs/osx/frameworks/* )
	set(MACOSX_FRAMEWORKS ${SDL2_FRAMEWORK} ${SDL2_TTF_FRAMEWORK} ${SDL2_MIXER_FRAMEWORK} ${CURL_FRAMEWORK} ${NOISE_FRAMEWORK})
	set_source_files_properties(${MACOSX_FRAMEWORKS} PROPERTIES MACOSX_PACKAGE_LOCATION Frameworks)

	# Declare the Cross_Platform_Glut_Game_Framework executable
	add_executable(Cross_Platform_Glut_Game_Framework MACOSX_BUNDLE ${Cross_Platform_Glut_Game_Framework_SRC} ${AppleCompatFiles} ${MACOSX_RESOURCES} ${MACOSX_FRAMEWORKS})

	# Set the runtime search path to look for frameworks and libraries in the Frameworks folder of the .app
	set_target_properties(Cross_Platform_Glut_Game_Framework PROPERTIES XCODE_ATTRIBUTE_LD_RUNPATH_SEARCH_PATHS "@loader_path @loader_path/../Frameworks")
    
    # Don't strip symbols on copy (for frameworks)
    set_target_properties(Cross_Platform_Glut_Game_Framework PROPERTIES XCODE_ATTRIBUTE_COPY_PHASE_STRIP "No")

    # Link the frameworks to Cross_Platform_Glut_Game_Framework

    target_link_libraries(Cross_Platform_Glut_Game_Framework ${OPENGL_FRAMEWORK})

ENDIF (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

# Are we compiling on Linux?
IF (${CMAKE_SYSTEM_NAME} MATCHES "Linux")

    # Linux is very good with package management and users should understand about the
    # highly organized system they run on.  Either way, depend on the libraries
    # being installed on the system.  OpenSuSE 13.1 had all dependecies in its repos

    # Required Libraries
    #
    # OpenGL Runtime (Mesa-libGL1, tested w/ 9.2.2-61.6.1) - http://www.mesa3d.org/
    # OpenGL Extension Wrangler (GLEW) - http://glew.sourceforge.net/
    # OpenGL Mathematics Library (GLM) - http://glm.g-truc.net/
    #
    # Simple Direct Media Layer (requires 2.0.0 or greater) - http://libsdl.org/download-2.0.php
    # Truetype Font Library for SDL (requires 2.0.12 or greater) - http://www.libsdl.org/projects/SDL_ttf/
    # Audio Mixer Library for SDL (requires 2.0.0 or greater) - http://www.libsdl.org/projects/SDL_mixer/
    #
    # libcurl (version 7.33.0 or greater) - http://curl.haxx.se/libcurl/
    # libnoise (version 1.0.0 or greater) - http://libnoise.sourceforge.net/
    #
    # A graphics card and driver supporting at least OpenGL 2.0, recommended 3.3+
    #
    # Graphics cards known to work
    #   - Nvidia GeForce GTX 770    (tested on Mac OS X and Linux)
    #   - Nvidia GeForce GTX 550 Ti (tested on Windows)
    #   - Intel HD Graphics 3000    (tested on Mac OS X)

	# Cross_Platform_Glut_Game_Framework Executable
	add_executable(Cross_Platform_Glut_Game_Framework ${Cross_Platform_Glut_Game_Framework_SRC})

    # Discover the include path and library for the system OpenGL Library
    find_path(OPENGL_INCLUDE_DIR NAMES GL/gl.h)
    include_directories(${OPENGL_INCLUDE_DIR})
    find_library(OPENGL_LIBRARY NAMES GL)
    target_link_libraries(Cross_Platform_Glut_Game_Framework ${OPENGL_LIBRARY})

    # Make a define, only used with Linux.  Also, make sure we use c++11
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__LINUX__")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -Wall")

ENDIF (${CMAKE_SYSTEM_NAME} MATCHES "Linux")

#Code should be organized

#Actors
FILE(GLOB ActorFiles
	"src/Actors/Actor.cpp“
	"src/Actors/Actor.h“
	"src/Actors/City.cpp“
	"src/Actors/City.h“
	"src/Actors/HostileCity.cpp“
	"src/Actors/HostileCity.h“
	"src/Actors/Player.cpp“
	"src/Actors/Player.h“
)
source_group(Actors FILES ${ActorFiles})

#Audio
FILE(GLOB AudioFiles
	"src/Audio/AudioCore.cpp“
	"src/Audio/AudioCore.h“
)
source_group(Audio FILES ${AudioFiles})

#Controls
FILE(GLOB ControlFiles
	"src/Controls/Controller.cpp“
	"src/Controls/Controller.h“
)
source_group(Controls FILES ${ControlFiles})

#Core
FILE(GLOB CoreFiles
	"src/Core/Engine.cpp“
	"src/Core/Engine.h“
	"src/Core/Game.cpp“
	"src/Core/Game.h“
	“src/Core/Main.cpp“
	"src/Core/stdafx.h“
)
source_group(Core FILES ${CoreFiles})

#Controls
FILE(GLOB LogicFiles
	"src/GameLogic/GameControl.cpp“
	"src/GameLogic/GameControl.h“
)
source_group(GameLogic FILES ${LogicFiles})

#Objects
FILE(GLOB ObjectFiles
	"src/Objects/aiming.cpp“
	"src/Objects/aiming.h“
	"src/Objects/Bomb.cpp“
	"src/Objects/Bomb.h“
	"src/Objects/Explosion.cpp“
	"src/Objects/Explosion.h“
	"src/Objects/Grid.cpp“
	"src/Objects/Grid.h“
	"src/Objects/Missle.cpp“
	"src/Objects/Missle.h“
)
source_group(Objects FILES ${ObjectFiles})

#Render
FILE(GLOB RenderFiles
	"src/Render/GraphicsCore.cpp“
	"src/Render/GraphicsCore.h“
	"src/Render/GraphicsObject.cpp“
	"src/Render/GraphicsObject.h“
)
source_group(Render FILES ${RenderFiles})

##########################################################################################
#UNIT TESTS