


#include "milter-test-enum-types.h"
#include "milter-test-utils.h"
#include "milter-test-client.h"
#include "milter-test-server.h"

/* enumerations from "milter-test-utils.h" */
GType
milter_test_errno_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_TEST_ERRNO_ECONNREFUSED, "MILTER_TEST_ERRNO_ECONNREFUSED", "econnrefused" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterTestErrno", values);
  }
  return etype;
}



