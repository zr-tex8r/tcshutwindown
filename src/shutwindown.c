#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <windows.h>

/* Initiates system shutdown.
 * Returns a bool showing whether the job succeeded.
 */
static BOOL shutdown_system (void)
{
    HANDLE TokenHandle;
    TOKEN_PRIVILEGES Privileges;
    
    if (!OpenProcessToken(GetCurrentProcess(),
            TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY,
            &TokenHandle))
        return FALSE;
    Privileges.PrivilegeCount = 1;
    Privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,
            &Privileges.Privileges[0].Luid);
    AdjustTokenPrivileges(TokenHandle, FALSE, &Privileges,
            0, NULL, NULL);
    if (GetLastError() != ERROR_SUCCESS)
        return FALSE;

    return ExitWindowsEx(EWX_SHUTDOWN, 0);
}

/* Lua function 'shutdown'.
 *   shutdown()
 */
static int l_shutdown(lua_State* L)
{
    if (!shutdown_system()) {
        return luaL_error(L, "cannot initiate shutdown");
    }
    return 0;
}

/* Lua function 'sleep'.
 *   sleep(number sec)
 * Sleeps for 'sec' seconds.
 */
static int l_sleep(lua_State* L)
{
    lua_Number sec = lua_tonumber(L, 1);
    DWORD msec = (DWORD)((double)sec * 1000.0);
    Sleep(msec);
    return 0;
}

/* Module registry */
static const luaL_reg registry[] = {
    {"sleep", l_sleep},
    {"shutdown", l_shutdown},
    {NULL, NULL}
};

/* Opens the module.
 */
__declspec(dllexport) int luaopen_shutwindown(lua_State *L)
{
  luaL_register(L, "shutwindown", registry);
  return 1;
}
