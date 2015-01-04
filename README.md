# Spiritiz

* spiritiz is a base of boost::spirit examples

* Done by Eloi du Bois

* LICENSE: LGPLv3

## Compilation

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


## Examples

Please note that ```scons example_name``` will build the example in question

* spiritizExample1

**Usage:** spiritizExample1 spiritzExample1.input 

This example needs a file having lines of this kind:

```
12*3-4*1
2 +3-4*3
2+3*4*3
```

The parser output all computed results in a vector<double>, the program iterates over the vector and display results.


* m3uParser

**Usage:** m3uParser absolute-paths.m3u

Should output the result of the m3u parsing (a vector<m3uParser::PlaylistItem>):

```
Playlist items: 
---
Filename: "file:///Users/admin/Music/_Playlist mariage/musique mariage/cajun/01. Offshore Blues.mp3"
Duration: 166
Infos: Offshore Blues
---
Filename: "file:///Users/admin/Music/_Playlist mariage/musique mariage/cajun/09. Mardi-Gras Song.mp3"
Duration: 134
Infos: Mardi-Gras Song
---
Filename: "file:///Users/admin/Music/_Playlist mariage/musique mariage/cajun/08. Valse de Bayou Teche.mp3"
Duration: 126
Infos: Valse de Bayou Teche
```

 
