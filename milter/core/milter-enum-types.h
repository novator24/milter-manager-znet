


#ifndef __MILTER_ENUM_TYPES_H__
#define __MILTER_ENUM_TYPES_H__

#include <glib-object.h>

G_BEGIN_DECLS
/* enumerations from "milter-protocol.h" */
GType milter_command_get_type (void);
#define MILTER_TYPE_COMMAND (milter_command_get_type())
GType milter_socket_family_get_type (void);
#define MILTER_TYPE_SOCKET_FAMILY (milter_socket_family_get_type())
GType milter_reply_get_type (void);
#define MILTER_TYPE_REPLY (milter_reply_get_type())
GType milter_status_get_type (void);
#define MILTER_TYPE_STATUS (milter_status_get_type())
GType milter_macro_stage_get_type (void);
#define MILTER_TYPE_MACRO_STAGE (milter_macro_stage_get_type())
GType milter_decoder_error_get_type (void);
#define MILTER_TYPE_DECODER_ERROR (milter_decoder_error_get_type())
GType milter_decoder_compare_type_get_type (void);
#define MILTER_TYPE_DECODER_COMPARE_TYPE (milter_decoder_compare_type_get_type())
GType milter_command_decoder_error_get_type (void);
#define MILTER_TYPE_COMMAND_DECODER_ERROR (milter_command_decoder_error_get_type())
GType milter_reply_decoder_error_get_type (void);
#define MILTER_TYPE_REPLY_DECODER_ERROR (milter_reply_decoder_error_get_type())
GType milter_agent_error_get_type (void);
#define MILTER_TYPE_AGENT_ERROR (milter_agent_error_get_type())
GType milter_action_flags_get_type (void);
#define MILTER_TYPE_ACTION_FLAGS (milter_action_flags_get_type())
GType milter_step_flags_get_type (void);
#define MILTER_TYPE_STEP_FLAGS (milter_step_flags_get_type())
GType milter_reader_error_get_type (void);
#define MILTER_TYPE_READER_ERROR (milter_reader_error_get_type())
GType milter_writer_error_get_type (void);
#define MILTER_TYPE_WRITER_ERROR (milter_writer_error_get_type())
GType milter_log_level_flags_get_type (void);
#define MILTER_TYPE_LOG_LEVEL_FLAGS (milter_log_level_flags_get_type())
GType milter_log_item_flags_get_type (void);
#define MILTER_TYPE_LOG_ITEM_FLAGS (milter_log_item_flags_get_type())
GType milter_log_colorize_get_type (void);
#define MILTER_TYPE_LOG_COLORIZE (milter_log_colorize_get_type())
GType milter_utils_pipe_mode_get_type (void);
#define MILTER_TYPE_UTILS_PIPE_MODE (milter_utils_pipe_mode_get_type())
GType milter_enum_error_get_type (void);
#define MILTER_TYPE_ENUM_ERROR (milter_enum_error_get_type())
GType milter_flags_error_get_type (void);
#define MILTER_TYPE_FLAGS_ERROR (milter_flags_error_get_type())
GType milter_connection_error_get_type (void);
#define MILTER_TYPE_CONNECTION_ERROR (milter_connection_error_get_type())
GType milter_esmtp_error_get_type (void);
#define MILTER_TYPE_ESMTP_ERROR (milter_esmtp_error_get_type())
GType milter_state_get_type (void);
#define MILTER_TYPE_STATE (milter_state_get_type())
GType milter_event_loop_error_get_type (void);
#define MILTER_TYPE_EVENT_LOOP_ERROR (milter_event_loop_error_get_type())
G_END_DECLS

#endif /* __MILTER_ENUM_TYPES_H__ */



