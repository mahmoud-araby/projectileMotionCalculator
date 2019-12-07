##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=projectileMotionCalculator
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=E:/examples/Lists/Lists
ProjectPath            :=E:/examples/Lists/Lists/projectileMotionCalculator
IntermediateDirectory  :=../build-$(ConfigurationName)/projectileMotionCalculator
OutDir                 :=../build-$(ConfigurationName)/projectileMotionCalculator
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=MAHMOUD
Date                   :=07/12/2019
CodeLitePath           :="C:/Program Files (x86)/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
Objects0=../build-$(ConfigurationName)/projectileMotionCalculator/main.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/projectileMotionCalculator/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\projectileMotionCalculator" mkdir "..\build-$(ConfigurationName)\projectileMotionCalculator"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\projectileMotionCalculator" mkdir "..\build-$(ConfigurationName)\projectileMotionCalculator"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/projectileMotionCalculator/.d:
	@if not exist "..\build-$(ConfigurationName)\projectileMotionCalculator" mkdir "..\build-$(ConfigurationName)\projectileMotionCalculator"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/projectileMotionCalculator/main.c$(ObjectSuffix): main.c ../build-$(ConfigurationName)/projectileMotionCalculator/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/examples/Lists/Lists/projectileMotionCalculator/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/projectileMotionCalculator/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/projectileMotionCalculator/main.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/projectileMotionCalculator/main.c$(DependSuffix) -MM main.c

../build-$(ConfigurationName)/projectileMotionCalculator/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/projectileMotionCalculator/main.c$(PreprocessSuffix) main.c


-include ../build-$(ConfigurationName)/projectileMotionCalculator//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


