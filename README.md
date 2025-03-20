## duration

```console
$ ./8601-secs P1D PT2H5S P1Y P4H10M5S
86400
7205
31536000
10713600
```

## history

This code lifted from develop branch of https://github.com/opendnssec/opendnssec 

I applied the following patch to the two files I'm interested in: `duration.[ch]`:

```diff
diff --git common/duration.c common/duration.c
index 1a3f273..4b30522 100644
--- common/duration.c
+++ common/duration.c
@@ -29,9 +29,9 @@
  * Durations.
  */
 
-#include "status.h"
+#define ods_log_error printf
+
 #include "duration.h"
-#include "log.h"
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -51,7 +51,10 @@ duration_create(void)
 {
     duration_type* duration;
 
-    CHECKALLOC(duration = (duration_type*) malloc(sizeof(duration_type)));
+    if ((duration = (duration_type*) malloc(sizeof(duration_type))) == NULL) {
+        fprintf(stderr, "Out of memory\n");
+        return (NULL);
+    };
     duration->years = 0;
     duration->months = 0;
     duration->weeks = 0;
diff --git common/duration.h common/duration.h
index 5a388f4..ef2267f 100644
--- common/duration.h
+++ common/duration.h
@@ -32,7 +32,6 @@
 #ifndef UTIL_DURATION_H
 #define UTIL_DURATION_H
 
-#include "config.h"
 
 #include <stdint.h>
 #include <time.h>
```
