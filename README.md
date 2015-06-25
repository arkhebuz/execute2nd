#### Execute 2nd


Geany (micro)plugin, makes second execute entry in the build menu keybindable (currently its not, v1.24.1).
That's all glorious functionality.


##### Installation:
- Clone repo
- Compile (consult `makefile`)
- Copy `execute2nd.so` to Geany libdir (at `$(pkg-config --variable=libdir geany)/geany`)
- Dependencies: try installing `libgtk2.0-dev intltool` if compiler freaks out
