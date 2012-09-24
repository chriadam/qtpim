/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtOrganizer module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QORGANIZERITEMUNIONFILTER_H
#define QORGANIZERITEMUNIONFILTER_H

#include <qorganizeritemfilter.h>
#include <QtCore/qlist.h>

QTORGANIZER_BEGIN_NAMESPACE

class QOrganizerItemUnionFilterPrivate;

/* Leaf class */

class Q_ORGANIZER_EXPORT QOrganizerItemUnionFilter : public QOrganizerItemFilter
{
public:

    QOrganizerItemUnionFilter();
    QOrganizerItemUnionFilter(const QOrganizerItemFilter &other);

    void setFilters(const QList<QOrganizerItemFilter> &filters);
    void prepend(const QOrganizerItemFilter &filter);
    void append(const QOrganizerItemFilter &filter);
    void remove(const QOrganizerItemFilter &filter);
    void clear();

    QOrganizerItemUnionFilter &operator<<(const QOrganizerItemFilter &filter);

    QList<QOrganizerItemFilter> filters() const;

private:
    Q_DECLARE_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemUnionFilter)
};

QTORGANIZER_END_NAMESPACE

#endif // QORGANIZERITEMUNIONFILTER_H
