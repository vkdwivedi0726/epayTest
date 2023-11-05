1. Unzip PrintDirectoryTree
2. Go inside directory PrintDirectoryTree and create new directory build
3. Go inside build directory and run following commands:
	cmake -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
	cmake --build .
4. Go inside build and open PrintDirectoryTree.sln 
	(This will open project in Visual Studio)
5. On the top -- choose RelWithDebInfo and x64 as project build type. 
6. Build project.
7. Afte project is build, click Start without Debug