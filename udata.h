#include "config.h"
#include "utarray.h"
#ifdef HAVE_REDIS
# include <hiredis/hiredis.h>
#endif


struct udata {
	UT_array *topics;		/* Array of topics to subscribe to */
#ifdef HAVE_REDIS
	redisContext *redis;
#endif
	int usefiles;			/* True if files to be written */
	int ignoreretained;		/* True if retained messages should be ignored */
	char *pubprefix;		/* If not NULL (default), republish modified payload to <pubprefix>/topic */
	int skipdemo;			/* True if _demo users are to be skipped */
	int useredis;			/* True if we should do Redis (if we have it) */
};
