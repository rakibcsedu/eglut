Eglut - (version 0.1)

SETTING EGLUT IN MSVC 6.0 :-

=======================================================================================================

1. Start MSVC and create a new C/C++ project. 

2. Now click Tools -> Options -> Directories, 

3. To include header files, Under 'Show directories for:' check 'Include files' and add absolute path of 
   eglut 'include' folder. Inlcuded path should look like "..\eglut\include" 

3. To include library files, Under 'Show directories for:' check 'Library files' and add absolute path of
   eglut 'lib' folder. Included path should look like "..\eglut\lib" 

4. click 'Ok'

5. There is a 'bin' folder that contains glut32.dll, copy this file to your project folder or add
   a path to 'bin' folder in your system path or copy the file in "\WINDOWS\system32"

6. Try to build the project, but it should give some errors, thats because you need to add 2 source 
   file with your project, you can either copy the files manunally in your project directory or 

7. Click Project -> Add to Project -> Files, now include the eglut.cpp and imagelib.cpp, they can be 
   found in 'src' folder under 'eglut' directory.  

8. Now build and run the project, also copy necessary image files in your project directory. 

=======================================================================================================