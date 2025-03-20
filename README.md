## duration

This code lifted from develop branch of https://github.com/opendnssec/opendnssec 

Copyright remains:

```
 * Copyright (c) 2009-2018 NLNet Labs.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ```

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
