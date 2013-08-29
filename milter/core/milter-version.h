/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 *  Copyright (C) 2008  Kouhei Sutou <kou@cozmixng.org>
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __MILTER_VERSION_H__
#define __MILTER_VERSION_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define MILTER_TOOLKIT_VERSION G_STRINGIFY(2.0.0)
#define MILTER_TOOLKIT_VERSION_MAJOR 2
#define MILTER_TOOLKIT_VERSION_MINOR 0
#define MILTER_TOOLKIT_VERSION_MICRO 0

#define MILTER_TOOLKIT_CHECK_VERSION(major, minor, micro)       \
    (MILTER_TOOLKIT_MAJOR_VERSION > (major) ||                  \
     (MILTER_TOOLKIT_MAJOR_VERSION == (major) &&                \
      MILTER_TOOLKIT_MINOR_VERSION > (minor)) ||                \
     (MILTER_TOOLKIT_MAJOR_VERSION == (major) &&                \
      MILTER_TOOLKIT_MINOR_VERSION == (minor) &&                \
      MILTER_TOOLKIT_MICRO_VERSION >= (micro)))

G_END_DECLS

#endif /* __MILTER_VERSION_H__ */

/*
vi:ts=4:nowrap:ai:expandtab:sw=4
*/
