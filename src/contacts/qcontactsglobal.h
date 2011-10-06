/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Mobility Components.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QTCONTACTSGLOBAL_H
#define QTCONTACTSGLOBAL_H

#include <QtCore/qglobal.h>

#define QTPIM_PREPEND_NAMESPACE(name) ::QtAddOn::Pim::name
#define QTPIM_BEGIN_NAMESPACE namespace QtAddOn { namespace Pim {
#define QTPIM_END_NAMESPACE } }
#define QTPIM_USE_NAMESPACE using namespace QtAddOn::Pim;

#if defined(Q_OS_WIN)
#  if defined(QT_NODLL)
#    undef QT_MAKEDLL
#    undef QT_DLL
#  elif defined(QT_MAKEDLL)
#    if defined(QT_DLL)
#      undef QT_DLL
#    endif
#    if defined(QT_BUILD_CONTACTS_LIB)
#      define Q_CONTACTS_EXPORT Q_DECL_EXPORT
#    else
#      define Q_CONTACTS_EXPORT Q_DECL_IMPORT
#    endif
#  elif defined(QT_DLL)
#    define Q_CONTACTS_EXPORT Q_DECL_IMPORT
#  endif
#endif

#if !defined(Q_CONTACTS_EXPORT)
#  if defined(QT_SHARED)
#    define Q_CONTACTS_EXPORT Q_DECL_EXPORT
#  else
#    define Q_CONTACTS_EXPORT
#  endif
#endif

#define QTCONTACTS_VERSION_NAME "com.nokia.qt.pim.contacts.api.version"
#define QTCONTACTS_IMPLEMENTATION_VERSION_NAME "com.nokia.qt.pim.contacts.implementation.version"
#define QTCONTACTS_VERSION 1

// Not needed since this is a typedef, and qglobal already does this for the base type
// Q_DECLARE_TYPEINFO(QTPIM_PREPEND_NAMESPACE(QContactLocalId), Q_PRIMITIVE_TYPE);

#endif
