/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtPim module of the Qt Toolkit.
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

import QtQuick 2.0
import QtTest 1.0
import QtContacts 5.0

TestCase {
    name: "ContactsOrganizationsTests"

    TestCase {
        name: "ContactsOrganizationsTests::NoOrganization"

        Contact {
            id: contactWithoutOrganization
        }

        Contact {
            id: anotherContactWithoutOrganization
        }

        Contact {
            id: yetAnotherContactWithoutOrganization
        }

        function test_organizationOfContactWithoutOrganizationIsDefined() {
            verifyIsDefined(contactWithoutOrganization.organization);
        }

        function test_organizationOfContactWithoutOrganizationIsEmpty() {
            verifyIsUndefined(contactWithoutOrganization.organization.assistantName);
            compare(contactWithoutOrganization.organization.department.length, 0);
            verifyIsUndefined(contactWithoutOrganization.organization.location);
            compare(contactWithoutOrganization.organization.logoUrl, "");
            verifyIsUndefined(contactWithoutOrganization.organization.name);
            verifyIsUndefined(contactWithoutOrganization.organization.role);
            verifyIsUndefined(contactWithoutOrganization.organization.title);
        }

        function test_organizationsCountOfAnotherContactWithoutOrganizationIsZero() {
            // we do not access the organization property of the contact,
            // so in this case the expected length is 0
            compare(anotherContactWithoutOrganization.organizations.length, 0);
        }

        function test_organizationsCountOfYetAnotherContactWithoutOrganizationIsOne() {
            // we first access the organization property of the contact,
            // so in this case the expected length is 1
            verifyIsDefined(yetAnotherContactWithoutOrganization.organization);
            compare(yetAnotherContactWithoutOrganization.organizations.length, 1);
        }
    }

    TestCase {
        name: "ContactsOrganizationsTests::OneOrganization"

        Contact {
            id: contactWithOneOrganization

            Organization {
                name: "myOrganization"
            }
        }

        function test_accessOrganizationThroughOrganization() {
            compare(contactWithOneOrganization.organization.name, "myOrganization");
        }

        function test_OrganizationCount() {
            compare(contactWithOneOrganization.organizations.length, 1);
        }

        function test_accessOrganizationThroughOrganizations() {
            compare(contactWithOneOrganization.organizations[0].name, "myOrganization");
        }

        function test_accessOrganizationThroughDetails() {
            compare(contactWithOneOrganization.details(
                        ContactDetail.Organization)[0].name, "myOrganization");
        }
    }

    TestCase {
        name: "ContactsOrganizationsTests::MultipleOrganizations"

        Contact {
            id: contactWithOrganizations

            Organization {
                name: "myOrganization1"
            }

            Organization {
                name: "myOrganization2"
            }
        }

        function test_accessOrganizationThroughOrganization() {
            compare(contactWithOrganizations.organization.name, "myOrganization1");
        }

        function test_organizationCount() {
            compare(contactWithOrganizations.organizations.length, 2);
        }

        function test_accessOrganizationThroughOrganizations() {
            compare(contactWithOrganizations.organizations[0].name, "myOrganization1");
            compare(contactWithOrganizations.organizations[1].name, "myOrganization2");
        }

        function test_accessOrganizationThroughDetails() {
            compare(contactWithOrganizations.details(
                        ContactDetail.Organization)[0].name, "myOrganization1");
        }
    }

    TestCase {
        name: "ContactsOrganizationsTests::DynamicallyAdded::MultipleOrganizations"

        Contact {
            id: contact1
        }

        Organization {
            id: organization1
            name: "myOrganization1"
        }

        Organization {
            id: organization2
            name: "myOrganization2"
        }

        function init() {
            contact1.clearDetails();
            contact1.addDetail(organization1);
            contact1.addDetail(organization2);
        }

        function test_accessOrganizationThroughOrganization() {
            compare(contact1.organization.name, "myOrganization1");
        }

        function test_organizationCount() {
            verify(contact1.organizations);
            compare(contact1.organizations.length, 2);
        }

        function test_accessOrganizationThroughOrganizations() {
            compare(contact1.organizations[0].name, "myOrganization1");
            compare(contact1.organizations[1].name, "myOrganization2");
        }

        function test_accessOrganizationThroughDetails() {
            compare(contact1.details(
                        ContactDetail.Organization)[0].name, "myOrganization1");
        }

        function cleanup () {
            contact1.clearDetails();
        }
    }

    function verifyIsUndefined(object) {
        verify(!object, "Object " + object + " is undefined");
    }

    function verifyIsDefined(object) {
        verify(object, "Object " + object + " is defined");
    }
}
