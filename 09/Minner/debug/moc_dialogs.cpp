/****************************************************************************
** Meta object code from reading C++ file 'dialogs.h'
**
** Created: Fri 28. May 06:23:08 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialogs.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialogs[] = {

  // content:
  4,       // revision
  0,       // classname
  0,    0, // classinfo
  3,   14, // methods
  0,    0, // properties
  0,    0, // enums/sets
  0,    0, // constructors
  0,       // flags
  1,       // signalCount

  // signals: signature, parameters, type, tag, flags
  9,    8,    8,    8, 0x05,

  // slots: signature, parameters, type, tag, flags
  17,    8,    8,    8, 0x08,
  29,    8,    8,    8, 0x08,

  0        // eod
};

static const char qt_meta_stringdata_Dialogs[] = {
  "Dialogs\0\0exits()\0ok_presed()\0"
  "cancel_presed()\0"
};

const QMetaObject Dialogs::staticMetaObject = {
  {
    &QDialog::staticMetaObject, qt_meta_stringdata_Dialogs,
    qt_meta_data_Dialogs, 0
  }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject& Dialogs::getStaticMetaObject() {
  return staticMetaObject;
}
#endif //Q_NO_DATA_RELOCATION

const QMetaObject* Dialogs::metaObject() const {
  return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void* Dialogs::qt_metacast(const char* _clname) {
  if (!_clname) return 0;

  if (!strcmp(_clname, qt_meta_stringdata_Dialogs))
    return static_cast<void*>(const_cast< Dialogs*>(this));

  return QDialog::qt_metacast(_clname);
}

int Dialogs::qt_metacall(QMetaObject::Call _c, int _id, void** _a) {
  _id = QDialog::qt_metacall(_c, _id, _a);

  if (_id < 0)
    return _id;

  if (_c == QMetaObject::InvokeMetaMethod) {
    switch (_id) {
      case 0:
        exits();
        break;

      case 1:
        ok_presed();
        break;

      case 2:
        cancel_presed();
        break;

      default:
        ;
    }

    _id -= 3;
  }

  return _id;
}

// SIGNAL 0
void Dialogs::exits() {
  QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
