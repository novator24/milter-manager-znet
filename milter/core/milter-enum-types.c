


#include "milter-enum-types.h"
#include "milter-protocol.h"
#include "milter-decoder.h"
#include "milter-command-decoder.h"
#include "milter-reply-decoder.h"
#include "milter-encoder.h"
#include "milter-command-encoder.h"
#include "milter-reply-encoder.h"
#include "milter-error-emittable.h"
#include "milter-finished-emittable.h"
#include "milter-agent.h"
#include "milter-protocol-agent.h"
#include "milter-macros-requests.h"
#include "milter-option.h"
#include "milter-reader.h"
#include "milter-writer.h"
#include "milter-headers.h"
#include "milter-logger.h"
#include "milter-syslog-logger.h"
#include "milter-reply-signals.h"
#include "milter-utils.h"
#include "milter-connection.h"
#include "milter-esmtp.h"
#include "milter-message-result.h"
#include "milter-session-result.h"
#include "milter-memory-profile.h"
#include "milter-event-loop.h"
#include "milter-libev-event-loop.h"
#include "milter-glib-event-loop.h"

/* enumerations from "milter-protocol.h" */
GType
milter_command_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_COMMAND_ABORT, "MILTER_COMMAND_ABORT", "abort" },
      { MILTER_COMMAND_BODY, "MILTER_COMMAND_BODY", "body" },
      { MILTER_COMMAND_CONNECT, "MILTER_COMMAND_CONNECT", "connect" },
      { MILTER_COMMAND_DEFINE_MACRO, "MILTER_COMMAND_DEFINE_MACRO", "define-macro" },
      { MILTER_COMMAND_END_OF_MESSAGE, "MILTER_COMMAND_END_OF_MESSAGE", "end-of-message" },
      { MILTER_COMMAND_HELO, "MILTER_COMMAND_HELO", "helo" },
      { MILTER_COMMAND_QUIT_NEW_CONNECTION, "MILTER_COMMAND_QUIT_NEW_CONNECTION", "quit-new-connection" },
      { MILTER_COMMAND_HEADER, "MILTER_COMMAND_HEADER", "header" },
      { MILTER_COMMAND_ENVELOPE_FROM, "MILTER_COMMAND_ENVELOPE_FROM", "envelope-from" },
      { MILTER_COMMAND_END_OF_HEADER, "MILTER_COMMAND_END_OF_HEADER", "end-of-header" },
      { MILTER_COMMAND_NEGOTIATE, "MILTER_COMMAND_NEGOTIATE", "negotiate" },
      { MILTER_COMMAND_QUIT, "MILTER_COMMAND_QUIT", "quit" },
      { MILTER_COMMAND_ENVELOPE_RECIPIENT, "MILTER_COMMAND_ENVELOPE_RECIPIENT", "envelope-recipient" },
      { MILTER_COMMAND_DATA, "MILTER_COMMAND_DATA", "data" },
      { MILTER_COMMAND_UNKNOWN, "MILTER_COMMAND_UNKNOWN", "unknown" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterCommand", values);
  }
  return etype;
}
GType
milter_socket_family_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_SOCKET_FAMILY_UNKNOWN, "MILTER_SOCKET_FAMILY_UNKNOWN", "unknown" },
      { MILTER_SOCKET_FAMILY_UNIX, "MILTER_SOCKET_FAMILY_UNIX", "unix" },
      { MILTER_SOCKET_FAMILY_INET, "MILTER_SOCKET_FAMILY_INET", "inet" },
      { MILTER_SOCKET_FAMILY_INET6, "MILTER_SOCKET_FAMILY_INET6", "inet6" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterSocketFamily", values);
  }
  return etype;
}
GType
milter_reply_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_REPLY_ADD_RECIPIENT, "MILTER_REPLY_ADD_RECIPIENT", "add-recipient" },
      { MILTER_REPLY_DELETE_RECIPIENT, "MILTER_REPLY_DELETE_RECIPIENT", "delete-recipient" },
      { MILTER_REPLY_ADD_RECIPIENT_WITH_PARAMETERS, "MILTER_REPLY_ADD_RECIPIENT_WITH_PARAMETERS", "add-recipient-with-parameters" },
      { MILTER_REPLY_SHUTDOWN, "MILTER_REPLY_SHUTDOWN", "shutdown" },
      { MILTER_REPLY_ACCEPT, "MILTER_REPLY_ACCEPT", "accept" },
      { MILTER_REPLY_REPLACE_BODY, "MILTER_REPLY_REPLACE_BODY", "replace-body" },
      { MILTER_REPLY_CONTINUE, "MILTER_REPLY_CONTINUE", "continue" },
      { MILTER_REPLY_DISCARD, "MILTER_REPLY_DISCARD", "discard" },
      { MILTER_REPLY_CHANGE_FROM, "MILTER_REPLY_CHANGE_FROM", "change-from" },
      { MILTER_REPLY_CONNECTION_FAILURE, "MILTER_REPLY_CONNECTION_FAILURE", "connection-failure" },
      { MILTER_REPLY_ADD_HEADER, "MILTER_REPLY_ADD_HEADER", "add-header" },
      { MILTER_REPLY_INSERT_HEADER, "MILTER_REPLY_INSERT_HEADER", "insert-header" },
      { MILTER_REPLY_SET_SYMBOL_LIST, "MILTER_REPLY_SET_SYMBOL_LIST", "set-symbol-list" },
      { MILTER_REPLY_CHANGE_HEADER, "MILTER_REPLY_CHANGE_HEADER", "change-header" },
      { MILTER_REPLY_PROGRESS, "MILTER_REPLY_PROGRESS", "progress" },
      { MILTER_REPLY_QUARANTINE, "MILTER_REPLY_QUARANTINE", "quarantine" },
      { MILTER_REPLY_REJECT, "MILTER_REPLY_REJECT", "reject" },
      { MILTER_REPLY_SKIP, "MILTER_REPLY_SKIP", "skip" },
      { MILTER_REPLY_TEMPORARY_FAILURE, "MILTER_REPLY_TEMPORARY_FAILURE", "temporary-failure" },
      { MILTER_REPLY_REPLY_CODE, "MILTER_REPLY_REPLY_CODE", "reply-code" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterReply", values);
  }
  return etype;
}
GType
milter_status_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_STATUS_DEFAULT, "MILTER_STATUS_DEFAULT", "default" },
      { MILTER_STATUS_NOT_CHANGE, "MILTER_STATUS_NOT_CHANGE", "not-change" },
      { MILTER_STATUS_CONTINUE, "MILTER_STATUS_CONTINUE", "continue" },
      { MILTER_STATUS_REJECT, "MILTER_STATUS_REJECT", "reject" },
      { MILTER_STATUS_DISCARD, "MILTER_STATUS_DISCARD", "discard" },
      { MILTER_STATUS_ACCEPT, "MILTER_STATUS_ACCEPT", "accept" },
      { MILTER_STATUS_TEMPORARY_FAILURE, "MILTER_STATUS_TEMPORARY_FAILURE", "temporary-failure" },
      { MILTER_STATUS_NO_REPLY, "MILTER_STATUS_NO_REPLY", "no-reply" },
      { MILTER_STATUS_SKIP, "MILTER_STATUS_SKIP", "skip" },
      { MILTER_STATUS_ALL_OPTIONS, "MILTER_STATUS_ALL_OPTIONS", "all-options" },
      { MILTER_STATUS_PROGRESS, "MILTER_STATUS_PROGRESS", "progress" },
      { MILTER_STATUS_ABORT, "MILTER_STATUS_ABORT", "abort" },
      { MILTER_STATUS_QUARANTINE, "MILTER_STATUS_QUARANTINE", "quarantine" },
      { MILTER_STATUS_STOP, "MILTER_STATUS_STOP", "stop" },
      { MILTER_STATUS_ERROR, "MILTER_STATUS_ERROR", "error" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterStatus", values);
  }
  return etype;
}
GType
milter_macro_stage_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_MACRO_STAGE_CONNECT, "MILTER_MACRO_STAGE_CONNECT", "connect" },
      { MILTER_MACRO_STAGE_HELO, "MILTER_MACRO_STAGE_HELO", "helo" },
      { MILTER_MACRO_STAGE_ENVELOPE_FROM, "MILTER_MACRO_STAGE_ENVELOPE_FROM", "envelope-from" },
      { MILTER_MACRO_STAGE_ENVELOPE_RECIPIENT, "MILTER_MACRO_STAGE_ENVELOPE_RECIPIENT", "envelope-recipient" },
      { MILTER_MACRO_STAGE_DATA, "MILTER_MACRO_STAGE_DATA", "data" },
      { MILTER_MACRO_STAGE_END_OF_MESSAGE, "MILTER_MACRO_STAGE_END_OF_MESSAGE", "end-of-message" },
      { MILTER_MACRO_STAGE_END_OF_HEADER, "MILTER_MACRO_STAGE_END_OF_HEADER", "end-of-header" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterMacroStage", values);
  }
  return etype;
}
GType
milter_decoder_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_DECODER_ERROR_SHORT_COMMAND_LENGTH, "MILTER_DECODER_ERROR_SHORT_COMMAND_LENGTH", "short-command-length" },
      { MILTER_DECODER_ERROR_LONG_COMMAND_LENGTH, "MILTER_DECODER_ERROR_LONG_COMMAND_LENGTH", "long-command-length" },
      { MILTER_DECODER_ERROR_UNEXPECTED_END, "MILTER_DECODER_ERROR_UNEXPECTED_END", "unexpected-end" },
      { MILTER_DECODER_ERROR_UNEXPECTED_COMMAND, "MILTER_DECODER_ERROR_UNEXPECTED_COMMAND", "unexpected-command" },
      { MILTER_DECODER_ERROR_MISSING_NULL, "MILTER_DECODER_ERROR_MISSING_NULL", "missing-null" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterDecoderError", values);
  }
  return etype;
}
GType
milter_decoder_compare_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_DECODER_COMPARE_AT_LEAST, "MILTER_DECODER_COMPARE_AT_LEAST", "at-least" },
      { MILTER_DECODER_COMPARE_EXACT, "MILTER_DECODER_COMPARE_EXACT", "exact" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterDecoderCompareType", values);
  }
  return etype;
}
GType
milter_command_decoder_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_COMMAND_DECODER_ERROR_UNKNOWN_MACRO_CONTEXT, "MILTER_COMMAND_DECODER_ERROR_UNKNOWN_MACRO_CONTEXT", "unknown-macro-context" },
      { MILTER_COMMAND_DECODER_ERROR_INVALID_FORMAT, "MILTER_COMMAND_DECODER_ERROR_INVALID_FORMAT", "invalid-format" },
      { MILTER_COMMAND_DECODER_ERROR_UNKNOWN_SOCKET_FAMILY, "MILTER_COMMAND_DECODER_ERROR_UNKNOWN_SOCKET_FAMILY", "unknown-socket-family" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterCommandDecoderError", values);
  }
  return etype;
}
GType
milter_reply_decoder_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_REPLY_DECODER_ERROR_UNEXPECTED_MACRO_STAGE, "MILTER_REPLY_DECODER_ERROR_UNEXPECTED_MACRO_STAGE", "stage" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterReplyDecoderError", values);
  }
  return etype;
}
GType
milter_agent_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_AGENT_ERROR_IO_ERROR, "MILTER_AGENT_ERROR_IO_ERROR", "io-error" },
      { MILTER_AGENT_ERROR_DECODE_ERROR, "MILTER_AGENT_ERROR_DECODE_ERROR", "decode-error" },
      { MILTER_AGENT_ERROR_NO_EVENT_LOOP_ERROR, "MILTER_AGENT_ERROR_NO_EVENT_LOOP_ERROR", "no-event-loop-error" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterAgentError", values);
  }
  return etype;
}
GType
milter_action_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { MILTER_ACTION_NONE, "MILTER_ACTION_NONE", "none" },
      { MILTER_ACTION_ADD_HEADERS, "MILTER_ACTION_ADD_HEADERS", "add-headers" },
      { MILTER_ACTION_CHANGE_BODY, "MILTER_ACTION_CHANGE_BODY", "change-body" },
      { MILTER_ACTION_ADD_ENVELOPE_RECIPIENT, "MILTER_ACTION_ADD_ENVELOPE_RECIPIENT", "add-envelope-recipient" },
      { MILTER_ACTION_DELETE_ENVELOPE_RECIPIENT, "MILTER_ACTION_DELETE_ENVELOPE_RECIPIENT", "delete-envelope-recipient" },
      { MILTER_ACTION_CHANGE_HEADERS, "MILTER_ACTION_CHANGE_HEADERS", "change-headers" },
      { MILTER_ACTION_QUARANTINE, "MILTER_ACTION_QUARANTINE", "quarantine" },
      { MILTER_ACTION_CHANGE_ENVELOPE_FROM, "MILTER_ACTION_CHANGE_ENVELOPE_FROM", "change-envelope-from" },
      { MILTER_ACTION_ADD_ENVELOPE_RECIPIENT_WITH_PARAMETERS, "MILTER_ACTION_ADD_ENVELOPE_RECIPIENT_WITH_PARAMETERS", "add-envelope-recipient-with-parameters" },
      { MILTER_ACTION_SET_SYMBOL_LIST, "MILTER_ACTION_SET_SYMBOL_LIST", "set-symbol-list" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("MilterActionFlags", values);
  }
  return etype;
}
GType
milter_step_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { MILTER_STEP_NONE, "MILTER_STEP_NONE", "none" },
      { MILTER_STEP_NO_CONNECT, "MILTER_STEP_NO_CONNECT", "no-connect" },
      { MILTER_STEP_NO_HELO, "MILTER_STEP_NO_HELO", "no-helo" },
      { MILTER_STEP_NO_ENVELOPE_FROM, "MILTER_STEP_NO_ENVELOPE_FROM", "no-envelope-from" },
      { MILTER_STEP_NO_ENVELOPE_RECIPIENT, "MILTER_STEP_NO_ENVELOPE_RECIPIENT", "no-envelope-recipient" },
      { MILTER_STEP_NO_BODY, "MILTER_STEP_NO_BODY", "no-body" },
      { MILTER_STEP_NO_HEADERS, "MILTER_STEP_NO_HEADERS", "no-headers" },
      { MILTER_STEP_NO_END_OF_HEADER, "MILTER_STEP_NO_END_OF_HEADER", "no-end-of-header" },
      { MILTER_STEP_NO_REPLY_HEADER, "MILTER_STEP_NO_REPLY_HEADER", "no-reply-header" },
      { MILTER_STEP_NO_UNKNOWN, "MILTER_STEP_NO_UNKNOWN", "no-unknown" },
      { MILTER_STEP_NO_DATA, "MILTER_STEP_NO_DATA", "no-data" },
      { MILTER_STEP_SKIP, "MILTER_STEP_SKIP", "skip" },
      { MILTER_STEP_ENVELOPE_RECIPIENT_REJECTED, "MILTER_STEP_ENVELOPE_RECIPIENT_REJECTED", "envelope-recipient-rejected" },
      { MILTER_STEP_NO_REPLY_CONNECT, "MILTER_STEP_NO_REPLY_CONNECT", "no-reply-connect" },
      { MILTER_STEP_NO_REPLY_HELO, "MILTER_STEP_NO_REPLY_HELO", "no-reply-helo" },
      { MILTER_STEP_NO_REPLY_ENVELOPE_FROM, "MILTER_STEP_NO_REPLY_ENVELOPE_FROM", "no-reply-envelope-from" },
      { MILTER_STEP_NO_REPLY_ENVELOPE_RECIPIENT, "MILTER_STEP_NO_REPLY_ENVELOPE_RECIPIENT", "no-reply-envelope-recipient" },
      { MILTER_STEP_NO_REPLY_DATA, "MILTER_STEP_NO_REPLY_DATA", "no-reply-data" },
      { MILTER_STEP_NO_REPLY_UNKNOWN, "MILTER_STEP_NO_REPLY_UNKNOWN", "no-reply-unknown" },
      { MILTER_STEP_NO_REPLY_END_OF_HEADER, "MILTER_STEP_NO_REPLY_END_OF_HEADER", "no-reply-end-of-header" },
      { MILTER_STEP_NO_REPLY_BODY, "MILTER_STEP_NO_REPLY_BODY", "no-reply-body" },
      { MILTER_STEP_HEADER_VALUE_WITH_LEADING_SPACE, "MILTER_STEP_HEADER_VALUE_WITH_LEADING_SPACE", "header-value-with-leading-space" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("MilterStepFlags", values);
  }
  return etype;
}
GType
milter_reader_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_READER_ERROR_NO_CHANNEL, "MILTER_READER_ERROR_NO_CHANNEL", "no-channel" },
      { MILTER_READER_ERROR_IO_ERROR, "MILTER_READER_ERROR_IO_ERROR", "io-error" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterReaderError", values);
  }
  return etype;
}
GType
milter_writer_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_WRITER_ERROR_NO_CHANNEL, "MILTER_WRITER_ERROR_NO_CHANNEL", "no-channel" },
      { MILTER_WRITER_ERROR_IO_ERROR, "MILTER_WRITER_ERROR_IO_ERROR", "io-error" },
      { MILTER_WRITER_ERROR_NOT_READY, "MILTER_WRITER_ERROR_NOT_READY", "not-ready" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterWriterError", values);
  }
  return etype;
}
GType
milter_log_level_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { MILTER_LOG_LEVEL_DEFAULT, "MILTER_LOG_LEVEL_DEFAULT", "default" },
      { MILTER_LOG_LEVEL_NONE, "MILTER_LOG_LEVEL_NONE", "none" },
      { MILTER_LOG_LEVEL_CRITICAL, "MILTER_LOG_LEVEL_CRITICAL", "critical" },
      { MILTER_LOG_LEVEL_ERROR, "MILTER_LOG_LEVEL_ERROR", "error" },
      { MILTER_LOG_LEVEL_WARNING, "MILTER_LOG_LEVEL_WARNING", "warning" },
      { MILTER_LOG_LEVEL_MESSAGE, "MILTER_LOG_LEVEL_MESSAGE", "message" },
      { MILTER_LOG_LEVEL_INFO, "MILTER_LOG_LEVEL_INFO", "info" },
      { MILTER_LOG_LEVEL_DEBUG, "MILTER_LOG_LEVEL_DEBUG", "debug" },
      { MILTER_LOG_LEVEL_TRACE, "MILTER_LOG_LEVEL_TRACE", "trace" },
      { MILTER_LOG_LEVEL_STATISTICS, "MILTER_LOG_LEVEL_STATISTICS", "statistics" },
      { MILTER_LOG_LEVEL_PROFILE, "MILTER_LOG_LEVEL_PROFILE", "profile" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("MilterLogLevelFlags", values);
  }
  return etype;
}
GType
milter_log_item_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { MILTER_LOG_ITEM_DEFAULT, "MILTER_LOG_ITEM_DEFAULT", "default" },
      { MILTER_LOG_ITEM_NONE, "MILTER_LOG_ITEM_NONE", "none" },
      { MILTER_LOG_ITEM_DOMAIN, "MILTER_LOG_ITEM_DOMAIN", "domain" },
      { MILTER_LOG_ITEM_LEVEL, "MILTER_LOG_ITEM_LEVEL", "level" },
      { MILTER_LOG_ITEM_LOCATION, "MILTER_LOG_ITEM_LOCATION", "location" },
      { MILTER_LOG_ITEM_TIME, "MILTER_LOG_ITEM_TIME", "time" },
      { MILTER_LOG_ITEM_NAME, "MILTER_LOG_ITEM_NAME", "name" },
      { MILTER_LOG_ITEM_PID, "MILTER_LOG_ITEM_PID", "pid" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("MilterLogItemFlags", values);
  }
  return etype;
}
GType
milter_log_colorize_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_LOG_COLORIZE_DEFAULT, "MILTER_LOG_COLORIZE_DEFAULT", "default" },
      { MILTER_LOG_COLORIZE_NONE, "MILTER_LOG_COLORIZE_NONE", "none" },
      { MILTER_LOG_COLORIZE_CONSOLE, "MILTER_LOG_COLORIZE_CONSOLE", "console" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterLogColorize", values);
  }
  return etype;
}
GType
milter_utils_pipe_mode_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_UTILS_READ_PIPE, "MILTER_UTILS_READ_PIPE", "read-pipe" },
      { MILTER_UTILS_WRITE_PIPE, "MILTER_UTILS_WRITE_PIPE", "write-pipe" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterUtilsPipeMode", values);
  }
  return etype;
}
GType
milter_enum_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_ENUM_ERROR_NULL_NAME, "MILTER_ENUM_ERROR_NULL_NAME", "null-name" },
      { MILTER_ENUM_ERROR_UNKNOWN_NAME, "MILTER_ENUM_ERROR_UNKNOWN_NAME", "unknown-name" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterEnumError", values);
  }
  return etype;
}
GType
milter_flags_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_FLAGS_ERROR_NULL_NAME, "MILTER_FLAGS_ERROR_NULL_NAME", "null-name" },
      { MILTER_FLAGS_ERROR_UNKNOWN_NAMES, "MILTER_FLAGS_ERROR_UNKNOWN_NAMES", "unknown-names" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterFlagsError", values);
  }
  return etype;
}
GType
milter_connection_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_CONNECTION_ERROR_INVALID_FORMAT, "MILTER_CONNECTION_ERROR_INVALID_FORMAT", "invalid-format" },
      { MILTER_CONNECTION_ERROR_SOCKET_FAILURE, "MILTER_CONNECTION_ERROR_SOCKET_FAILURE", "socket-failure" },
      { MILTER_CONNECTION_ERROR_SET_SOCKET_OPTION_FAILURE, "MILTER_CONNECTION_ERROR_SET_SOCKET_OPTION_FAILURE", "set-socket-option-failure" },
      { MILTER_CONNECTION_ERROR_ACCEPT_FAILURE, "MILTER_CONNECTION_ERROR_ACCEPT_FAILURE", "accept-failure" },
      { MILTER_CONNECTION_ERROR_BIND_FAILURE, "MILTER_CONNECTION_ERROR_BIND_FAILURE", "bind-failure" },
      { MILTER_CONNECTION_ERROR_LISTEN_FAILURE, "MILTER_CONNECTION_ERROR_LISTEN_FAILURE", "listen-failure" },
      { MILTER_CONNECTION_ERROR_UNIX_SOCKET, "MILTER_CONNECTION_ERROR_UNIX_SOCKET", "unix-socket" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterConnectionError", values);
  }
  return etype;
}
GType
milter_esmtp_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_ESMTP_ERROR_INVALID_FORMAT, "MILTER_ESMTP_ERROR_INVALID_FORMAT", "format" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterEsmtpError", values);
  }
  return etype;
}
GType
milter_state_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_STATE_INVALID, "MILTER_STATE_INVALID", "invalid" },
      { MILTER_STATE_START, "MILTER_STATE_START", "start" },
      { MILTER_STATE_NEGOTIATE, "MILTER_STATE_NEGOTIATE", "negotiate" },
      { MILTER_STATE_NEGOTIATE_REPLIED, "MILTER_STATE_NEGOTIATE_REPLIED", "negotiate-replied" },
      { MILTER_STATE_CONNECT, "MILTER_STATE_CONNECT", "connect" },
      { MILTER_STATE_CONNECT_REPLIED, "MILTER_STATE_CONNECT_REPLIED", "connect-replied" },
      { MILTER_STATE_HELO, "MILTER_STATE_HELO", "helo" },
      { MILTER_STATE_HELO_REPLIED, "MILTER_STATE_HELO_REPLIED", "helo-replied" },
      { MILTER_STATE_ENVELOPE_FROM, "MILTER_STATE_ENVELOPE_FROM", "envelope-from" },
      { MILTER_STATE_ENVELOPE_FROM_REPLIED, "MILTER_STATE_ENVELOPE_FROM_REPLIED", "envelope-from-replied" },
      { MILTER_STATE_ENVELOPE_RECIPIENT, "MILTER_STATE_ENVELOPE_RECIPIENT", "envelope-recipient" },
      { MILTER_STATE_ENVELOPE_RECIPIENT_REPLIED, "MILTER_STATE_ENVELOPE_RECIPIENT_REPLIED", "envelope-recipient-replied" },
      { MILTER_STATE_DATA, "MILTER_STATE_DATA", "data" },
      { MILTER_STATE_DATA_REPLIED, "MILTER_STATE_DATA_REPLIED", "data-replied" },
      { MILTER_STATE_UNKNOWN, "MILTER_STATE_UNKNOWN", "unknown" },
      { MILTER_STATE_UNKNOWN_REPLIED, "MILTER_STATE_UNKNOWN_REPLIED", "unknown-replied" },
      { MILTER_STATE_HEADER, "MILTER_STATE_HEADER", "header" },
      { MILTER_STATE_HEADER_REPLIED, "MILTER_STATE_HEADER_REPLIED", "header-replied" },
      { MILTER_STATE_END_OF_HEADER, "MILTER_STATE_END_OF_HEADER", "end-of-header" },
      { MILTER_STATE_END_OF_HEADER_REPLIED, "MILTER_STATE_END_OF_HEADER_REPLIED", "end-of-header-replied" },
      { MILTER_STATE_BODY, "MILTER_STATE_BODY", "body" },
      { MILTER_STATE_BODY_REPLIED, "MILTER_STATE_BODY_REPLIED", "body-replied" },
      { MILTER_STATE_END_OF_MESSAGE, "MILTER_STATE_END_OF_MESSAGE", "end-of-message" },
      { MILTER_STATE_END_OF_MESSAGE_REPLIED, "MILTER_STATE_END_OF_MESSAGE_REPLIED", "end-of-message-replied" },
      { MILTER_STATE_QUIT, "MILTER_STATE_QUIT", "quit" },
      { MILTER_STATE_QUIT_REPLIED, "MILTER_STATE_QUIT_REPLIED", "quit-replied" },
      { MILTER_STATE_ABORT, "MILTER_STATE_ABORT", "abort" },
      { MILTER_STATE_ABORT_REPLIED, "MILTER_STATE_ABORT_REPLIED", "abort-replied" },
      { MILTER_STATE_FINISHED, "MILTER_STATE_FINISHED", "finished" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterState", values);
  }
  return etype;
}
GType
milter_event_loop_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_EVENT_LOOP_ERROR_MAX, "MILTER_EVENT_LOOP_ERROR_MAX", "max" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterEventLoopError", values);
  }
  return etype;
}



