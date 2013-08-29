


#ifndef __MILTER_SERVER_ENUM_TYPES_H__
#define __MILTER_SERVER_ENUM_TYPES_H__

#include <glib-object.h>

G_BEGIN_DECLS
/* enumerations from "milter-server-context.h" */
GType milter_server_context_error_get_type (void);
#define MILTER_TYPE_SERVER_CONTEXT_ERROR (milter_server_context_error_get_type())
GType milter_server_context_state_get_type (void);
#define MILTER_TYPE_SERVER_CONTEXT_STATE (milter_server_context_state_get_type())
G_END_DECLS

#endif /* __MILTER_SERVER_ENUM_TYPES_H__ */



