TEMPLATE=app
TARGET=tst_qmlcontacts
SOURCES += tst_qmlcontacts.cpp
OTHER_FILES += \
    testcases/ContactsJsonDbPartition.qml \
    testcases/ContactsJsonDbPartitions.qml \
    testcases/ContactsJsonDbPartitionTestHelper.qml \
    testcases/ContactsJsonDbTestHelper.qml \
    testcases/ContactsSavingTestCase.qml \
    testcases/ContactsSignalingTestCase.qml \
    testcases/ContactsTestHelper.qml \
    testcases/initialize_jsondb_for_tests.qml \
    testcases/SignalingJsonDb.qml \
    testcases/tst_contact_add_detail.qml \
    testcases/tst_contact_addresses.qml \
    testcases/tst_contact_detail_access.qml \
    testcases/tst_contactdetail.qml \
    testcases/tst_contact_emails.qml \
    testcases/tst_contact_extendeddetails.qml \
    testcases/tst_contactmodel_signals.qml \
    testcases/tst_contact_modification.qml \
    testcases/tst_contact_organizations.qml \
    testcases/tst_contact_phonenumbers.qml \
    testcases/tst_contactrelationship.qml \
    testcases/tst_contact_remove_detail.qml \
    testcases/tst_contacts_clear_details_e2e.qml \
    testcases/tst_contacts_details_saving_e2e.qml \
    testcases/tst_contacts_e2e.qml \
    testcases/tst_contacts_export_import_e2e.qml \
    testcases/tst_contacts_export_import_signaling_e2e.qml \
    testcases/tst_contacts_extended_detail_e2e.qml \
    testcases/tst_contacts_fetch_contacts_e2e.qml \
    testcases/tst_contacts_filtering_by_detail_e2e.qml \
    testcases/tst_contacts_filtering_e2e.qml \
    testcases/tst_contact_signals.qml \
    testcases/tst_contacts_intersection_filter_e2e.qml \
    testcases/tst_contacts_jsondb_partitions_e2e.qml \
    testcases/tst_contacts_jsondb_to_model_notification_e2e.qml \
    testcases/tst_contacts_model_to_model_notification_e2e.qml \
    testcases/tst_contacts_remove_contacts_e2e.qml \
    testcases/tst_contacts_remove_detail_e2e.qml \
    testcases/tst_contacts_save_contact_e2e.qml \
    testcases/tst_contacts_sorting_e2e.qml \
    testcases/tst_contact_urls.qml
QT += qmltest contacts versit
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
