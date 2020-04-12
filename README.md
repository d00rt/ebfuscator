# Ebfuscator
Ebfuscator is the first tool that allows you to obfuscate strings using the ebfuscation technique.

Ebfuscator takes a C source file, the target platform (Windows, Linux) and a list of variables in the source you want to obfuscate. It applies a transformation based on Ebfuscation technique and produces a C source obfuscated file.

This tool is a proof of concept so there are many features that are not yet implemented and it has its limitations. For more information read the Limitations section.

## Ebfuscation: Abusing system errors for binary obfuscation
Ebfuscation, is a technique which can be used to implement different transformations such as Literals encoding, Control Flow Flattening and Virtualization. This technique is based on System's errors. To understand better how this technique works please read the article I wrote [here](https://www.d00rt.eus/2020/04/ebfuscation-abusing-system-errors-for.html) where I explain in detail the technique.

# Usage

Ebfuscator must be run from the project path, since it depends on the files located into {CURRENT_PATH}/errors/*

First you need to ebfuscate your source program

**Linux:**

`./ebfuscator.bin --platform [platform] --source [source] --var [variables] ...`


If success the folder **./output/** is created where you can find your C source code obfuscated (ebfuscated.c) and both errors.c and erros.h files where you can find the need code to generate errors for the target platform you chose.

So now you only need to compile the sources for your target platform. In case of linux you can do

`gcc -o my_program ./output/ebfuscated.c ./output/errors.c -lm`

Enjoy!

## Example

The following example uses the source program ./examples/crackme_test.c and it can be ebfuscated for both **Linux** and **Windows** 

1) ebfuscate the variable **passwd** for **windows** platform.

`./ebfuscator.bin --platform windows --source ./examples/crackme_test.c --var passwd`

2) ebfuscate the variables **passwd**, **invalid_pass** and **valid_pass**  for **linux** platform.

`./ebfuscator.bin --platform linux --source ./examples/crackme_test.c --var passwd valid_pass invalid_pass`


3) ebfuscate the variables **invalid_pass** and **valid_pass**  for **windows** platform.

`./ebfuscator.bin --platform windows --source ./examples/crackme_test.c --var valid_pass --var invalid_pass`

# Limitations
- **Analyzer:** The main idea of this project was not to have a powerful analyzer, rather the analyzer is very dumb. So in order for your variables to be found by the analyzer they have to be declared in compliance with the following requirements:
    - Declaration and initialization of the string/bytearray must be done in the same line.
    - The declaration must match the following regex **r#"([\s\t]*)char\s*\*?\s*{variable}\s*(\[[0-9]*\])?\s*=\s*(".*")\s*;"#**. Here some valid examples:
        - `char * valid = "test";`
        - `char valid[] = "test";`
        - `char valid[5] = "test\0";`
        - `char *shellcode = "\xDE\xAD\xBE\xEF";`
        
- **Platform:** At this moment the tool only supports **Windows** and **Linux** based operating systems.
- **Errors:** There are only a few errors implemented for each platform, this causes a lot of overhead when generating the obfuscated program. This overhead could be as well a feature but it's preferible to have the way to generate an error for a given value instead of combine different errors to get it. 

# Upcoming
- Ebfuscator code release.
- Stealthy mode to retrieve the errors. Instead of use GetLastError() or errno, read errors from TIB.
- Implementation of more errors, for both Windows and Linux (Pull Request are allowed :D)
