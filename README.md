# INTRODUCTION

* spiritiz is a base of boost::spirit examples

* Done by Eloi du Bois

* LICENSE: LGPLv3

# Compilation

To compile, you will need boost and scons:

* boost: (http://www.boost.org/users/download/)
* scons: (http://www.scons.org/)

First, clone the repository:

```
git clone https://github.com/edubois/spiritiz.git
cd spiritiz
git submodule update -i
```

This should bring tools/sconsProject

now, go into tools/sconsProject

and do (this is mandatory):

```git checkout precompiled_header_proposal```


Now, it's time to edit default.sconf according to your configuration.
In the default configuration, I made a parent directory 3rdParties where I put
my 3rd party libraries. To change your external libraries base dir, 
edit the variable extern in this file (default.sconf).
If you are using Mac, adapt the last lines according to your
XCode configuration.
If you are not using Mac, remove the lines after '# Mac only'

When you are ready, enter:

scons mode=release

This will build the default example application.


#Examples (scons <example_name> will build the example in question):

* spiritizExample1

**Usage:** spiritizExample1 spiritzExample1.input 

This example needs a file having lines of this kind:

```
12*3-4*1
2 +3-4*3
2+3*4*3
```

Then it put all computed results in a vector<double>



