#define __STR2__(x) #x
#define __STR1__(x) __STR2__(x)
#define __PRAGMA_LOC__ __FILE__ "("__STR1__(__LINE__)") "
#define _warning(c, x) __pragma(message(__PRAGMA_LOC__ ": warning " #c ":" x)) // x - warning, c - code
#define _error(c, x) __pragma(message(__PRAGMA_LOC__ ": error " #c ": " x)) // x - error, c - code