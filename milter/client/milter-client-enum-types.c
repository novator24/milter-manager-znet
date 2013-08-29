


#include "milter-client-enum-types.h"
#include "milter-client.h"
#include "milter-client-context.h"
#include "milter-client-runner.h"
#include "milter-client-single-thread-runner.h"
#include "milter-client-objects.h"

/* enumerations from "milter-client.h" */
GType
milter_client_event_loop_backend_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_CLIENT_EVENT_LOOP_BACKEND_DEFAULT, "MILTER_CLIENT_EVENT_LOOP_BACKEND_DEFAULT", "default" },
      { MILTER_CLIENT_EVENT_LOOP_BACKEND_GLIB, "MILTER_CLIENT_EVENT_LOOP_BACKEND_GLIB", "glib" },
      { MILTER_CLIENT_EVENT_LOOP_BACKEND_LIBEV, "MILTER_CLIENT_EVENT_LOOP_BACKEND_LIBEV", "libev" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterClientEventLoopBackend", values);
  }
  return etype;
}
GType
milter_client_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_CLIENT_ERROR_RUNNING, "MILTER_CLIENT_ERROR_RUNNING", "running" },
      { MILTER_CLIENT_ERROR_UNIX_SOCKET, "MILTER_CLIENT_ERROR_UNIX_SOCKET", "unix-socket" },
      { MILTER_CLIENT_ERROR_IO_ERROR, "MILTER_CLIENT_ERROR_IO_ERROR", "io-error" },
      { MILTER_CLIENT_ERROR_THREAD, "MILTER_CLIENT_ERROR_THREAD", "thread" },
      { MILTER_CLIENT_ERROR_PASSWORD_ENTRY, "MILTER_CLIENT_ERROR_PASSWORD_ENTRY", "password-entry" },
      { MILTER_CLIENT_ERROR_GROUP_ENTRY, "MILTER_CLIENT_ERROR_GROUP_ENTRY", "group-entry" },
      { MILTER_CLIENT_ERROR_DROP_PRIVILEGE, "MILTER_CLIENT_ERROR_DROP_PRIVILEGE", "drop-privilege" },
      { MILTER_CLIENT_ERROR_DETACH_IO, "MILTER_CLIENT_ERROR_DETACH_IO", "detach-io" },
      { MILTER_CLIENT_ERROR_DAEMONIZE, "MILTER_CLIENT_ERROR_DAEMONIZE", "daemonize" },
      { MILTER_CLIENT_ERROR_NOT_LISTENED_YET, "MILTER_CLIENT_ERROR_NOT_LISTENED_YET", "not-listened-yet" },
      { MILTER_CLIENT_ERROR_PROCESS, "MILTER_CLIENT_ERROR_PROCESS", "process" },
      { MILTER_CLIENT_ERROR_PID_FILE, "MILTER_CLIENT_ERROR_PID_FILE", "pid-file" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterClientError", values);
  }
  return etype;
}
GType
milter_client_context_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_CLIENT_CONTEXT_ERROR_INVALID_CODE, "MILTER_CLIENT_CONTEXT_ERROR_INVALID_CODE", "invalid-code" },
      { MILTER_CLIENT_CONTEXT_ERROR_IO_ERROR, "MILTER_CLIENT_CONTEXT_ERROR_IO_ERROR", "io-error" },
      { MILTER_CLIENT_CONTEXT_ERROR_NULL, "MILTER_CLIENT_CONTEXT_ERROR_NULL", "null" },
      { MILTER_CLIENT_CONTEXT_ERROR_INVALID_STATE, "MILTER_CLIENT_CONTEXT_ERROR_INVALID_STATE", "invalid-state" },
      { MILTER_CLIENT_CONTEXT_ERROR_INVALID_ACTION, "MILTER_CLIENT_CONTEXT_ERROR_INVALID_ACTION", "invalid-action" },
      { MILTER_CLIENT_CONTEXT_ERROR_EMPTY, "MILTER_CLIENT_CONTEXT_ERROR_EMPTY", "empty" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterClientContextError", values);
  }
  return etype;
}
GType
milter_client_context_state_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_CLIENT_CONTEXT_STATE_INVALID, "MILTER_CLIENT_CONTEXT_STATE_INVALID", "invalid" },
      { MILTER_CLIENT_CONTEXT_STATE_START, "MILTER_CLIENT_CONTEXT_STATE_START", "start" },
      { MILTER_CLIENT_CONTEXT_STATE_NEGOTIATE, "MILTER_CLIENT_CONTEXT_STATE_NEGOTIATE", "negotiate" },
      { MILTER_CLIENT_CONTEXT_STATE_NEGOTIATE_REPLIED, "MILTER_CLIENT_CONTEXT_STATE_NEGOTIATE_REPLIED", "negotiate-replied" },
      { MILTER_CLIENT_CONTEXT_STATE_CONNECT, "MILTER_CLIENT_CONTEXT_STATE_CONNECT", "connect" },
      { MILTER_CLIENT_CONTEXT_STATE_CONNECT_REPLIED, "MILTER_CLIENT_CONTEXT_STATE_CONNECT_REPLIED", "connect-replied" },
      { MILTER_CLIENT_CONTEXT_STATE_HELO, "MILTER_CLIENT_CONTEXT_STATE_HELO", "helo" },
      { MILTER_CLIENT_CONTEXT_STATE_HELO_REPLIED, "MILTER_CLIENT_CONTEXT_STATE_HELO_REPLIED", "helo-replied" },
      { MILTER_CLIENT_CONTEXT_STATE_ENVELOPE_FROM, "MILTER_CLIENT_CONTEXT_STATE_ENVELOPE_FROM", "envelope-from" },
      { MILTER_CLIENT_CONTEXT_STATE_ENVELOPE_FROM_REPLIED, "MILTER_CLIENT_CONTEXT_STATE_ENVELOPE_FROM_REPLIED", "envelope-from-replied" },
      { MILTER_CLIENT_CONTEXT_STATE_ENVELOPE_RECIPIENT, "MILTER_CLIENT_CONTEXT_STATE_ENVELOPE_RECIPIENT", "envelope-recipient" },
      { MILTER_CLIENT_CONTEXT_STATE_ENVELOPE_RECIPIENT_REPLIED, "MILTER_CLIENT_CONTEXT_STATE_ENVELOPE_RECIPIENT_REPLIED", "envelope-recipient-replied" },
      { MILTER_CLIENT_CONTEXT_STATE_DATA, "MILTER_CLIENT_CONTEXT_STATE_DATA", "data" },
      { MILTER_CLIENT_CONTEXT_STATE_DATA_REPLIED, "MILTER_CLIENT_CONTEXT_STATE_DATA_REPLIED", "data-replied" },
      { MILTER_CLIENT_CONTEXT_STATE_UNKNOWN, "MILTER_CLIENT_CONTEXT_STATE_UNKNOWN", "unknown" },
      { MILTER_CLIENT_CONTEXT_STATE_UNKNOWN_REPLIED, "MILTER_CLIENT_CONTEXT_STATE_UNKNOWN_REPLIED", "unknown-replied" },
      { MILTER_CLIENT_CONTEXT_STATE_HEADER, "MILTER_CLIENT_CONTEXT_STATE_HEADER", "header" },
      { MILTER_CLIENT_CONTEXT_STATE_HEADER_REPLIED, "MILTER_CLIENT_CONTEXT_STATE_HEADER_REPLIED", "header-replied" },
      { MILTER_CLIENT_CONTEXT_STATE_END_OF_HEADER, "MILTER_CLIENT_CONTEXT_STATE_END_OF_HEADER", "end-of-header" },
      { MILTER_CLIENT_CONTEXT_STATE_END_OF_HEADER_REPLIED, "MILTER_CLIENT_CONTEXT_STATE_END_OF_HEADER_REPLIED", "end-of-header-replied" },
      { MILTER_CLIENT_CONTEXT_STATE_BODY, "MILTER_CLIENT_CONTEXT_STATE_BODY", "body" },
      { MILTER_CLIENT_CONTEXT_STATE_BODY_REPLIED, "MILTER_CLIENT_CONTEXT_STATE_BODY_REPLIED", "body-replied" },
      { MILTER_CLIENT_CONTEXT_STATE_END_OF_MESSAGE, "MILTER_CLIENT_CONTEXT_STATE_END_OF_MESSAGE", "end-of-message" },
      { MILTER_CLIENT_CONTEXT_STATE_END_OF_MESSAGE_REPLIED, "MILTER_CLIENT_CONTEXT_STATE_END_OF_MESSAGE_REPLIED", "end-of-message-replied" },
      { MILTER_CLIENT_CONTEXT_STATE_QUIT, "MILTER_CLIENT_CONTEXT_STATE_QUIT", "quit" },
      { MILTER_CLIENT_CONTEXT_STATE_QUIT_REPLIED, "MILTER_CLIENT_CONTEXT_STATE_QUIT_REPLIED", "quit-replied" },
      { MILTER_CLIENT_CONTEXT_STATE_ABORT, "MILTER_CLIENT_CONTEXT_STATE_ABORT", "abort" },
      { MILTER_CLIENT_CONTEXT_STATE_ABORT_REPLIED, "MILTER_CLIENT_CONTEXT_STATE_ABORT_REPLIED", "abort-replied" },
      { MILTER_CLIENT_CONTEXT_STATE_FINISHED, "MILTER_CLIENT_CONTEXT_STATE_FINISHED", "finished" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterClientContextState", values);
  }
  return etype;
}
GType
milter_client_runner_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_CLIENT_RUNNER_ERROR_RUNNING, "MILTER_CLIENT_RUNNER_ERROR_RUNNING", "running" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterClientRunnerError", values);
  }
  return etype;
}
GType
milter_client_single_thread_runner_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_CLIENT_SINGLE_THREAD_RUNNER_ERROR_TODO, "MILTER_CLIENT_SINGLE_THREAD_RUNNER_ERROR_TODO", "todo" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterClientSingleThreadRunnerError", values);
  }
  return etype;
}



