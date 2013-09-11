/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef NSU_EXPORT_H
#define NSU_EXPORT_H

#include <QtCore/qglobal.h>

#if defined(nitroshareutil_EXPORTS)
    #define NSU_EXPORT Q_DECL_EXPORT
#else
    #define NSU_EXPORT Q_DECL_IMPORT
#endif

#endif // NSU_EXPORT_H

