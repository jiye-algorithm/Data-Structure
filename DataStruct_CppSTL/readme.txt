Microsoft Visual C++ Users:

      Open directory  msvcpp

      Use the workspace/project "program.dsw". As a prototype,
      the project contains a program from Chapter 1. The graphics
      library is loaded in the project, so the project can
      be used both for programs that do and do not use the graphics
      package.

Borland Users:   
      
		To use the Borland 5.5 command line compiler, execute
	
			bcc32 prog_name.cpp
		
		for non-graphics programs, and
	
			bcc32 prog_name.cpp ..\ezdraw\ezd32b.lib
	
		for programs that use the graphics library.

Other contents in the "ftsoftds" directory:

      All classes and libraries that are developed in the book are
      located as header files in the directory "include"
 
      The programs that are developed in the book are located in
      the corresponding chapter directory (ch1 and so forth).

      The directory "ezdraw" contains the graphics libraries for 
      Microsoft Visual C++ (Ezd32m.lib) and Borland C++ (Ezd32b.lib).

         "Ezd32m.lib": A MicroSoft Visual C++ interface library for 
                       the 32-bit Windows graphics system.   
         "Ezd32b.lib": A Borland C++ interface library for the 
                       32-bit Windows graphics system.   

         The directory also contains a dynamic link library
         "EzDraw32.dll" that must reside in the Windows/System
         directory and the file "EzDraw.ini" that belongs in the
         Windows directory. It may be necessary to set Windows Explorer
         so it will view hidden and system files in order to see
         "EzDraw32.dll".

            Copy:      "EzDraw32.ini"  to "c:\Windows\"
            Copy:      "EzDraw32.dll"  to "c:\Windows\System"
