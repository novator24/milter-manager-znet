


#include "milter-manager-enum-types.h"
#include "milter-manager-leader.h"
#include "milter-manager-configuration.h"
#include "milter-manager-child.h"
#include "milter-manager-children.h"
#include "milter-manager-objects.h"
#include "milter-manager-egg.h"
#include "milter-manager-module.h"
#include "milter-manager-module-impl.h"
#include "milter-manager-control-command-decoder.h"
#include "milter-manager-control-reply-decoder.h"
#include "milter-manager-control-command-encoder.h"
#include "milter-manager-control-reply-encoder.h"
#include "milter-manager-control-protocol.h"
#include "milter-manager-reply-protocol.h"
#include "milter-manager-reply-decoder.h"
#include "milter-manager-reply-encoder.h"
#include "milter-manager-controller-context.h"
#include "milter-manager-controller.h"
#include "milter-manager-launch-protocol.h"
#include "milter-manager-launch-command-encoder.h"
#include "milter-manager-launch-command-decoder.h"
#include "milter-manager-applicable-condition.h"
#include "milter-manager-process-launcher.h"
#include "milter-manager.h"

/* enumerations from "milter-manager-leader.h" */
GType
milter_manager_leader_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_MANAGER_LEADER_ERROR_INVALID_STATE, "MILTER_MANAGER_LEADER_ERROR_INVALID_STATE", "state" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterManagerLeaderError", values);
  }
  return etype;
}
GType
milter_manager_leader_state_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_MANAGER_LEADER_STATE_INVALID, "MILTER_MANAGER_LEADER_STATE_INVALID", "invalid" },
      { MILTER_MANAGER_LEADER_STATE_START, "MILTER_MANAGER_LEADER_STATE_START", "start" },
      { MILTER_MANAGER_LEADER_STATE_NEGOTIATE, "MILTER_MANAGER_LEADER_STATE_NEGOTIATE", "negotiate" },
      { MILTER_MANAGER_LEADER_STATE_NEGOTIATE_REPLIED, "MILTER_MANAGER_LEADER_STATE_NEGOTIATE_REPLIED", "negotiate-replied" },
      { MILTER_MANAGER_LEADER_STATE_CONNECT, "MILTER_MANAGER_LEADER_STATE_CONNECT", "connect" },
      { MILTER_MANAGER_LEADER_STATE_CONNECT_REPLIED, "MILTER_MANAGER_LEADER_STATE_CONNECT_REPLIED", "connect-replied" },
      { MILTER_MANAGER_LEADER_STATE_HELO, "MILTER_MANAGER_LEADER_STATE_HELO", "helo" },
      { MILTER_MANAGER_LEADER_STATE_HELO_REPLIED, "MILTER_MANAGER_LEADER_STATE_HELO_REPLIED", "helo-replied" },
      { MILTER_MANAGER_LEADER_STATE_ENVELOPE_FROM, "MILTER_MANAGER_LEADER_STATE_ENVELOPE_FROM", "envelope-from" },
      { MILTER_MANAGER_LEADER_STATE_ENVELOPE_FROM_REPLIED, "MILTER_MANAGER_LEADER_STATE_ENVELOPE_FROM_REPLIED", "envelope-from-replied" },
      { MILTER_MANAGER_LEADER_STATE_ENVELOPE_RECIPIENT, "MILTER_MANAGER_LEADER_STATE_ENVELOPE_RECIPIENT", "envelope-recipient" },
      { MILTER_MANAGER_LEADER_STATE_ENVELOPE_RECIPIENT_REPLIED, "MILTER_MANAGER_LEADER_STATE_ENVELOPE_RECIPIENT_REPLIED", "envelope-recipient-replied" },
      { MILTER_MANAGER_LEADER_STATE_DATA, "MILTER_MANAGER_LEADER_STATE_DATA", "data" },
      { MILTER_MANAGER_LEADER_STATE_DATA_REPLIED, "MILTER_MANAGER_LEADER_STATE_DATA_REPLIED", "data-replied" },
      { MILTER_MANAGER_LEADER_STATE_UNKNOWN, "MILTER_MANAGER_LEADER_STATE_UNKNOWN", "unknown" },
      { MILTER_MANAGER_LEADER_STATE_UNKNOWN_REPLIED, "MILTER_MANAGER_LEADER_STATE_UNKNOWN_REPLIED", "unknown-replied" },
      { MILTER_MANAGER_LEADER_STATE_HEADER, "MILTER_MANAGER_LEADER_STATE_HEADER", "header" },
      { MILTER_MANAGER_LEADER_STATE_HEADER_REPLIED, "MILTER_MANAGER_LEADER_STATE_HEADER_REPLIED", "header-replied" },
      { MILTER_MANAGER_LEADER_STATE_END_OF_HEADER, "MILTER_MANAGER_LEADER_STATE_END_OF_HEADER", "end-of-header" },
      { MILTER_MANAGER_LEADER_STATE_END_OF_HEADER_REPLIED, "MILTER_MANAGER_LEADER_STATE_END_OF_HEADER_REPLIED", "end-of-header-replied" },
      { MILTER_MANAGER_LEADER_STATE_BODY, "MILTER_MANAGER_LEADER_STATE_BODY", "body" },
      { MILTER_MANAGER_LEADER_STATE_BODY_REPLIED, "MILTER_MANAGER_LEADER_STATE_BODY_REPLIED", "body-replied" },
      { MILTER_MANAGER_LEADER_STATE_END_OF_MESSAGE, "MILTER_MANAGER_LEADER_STATE_END_OF_MESSAGE", "end-of-message" },
      { MILTER_MANAGER_LEADER_STATE_END_OF_MESSAGE_REPLIED, "MILTER_MANAGER_LEADER_STATE_END_OF_MESSAGE_REPLIED", "end-of-message-replied" },
      { MILTER_MANAGER_LEADER_STATE_QUIT, "MILTER_MANAGER_LEADER_STATE_QUIT", "quit" },
      { MILTER_MANAGER_LEADER_STATE_QUIT_REPLIED, "MILTER_MANAGER_LEADER_STATE_QUIT_REPLIED", "quit-replied" },
      { MILTER_MANAGER_LEADER_STATE_ABORT, "MILTER_MANAGER_LEADER_STATE_ABORT", "abort" },
      { MILTER_MANAGER_LEADER_STATE_ABORT_REPLIED, "MILTER_MANAGER_LEADER_STATE_ABORT_REPLIED", "abort-replied" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterManagerLeaderState", values);
  }
  return etype;
}
GType
milter_manager_configuration_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_MANAGER_CONFIGURATION_ERROR_NOT_IMPLEMENTED, "MILTER_MANAGER_CONFIGURATION_ERROR_NOT_IMPLEMENTED", "not-implemented" },
      { MILTER_MANAGER_CONFIGURATION_ERROR_NOT_EXIST, "MILTER_MANAGER_CONFIGURATION_ERROR_NOT_EXIST", "not-exist" },
      { MILTER_MANAGER_CONFIGURATION_ERROR_UNKNOWN, "MILTER_MANAGER_CONFIGURATION_ERROR_UNKNOWN", "unknown" },
      { MILTER_MANAGER_CONFIGURATION_ERROR_SAVE, "MILTER_MANAGER_CONFIGURATION_ERROR_SAVE", "save" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterManagerConfigurationError", values);
  }
  return etype;
}
GType
milter_manager_child_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_MANAGER_CHILD_ERROR_BAD_COMMAND_STRING, "MILTER_MANAGER_CHILD_ERROR_BAD_COMMAND_STRING", "bad-command-string" },
      { MILTER_MANAGER_CHILD_ERROR_START_FAILURE, "MILTER_MANAGER_CHILD_ERROR_START_FAILURE", "start-failure" },
      { MILTER_MANAGER_CHILD_ERROR_INVALID_USER_NAME, "MILTER_MANAGER_CHILD_ERROR_INVALID_USER_NAME", "invalid-user-name" },
      { MILTER_MANAGER_CHILD_ERROR_NO_PRIVILEGE_MODE, "MILTER_MANAGER_CHILD_ERROR_NO_PRIVILEGE_MODE", "no-privilege-mode" },
      { MILTER_MANAGER_CHILD_ERROR_MILTER_TERMINATED_BY_SIGNAL, "MILTER_MANAGER_CHILD_ERROR_MILTER_TERMINATED_BY_SIGNAL", "milter-terminated-by-signal" },
      { MILTER_MANAGER_CHILD_ERROR_MILTER_EXIT, "MILTER_MANAGER_CHILD_ERROR_MILTER_EXIT", "milter-exit" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterManagerChildError", values);
  }
  return etype;
}
GType
milter_manager_children_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_MANAGER_CHILDREN_ERROR_MILTER_EXIT, "MILTER_MANAGER_CHILDREN_ERROR_MILTER_EXIT", "milter-exit" },
      { MILTER_MANAGER_CHILDREN_ERROR_NO_NEGOTIATION, "MILTER_MANAGER_CHILDREN_ERROR_NO_NEGOTIATION", "no-negotiation" },
      { MILTER_MANAGER_CHILDREN_ERROR_NO_DEMAND_COMMAND, "MILTER_MANAGER_CHILDREN_ERROR_NO_DEMAND_COMMAND", "no-demand-command" },
      { MILTER_MANAGER_CHILDREN_ERROR_NO_ALIVE_MILTER, "MILTER_MANAGER_CHILDREN_ERROR_NO_ALIVE_MILTER", "no-alive-milter" },
      { MILTER_MANAGER_CHILDREN_ERROR_NO_MESSAGE_PROCESSING_MILTER, "MILTER_MANAGER_CHILDREN_ERROR_NO_MESSAGE_PROCESSING_MILTER", "no-message-processing-milter" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterManagerChildrenError", values);
  }
  return etype;
}
GType
milter_manager_egg_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_MANAGER_EGG_ERROR_INVALID, "MILTER_MANAGER_EGG_ERROR_INVALID", "invalid" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterManagerEggError", values);
  }
  return etype;
}
GType
milter_manager_control_command_decoder_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_MANAGER_CONTROL_COMMAND_DECODER_ERROR_UNEXPECTED_COMMAND, "MILTER_MANAGER_CONTROL_COMMAND_DECODER_ERROR_UNEXPECTED_COMMAND", "command" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterManagerControlCommandDecoderError", values);
  }
  return etype;
}
GType
milter_manager_control_reply_decoder_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_MANAGER_CONTROL_REPLY_DECODER_ERROR_UNEXPECTED_REPLY, "MILTER_MANAGER_CONTROL_REPLY_DECODER_ERROR_UNEXPECTED_REPLY", "reply" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterManagerControlReplyDecoderError", values);
  }
  return etype;
}
GType
milter_manager_reply_decoder_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_MANAGER_REPLY_DECODER_ERROR_UNEXPECTED_REPLY, "MILTER_MANAGER_REPLY_DECODER_ERROR_UNEXPECTED_REPLY", "reply" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterManagerReplyDecoderError", values);
  }
  return etype;
}
GType
milter_manager_controller_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_MANAGER_CONTROLLER_ERROR_LISTING, "MILTER_MANAGER_CONTROLLER_ERROR_LISTING", "listing" },
      { MILTER_MANAGER_CONTROLLER_ERROR_NO_SPEC, "MILTER_MANAGER_CONTROLLER_ERROR_NO_SPEC", "no-spec" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterManagerControllerError", values);
  }
  return etype;
}
GType
milter_manager_launch_command_decoder_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_MANAGER_LAUNCH_COMMAND_DECODER_ERROR_UNEXPECTED_COMMAND, "MILTER_MANAGER_LAUNCH_COMMAND_DECODER_ERROR_UNEXPECTED_COMMAND", "command" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterManagerLaunchCommandDecoderError", values);
  }
  return etype;
}
GType
milter_manager_process_launcher_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MILTER_MANAGER_PROCESS_LAUNCHER_ERROR_BAD_COMMAND_STRING, "MILTER_MANAGER_PROCESS_LAUNCHER_ERROR_BAD_COMMAND_STRING", "bad-command-string" },
      { MILTER_MANAGER_PROCESS_LAUNCHER_ERROR_START_FAILURE, "MILTER_MANAGER_PROCESS_LAUNCHER_ERROR_START_FAILURE", "start-failure" },
      { MILTER_MANAGER_PROCESS_LAUNCHER_ERROR_INVALID_USER_NAME, "MILTER_MANAGER_PROCESS_LAUNCHER_ERROR_INVALID_USER_NAME", "invalid-user-name" },
      { MILTER_MANAGER_PROCESS_LAUNCHER_ERROR_ALREADY_LAUNCHED, "MILTER_MANAGER_PROCESS_LAUNCHER_ERROR_ALREADY_LAUNCHED", "already-launched" },
      { MILTER_MANAGER_PROCESS_LAUNCHER_ERROR_MILTER_EXIT, "MILTER_MANAGER_PROCESS_LAUNCHER_ERROR_MILTER_EXIT", "milter-exit" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MilterManagerProcessLauncherError", values);
  }
  return etype;
}



