/****************************************************************************
** Meta object code from reading C++ file 'Buttons.h'
**
** Created: Fri 28. May 13:11:37 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Buttons.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Buttons.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Buttons[] = {

  // content:
  4,       // revision
  0,       // classname
  0,    0, // classinfo
  1,   14, // methods
  0,    0, // properties
  0,    0, // enums/sets
  0,    0, // constructors
  0,       // flags
  0,       // signalCount

  // slots: signature, parameters, type, tag, flags
  15,    9,    8,    8, 0x08,

  0        // eod
};

static const char qt_meta_stringdata_Buttons[] = {
  "Buttons\0\0event\0mousePressEvent(QMouseEvent*)\0"
};

const QMetaObject Buttons::staticMetaObject = {
  {
    &QPushButton::staticMetaObject, qt_meta_stringdata_Buttons,
    qt_meta_data_Buttons, 0
  }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject& Buttons::getStaticMetaObject() {
  return staticMetaObject;
}
#endif //Q_NO_DATA_RELOCATION

const QMetaObject* Buttons::metaObject() const {
  return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void* Buttons::qt_metacast(const char* _clname) {
  if (!_clname) return 0;

  if (!strcmp(_clname, qt_meta_stringdata_Buttons))
    return static_cast<void*>(const_cast< Buttons*>(this));

  return QPushButton::qt_metacast(_clname);
}

int Buttons::qt_metacall(QMetaObject::Call _c, int _id, void** _a) {
  _id = QPushButton::qt_metacall(_c, _id, _a);

  if (_id < 0)
    return _id;

  if (_c == QMetaObject::InvokeMetaMethod) {
    switch (_id) {
      case 0:
        mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1])));
        break;

      default:
        ;
    }

    _id -= 1;
  }

  return _id;
}
QT_END_MOC_NAMESPACE
