
#ifndef ___milter_marshal_MARSHAL_H__
#define ___milter_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* VOID:STRING,POINTER,UINT (./milter-marshalers.list:1) */
extern void _milter_marshal_VOID__STRING_POINTER_UINT (GClosure     *closure,
                                                       GValue       *return_value,
                                                       guint         n_param_values,
                                                       const GValue *param_values,
                                                       gpointer      invocation_hint,
                                                       gpointer      marshal_data);

/* VOID:ENUM,POINTER (./milter-marshalers.list:2) */
extern void _milter_marshal_VOID__ENUM_POINTER (GClosure     *closure,
                                                GValue       *return_value,
                                                guint         n_param_values,
                                                const GValue *param_values,
                                                gpointer      invocation_hint,
                                                gpointer      marshal_data);

/* VOID:ENUM,STRING (./milter-marshalers.list:3) */
extern void _milter_marshal_VOID__ENUM_STRING (GClosure     *closure,
                                               GValue       *return_value,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint,
                                               gpointer      marshal_data);

/* VOID:STRING,STRING (./milter-marshalers.list:4) */
extern void _milter_marshal_VOID__STRING_STRING (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);

/* VOID:STRING,STRING,ENUM (./milter-marshalers.list:5) */
extern void _milter_marshal_VOID__STRING_STRING_ENUM (GClosure     *closure,
                                                      GValue       *return_value,
                                                      guint         n_param_values,
                                                      const GValue *param_values,
                                                      gpointer      invocation_hint,
                                                      gpointer      marshal_data);

/* VOID:STRING,UINT (./milter-marshalers.list:6) */
extern void _milter_marshal_VOID__STRING_UINT (GClosure     *closure,
                                               GValue       *return_value,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint,
                                               gpointer      marshal_data);

/* VOID:STRING,UINT,ENUM (./milter-marshalers.list:7) */
extern void _milter_marshal_VOID__STRING_UINT_ENUM (GClosure     *closure,
                                                    GValue       *return_value,
                                                    guint         n_param_values,
                                                    const GValue *param_values,
                                                    gpointer      invocation_hint,
                                                    gpointer      marshal_data);

/* VOID:STRING,UINT,STRING (./milter-marshalers.list:8) */
extern void _milter_marshal_VOID__STRING_UINT_STRING (GClosure     *closure,
                                                      GValue       *return_value,
                                                      guint         n_param_values,
                                                      const GValue *param_values,
                                                      gpointer      invocation_hint,
                                                      gpointer      marshal_data);

/* VOID:STRING,UINT64 (./milter-marshalers.list:9) */
extern void _milter_marshal_VOID__STRING_UINT64 (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);

/* VOID:STRING,FLAGS,STRING,UINT,STRING,POINTER,STRING (./milter-marshalers.list:10) */
extern void _milter_marshal_VOID__STRING_FLAGS_STRING_UINT_STRING_POINTER_STRING (GClosure     *closure,
                                                                                  GValue       *return_value,
                                                                                  guint         n_param_values,
                                                                                  const GValue *param_values,
                                                                                  gpointer      invocation_hint,
                                                                                  gpointer      marshal_data);

/* VOID:STRING,ENUM (./milter-marshalers.list:11) */
extern void _milter_marshal_VOID__STRING_ENUM (GClosure     *closure,
                                               GValue       *return_value,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint,
                                               gpointer      marshal_data);

/* VOID:STRING,POINTER,UINT,ENUM (./milter-marshalers.list:12) */
extern void _milter_marshal_VOID__STRING_POINTER_UINT_ENUM (GClosure     *closure,
                                                            GValue       *return_value,
                                                            guint         n_param_values,
                                                            const GValue *param_values,
                                                            gpointer      invocation_hint,
                                                            gpointer      marshal_data);

/* VOID:POINTER,UINT (./milter-marshalers.list:13) */
extern void _milter_marshal_VOID__POINTER_UINT (GClosure     *closure,
                                                GValue       *return_value,
                                                guint         n_param_values,
                                                const GValue *param_values,
                                                gpointer      invocation_hint,
                                                gpointer      marshal_data);

/* VOID:UINT,STRING,STRING (./milter-marshalers.list:14) */
extern void _milter_marshal_VOID__UINT_STRING_STRING (GClosure     *closure,
                                                      GValue       *return_value,
                                                      guint         n_param_values,
                                                      const GValue *param_values,
                                                      gpointer      invocation_hint,
                                                      gpointer      marshal_data);

/* VOID:OBJECT,POINTER (./milter-marshalers.list:15) */
extern void _milter_marshal_VOID__OBJECT_POINTER (GClosure     *closure,
                                                  GValue       *return_value,
                                                  guint         n_param_values,
                                                  const GValue *param_values,
                                                  gpointer      invocation_hint,
                                                  gpointer      marshal_data);

/* VOID:OBJECT,OBJECT (./milter-marshalers.list:16) */
extern void _milter_marshal_VOID__OBJECT_OBJECT (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);

/* VOID:OBJECT,OBJECT,ENUM (./milter-marshalers.list:17) */
extern void _milter_marshal_VOID__OBJECT_OBJECT_ENUM (GClosure     *closure,
                                                      GValue       *return_value,
                                                      guint         n_param_values,
                                                      const GValue *param_values,
                                                      gpointer      invocation_hint,
                                                      gpointer      marshal_data);

/* VOID:OBJECT,OBJECT,OBJECT (./milter-marshalers.list:18) */
extern void _milter_marshal_VOID__OBJECT_OBJECT_OBJECT (GClosure     *closure,
                                                        GValue       *return_value,
                                                        guint         n_param_values,
                                                        const GValue *param_values,
                                                        gpointer      invocation_hint,
                                                        gpointer      marshal_data);

/* VOID:ENUM (./milter-marshalers.list:19) */
#define _milter_marshal_VOID__ENUM	g_cclosure_marshal_VOID__ENUM

/* BOOLEAN:VOID (./milter-marshalers.list:20) */
extern void _milter_marshal_BOOLEAN__VOID (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);

/* BOOLEAN:POINTER (./milter-marshalers.list:21) */
extern void _milter_marshal_BOOLEAN__POINTER (GClosure     *closure,
                                              GValue       *return_value,
                                              guint         n_param_values,
                                              const GValue *param_values,
                                              gpointer      invocation_hint,
                                              gpointer      marshal_data);

/* BOOLEAN:STRING (./milter-marshalers.list:22) */
extern void _milter_marshal_BOOLEAN__STRING (GClosure     *closure,
                                             GValue       *return_value,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint,
                                             gpointer      marshal_data);

/* BOOLEAN:STRING,STRING (./milter-marshalers.list:23) */
extern void _milter_marshal_BOOLEAN__STRING_STRING (GClosure     *closure,
                                                    GValue       *return_value,
                                                    guint         n_param_values,
                                                    const GValue *param_values,
                                                    gpointer      invocation_hint,
                                                    gpointer      marshal_data);

/* BOOLEAN:STRING,UINT (./milter-marshalers.list:24) */
extern void _milter_marshal_BOOLEAN__STRING_UINT (GClosure     *closure,
                                                  GValue       *return_value,
                                                  guint         n_param_values,
                                                  const GValue *param_values,
                                                  gpointer      invocation_hint,
                                                  gpointer      marshal_data);

/* BOOLEAN:STRING,UINT64 (./milter-marshalers.list:25) */
extern void _milter_marshal_BOOLEAN__STRING_UINT64 (GClosure     *closure,
                                                    GValue       *return_value,
                                                    guint         n_param_values,
                                                    const GValue *param_values,
                                                    gpointer      invocation_hint,
                                                    gpointer      marshal_data);

/* BOOLEAN:STRING,POINTER,UINT (./milter-marshalers.list:26) */
extern void _milter_marshal_BOOLEAN__STRING_POINTER_UINT (GClosure     *closure,
                                                          GValue       *return_value,
                                                          guint         n_param_values,
                                                          const GValue *param_values,
                                                          gpointer      invocation_hint,
                                                          gpointer      marshal_data);

/* ENUM:STRING,POINTER,UINT (./milter-marshalers.list:27) */
extern void _milter_marshal_ENUM__STRING_POINTER_UINT (GClosure     *closure,
                                                       GValue       *return_value,
                                                       guint         n_param_values,
                                                       const GValue *param_values,
                                                       gpointer      invocation_hint,
                                                       gpointer      marshal_data);

/* ENUM:OBJECT,OBJECT (./milter-marshalers.list:28) */
extern void _milter_marshal_ENUM__OBJECT_OBJECT (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);

/* ENUM:STRING (./milter-marshalers.list:29) */
extern void _milter_marshal_ENUM__STRING (GClosure     *closure,
                                          GValue       *return_value,
                                          guint         n_param_values,
                                          const GValue *param_values,
                                          gpointer      invocation_hint,
                                          gpointer      marshal_data);

/* ENUM:STRING,STRING (./milter-marshalers.list:30) */
extern void _milter_marshal_ENUM__STRING_STRING (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);

/* ENUM:VOID (./milter-marshalers.list:31) */
extern void _milter_marshal_ENUM__VOID (GClosure     *closure,
                                        GValue       *return_value,
                                        guint         n_param_values,
                                        const GValue *param_values,
                                        gpointer      invocation_hint,
                                        gpointer      marshal_data);

/* ENUM:ENUM (./milter-marshalers.list:32) */
extern void _milter_marshal_ENUM__ENUM (GClosure     *closure,
                                        GValue       *return_value,
                                        guint         n_param_values,
                                        const GValue *param_values,
                                        gpointer      invocation_hint,
                                        gpointer      marshal_data);

/* ENUM:STRING,UINT (./milter-marshalers.list:33) */
extern void _milter_marshal_ENUM__STRING_UINT (GClosure     *closure,
                                               GValue       *return_value,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint,
                                               gpointer      marshal_data);

/* ENUM:STRING,UINT64 (./milter-marshalers.list:34) */
extern void _milter_marshal_ENUM__STRING_UINT64 (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);

G_END_DECLS

#endif /* ___milter_marshal_MARSHAL_H__ */

