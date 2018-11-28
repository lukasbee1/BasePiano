Audiere 32 bit and 64 bit binaries for development.  I couldn't find any existing ones, so here they are.

Versions used:
audiere: 1.9.4 (?) forked from Chad Austin's Audiere on github
flac: 1.3.1
libogg: 1.3.2
libvorbis: 1.3.5

NOTE: The 64 bit binaries are missing mod/xm playback because I was too lazy to find and compile Dumb.  Also missing speexfile support, whatever that is.

If you'd like to do it yourself (remove NO_DUMB and NO_SPEEX preprocessor definitions and add the libs), I put the source with all depedencies on github.  (tweaked for msvc2005 release 32 and 64 bit compiles)

Github: https://github.com/SethRobinson/Audiere

Seth A Robinson
www.rtsoft.com
@rtsoft