/****************************************************************************
** Meta object code from reading C++ file 'minner.h'
**
** Created: Fri 28. May 13:11:31 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../minner.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'minner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Minner[] = {

  // content:
  4,       // revision
  0,       // classname
  0,    0, // classinfo
  6,   14, // methods
  0,    0, // properties
  0,    0, // enums/sets
  0,    0, // constructors
  0,       // flags
  0,       // signalCount

  // slots: signature, parameters, type, tag, flags
  8,    7,    7,    7, 0x08,
  18,    7,    7,    7, 0x08,
  33,    7,    7,    7, 0x08,
  49,    7,    7,    7, 0x08,
  65,    7,    7,    7, 0x08,
  75,    7,    7,    7, 0x08,

  0        // eod
};

static const char qt_meta_stringdata_Minner[] = {
  "Minner\0\0newGame()\0setFieldSize()\0"
  "setFieldSize2()\0setFieldSize3()\0"
  "Restart()\0Savebi()\0"
};

const QMetaObject Minner::staticMetaObject = {
  {
    &QMainWindow::staticMetaObject, qt_meta_stringdata_Minner,
    qt_meta_data_Minner, 0
  }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject& Minner::getStaticMetaObject() {
  return staticMetaObject;
}
#endif //Q_NO_DATA_RELOCATION

const QMetaObject* Minner::metaObject() const {
  return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void* Minner::qt_metacast(const char* _clname) {
  if (!_clname) return 0;

  if (!strcmp(_clname, qt_meta_stringdata_Minner))
    return static_cast<void*>(const_cast< Minner*>(this));

  return QMainWindow::qt_metacast(_clname);
}

int Minner::qt_metacall(QMetaObject::Call _c, int _id, void** _a) {
  _id = QMainWindow::qt_metacall(_c, _id, _a);

  if (_id < 0)
    return _id;

  if (_c == QMetaObject::InvokeMetaMethod) {
    switch (_id) {
      case 0:
        newGame();
        break;

      case 1:
        setFieldSize();
        break;

      case 2:
        setFieldSize2();
        break;

      case 3:
        setFieldSize3();
        break;

      case 4:
        Restart();
        break;

      case 5:
        Savebi();
        break;

      default:
        ;
    }

    _id -= 6;
  }

  return _id;
}
QT_END_MOC_NAMESPACE
