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

#include <qorganizeritemintersectionfilter.h>
#include <private/qorganizeritemintersectionfilter_p.h>

QT_BEGIN_NAMESPACE_ORGANIZER

/*!
    \class QOrganizerItemIntersectionFilter
    \brief The QOrganizerItemIntersectionFilter class provides a filter which intersects the results
           of other filters.
    \inmodule QtOrganizer
    \ingroup organizer-filters

    It may be used to select organizer items which match all of the filters in the intersection filter.
 */

Q_IMPLEMENT_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemIntersectionFilter)

/*!
    \fn QOrganizerItemIntersectionFilter::QOrganizerItemIntersectionFilter(const QOrganizerItemFilter &other)

    Constructs a copy of \a other if possible, otherwise constructs a new intersection filter.
 */

/*!
    Constructs a new intersection filter.
 */
QOrganizerItemIntersectionFilter::QOrganizerItemIntersectionFilter()
    : QOrganizerItemFilter(new QOrganizerItemIntersectionFilterPrivate)
{
}

/*!
    Sets the filters whose criteria will be intersected to \a filters.

    \sa filters(), clear()
 */
void QOrganizerItemIntersectionFilter::setFilters(const QList<QOrganizerItemFilter> &filters)
{
    Q_D(QOrganizerItemIntersectionFilter);
    d->m_filters = filters;
}

/*!
    Clears the list of filters. Note that an empty intersection filter will match no items.

    \sa filters(), setFilters()
 */
void QOrganizerItemIntersectionFilter::clear()
{
    Q_D(QOrganizerItemIntersectionFilter);
    d->m_filters.clear();
}

/*!
    Prepends the given \a filter to the list of intersected filters.

    \sa append(), filters()
 */
void QOrganizerItemIntersectionFilter::prepend(const QOrganizerItemFilter &filter)
{
    Q_D(QOrganizerItemIntersectionFilter);
    d->m_filters.prepend(filter);
}

/*!
    Appends the given \a filter to the list of intersected filters.

    \sa operator<<(), prepend(), filters()
 */
void QOrganizerItemIntersectionFilter::append(const QOrganizerItemFilter &filter)
{
    Q_D(QOrganizerItemIntersectionFilter);
    d->m_filters.append(filter);
}

/*!
    Removes the given \a filter from the intersection list.

    \sa filters(), append(), prepend(), clear()
 */
void QOrganizerItemIntersectionFilter::remove(const QOrganizerItemFilter &filter)
{
    Q_D(QOrganizerItemIntersectionFilter);
    d->m_filters.removeAll(filter);
}

/*!
    Appends the given \a filter to the list of intersected filters.

    \sa append()
 */
QOrganizerItemIntersectionFilter &QOrganizerItemIntersectionFilter::operator<<(const QOrganizerItemFilter &filter)
{
    Q_D(QOrganizerItemIntersectionFilter);
    d->m_filters << filter;
    return *this;
}

/*!
    Returns the list of filters which form the intersection filter.

    \sa setFilters(), prepend(), append(), remove()
 */
QList<QOrganizerItemFilter> QOrganizerItemIntersectionFilter::filters() const
{
    Q_D(const QOrganizerItemIntersectionFilter);
    return d->m_filters;
}

QT_END_NAMESPACE_ORGANIZER
