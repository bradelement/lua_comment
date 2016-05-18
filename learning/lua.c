#define lua_c

#include "lprefix.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

#if !defined(LUA_PROMPT)
#define LUA_PROMPT   "> "
#define LUA_PROMPT2  ">> "
#endif

#if !defined(LUA_MAXINPUT)
#define LUA_MAXINPUT 512
#endif

#if !defined(LUA_INIT_VAR)
#define LUA_INIT_VAR "LUA_INIT"
#endif

#define LUA_INITVARVERSION \
    LUA_INIT_VAR "_" LUA_VERSION_MAJOR "_" LUA_VERSION_MINOR
    

#if !defined(lua_stdin_is_tty)
    #if defined(LUA_USE_POSIX)
        #include <unistd.h>
        #define lua_stdin_is_tty() isatty(0)
    #elif defined(LUA_USE_WINDOWS)
        #include <io.h>
        #define lua_stdin_is_tty() _isatty(_fileno(stdin))
    #else
        #define lua_stdin_is_tty() 1  /*assume stdin is a tty*/
    #endif
#endif
