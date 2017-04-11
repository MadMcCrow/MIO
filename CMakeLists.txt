cmake_minimum_required(VERSION 3.0)
# Declaration of the project

project(MyProject)

# Creating a repository for binary files
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE}) 


# Including ViconDataStreamSDK_CPP directory
include_directories(StartConnection/libs)

# Linking directory 
link_directories(StartConnection/libs)

# Finding automatically the source files
file(
	GLOB_RECURSE	# Récupération d'une liste de fichier recursivement

	source_files_starter	# Stocker la liste dans une variable

	StartConnection/src/*		# Dossier de recherche
)

# Declaration of executables

add_executable(

	starter		# Nom de l'executable

	${source_files_starter} 
)


# Linking libraries to executables
target_link_libraries(

	starter		

	ViconDataStreamSDK_CPP

)

