Eglut - (version 0.1)

SETTING EGLUT IN CODE::BLOCKS :-

============================================================================================

1. Start code::blocks 

2. Click 'Settings' -> 'Compiler and debugger' 

3. Click on the tab 'Search directories' 

4. Now, under 'Compiler' tab click 'add'. Paste the path of 'include' folder of eglut and click 'ok'. 
   For me tha path is 'D:\eglut_ver0.1\eglut\include'

5. Now, under 'linker' tab do the same thing for 'lib' folder. 
   For me tha path is 'D:\eglut_ver0.1\eglut\lib'

6. Now click on 'Linker settings' tab , left of 'Search directories' Under 'Link Libraries'
   click 'add', then type 'libsoil' and click 'ok'. This way add 'libglut32' and 'libopengl32' one at a time.
   After adding them click 'ok' and you are done. 
   NOTE : If you add 'libopengl32' before adding 'libsoil' you might get error 'Undefined references'.

7. By doing these, path of eglut header files and lib files are accessible from all code::blocks project.

8. Now create a C/C++ console project and copy the code of any sample file into your main.c/main.cpp

9. To build and run your program press 'F9', if there is no error your program will run. 
   But your program might not found 'glut32.dll' You will find 'glut32.dll' in 
   '..\eglut\bin' folder. 

10. After that you should be able to compile and run sample programs in code::blocks   
   
============================================================================================
