


#ifndef __MILTER_CLIENT_ENUM_TYPES_H__
#define __MILTER_CLIENT_ENUM_TYPES_H__

#include <glib-object.h>

G_BEGIN_DECLS
/* enumerations from "milter-client.h" */
GType milter_client_event_loop_backend_get_type (void);
#define MILTER_TYPE_CLIENT_EVENT_LOOP_BACKEND (milter_client_event_loop_backend_get_type())
GType milter_client_error_get_type (void);
#define MILTER_TYPE_CLIENT_ERROR (milter_client_error_get_type())
GType milter_client_context_error_get_type (void);
#define MILTER_TYPE_CLIENT_CONTEXT_ERROR (milter_client_context_error_get_type())
GType milter_client_context_state_get_type (void);
#define MILTER_TYPE_CLIENT_CONTEXT_STATE (milter_client_context_state_get_type())
GType milter_client_runner_error_get_type (void);
#define MILTER_TYPE_CLIENT_RUNNER_ERROR (milter_client_runner_error_get_type())
GType milter_client_single_thread_runner_error_get_type (void);
#define MILTER_TYPE_CLIENT_SINGLE_THREAD_RUNNER_ERROR (milter_client_single_thread_runner_error_get_type())
G_END_DECLS

#endif /* __MILTER_CLIENT_ENUM_TYPES_H__ */



