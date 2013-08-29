


#ifndef __MILTER_MANAGER_ENUM_TYPES_H__
#define __MILTER_MANAGER_ENUM_TYPES_H__

#include <glib-object.h>

G_BEGIN_DECLS
/* enumerations from "milter-manager-leader.h" */
GType milter_manager_leader_error_get_type (void);
#define MILTER_TYPE_MANAGER_LEADER_ERROR (milter_manager_leader_error_get_type())
GType milter_manager_leader_state_get_type (void);
#define MILTER_TYPE_MANAGER_LEADER_STATE (milter_manager_leader_state_get_type())
GType milter_manager_configuration_error_get_type (void);
#define MILTER_TYPE_MANAGER_CONFIGURATION_ERROR (milter_manager_configuration_error_get_type())
GType milter_manager_child_error_get_type (void);
#define MILTER_TYPE_MANAGER_CHILD_ERROR (milter_manager_child_error_get_type())
GType milter_manager_children_error_get_type (void);
#define MILTER_TYPE_MANAGER_CHILDREN_ERROR (milter_manager_children_error_get_type())
GType milter_manager_egg_error_get_type (void);
#define MILTER_TYPE_MANAGER_EGG_ERROR (milter_manager_egg_error_get_type())
GType milter_manager_control_command_decoder_error_get_type (void);
#define MILTER_TYPE_MANAGER_CONTROL_COMMAND_DECODER_ERROR (milter_manager_control_command_decoder_error_get_type())
GType milter_manager_control_reply_decoder_error_get_type (void);
#define MILTER_TYPE_MANAGER_CONTROL_REPLY_DECODER_ERROR (milter_manager_control_reply_decoder_error_get_type())
GType milter_manager_reply_decoder_error_get_type (void);
#define MILTER_TYPE_MANAGER_REPLY_DECODER_ERROR (milter_manager_reply_decoder_error_get_type())
GType milter_manager_controller_error_get_type (void);
#define MILTER_TYPE_MANAGER_CONTROLLER_ERROR (milter_manager_controller_error_get_type())
GType milter_manager_launch_command_decoder_error_get_type (void);
#define MILTER_TYPE_MANAGER_LAUNCH_COMMAND_DECODER_ERROR (milter_manager_launch_command_decoder_error_get_type())
GType milter_manager_process_launcher_error_get_type (void);
#define MILTER_TYPE_MANAGER_PROCESS_LAUNCHER_ERROR (milter_manager_process_launcher_error_get_type())
G_END_DECLS

#endif /* __MILTER_MANAGER_ENUM_TYPES_H__ */



