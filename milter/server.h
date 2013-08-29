/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 *  Copyright (C) 2008-2009  Kouhei Sutou <kou@clear-code.com>
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

#ifndef __MILTER_SERVER_H__
#define __MILTER_SERVER_H__

#include <milter/core.h>
#include <milter/server/milter-server-context.h>
#include <milter/server/milter-server-enum-types.h>

/**
 * milter_server_init:
 *
 * Call this function before using any other the milter-server
 * library functions.
 */
void milter_server_init (void);

/**
 * milter_quit:
 *
 * Call this function after the milter-server library use.
 */
void milter_server_quit (void);


#endif /* __MILTER_SERVER_H__ */

/*
vi:nowrap:ai:expandtab:sw=4
*/
