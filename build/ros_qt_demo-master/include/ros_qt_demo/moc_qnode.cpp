/****************************************************************************
** Meta object code from reading C++ file 'qnode.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ros_qt_demo-master/include/ros_qt_demo/qnode.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnode.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_class1_ros_qt_demo__QNode_t {
    QByteArrayData data[27];
    char stringdata0[316];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_class1_ros_qt_demo__QNode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_class1_ros_qt_demo__QNode_t qt_meta_stringdata_class1_ros_qt_demo__QNode = {
    {
QT_MOC_LITERAL(0, 0, 25), // "class1_ros_qt_demo::QNode"
QT_MOC_LITERAL(1, 26, 14), // "loggingUpdated"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 11), // "rosShutdown"
QT_MOC_LITERAL(4, 54, 11), // "odom_update"
QT_MOC_LITERAL(5, 66, 1), // "x"
QT_MOC_LITERAL(6, 68, 1), // "y"
QT_MOC_LITERAL(7, 70, 1), // "z"
QT_MOC_LITERAL(8, 72, 1), // "w"
QT_MOC_LITERAL(9, 74, 15), // "send_signelpose"
QT_MOC_LITERAL(10, 90, 12), // "speed_update"
QT_MOC_LITERAL(11, 103, 20), // "face_distance_update"
QT_MOC_LITERAL(12, 124, 4), // "data"
QT_MOC_LITERAL(13, 129, 18), // "face_offset_update"
QT_MOC_LITERAL(14, 148, 21), // "object_zuobiao_udpate"
QT_MOC_LITERAL(15, 170, 9), // "zuobiao_x"
QT_MOC_LITERAL(16, 180, 9), // "zuobiao_y"
QT_MOC_LITERAL(17, 190, 9), // "zuobiao_z"
QT_MOC_LITERAL(18, 200, 11), // "std::string"
QT_MOC_LITERAL(19, 212, 10), // "yaw_update"
QT_MOC_LITERAL(20, 223, 3), // "yaw"
QT_MOC_LITERAL(21, 227, 11), // "name_udpate"
QT_MOC_LITERAL(22, 239, 16), // "mult_pose_update"
QT_MOC_LITERAL(23, 256, 34), // "std::map<int,std::vector<doub..."
QT_MOC_LITERAL(24, 291, 5), // "bings"
QT_MOC_LITERAL(25, 297, 12), // "get_aimpoint"
QT_MOC_LITERAL(26, 310, 5) // "index"

    },
    "class1_ros_qt_demo::QNode\0loggingUpdated\0"
    "\0rosShutdown\0odom_update\0x\0y\0z\0w\0"
    "send_signelpose\0speed_update\0"
    "face_distance_update\0data\0face_offset_update\0"
    "object_zuobiao_udpate\0zuobiao_x\0"
    "zuobiao_y\0zuobiao_z\0std::string\0"
    "yaw_update\0yaw\0name_udpate\0mult_pose_update\0"
    "std::map<int,std::vector<double> >\0"
    "bings\0get_aimpoint\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_class1_ros_qt_demo__QNode[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    4,   76,    2, 0x06 /* Public */,
       9,    4,   85,    2, 0x06 /* Public */,
      10,    3,   94,    2, 0x06 /* Public */,
      11,    1,  101,    2, 0x06 /* Public */,
      13,    1,  104,    2, 0x06 /* Public */,
      14,    4,  107,    2, 0x06 /* Public */,
      19,    1,  116,    2, 0x06 /* Public */,
      21,    1,  119,    2, 0x06 /* Public */,
      22,    1,  122,    2, 0x06 /* Public */,
      25,    1,  125,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    5,    6,    7,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 18,   15,   16,   17,   12,
    QMetaType::Void, QMetaType::Float,   20,
    QMetaType::Void, 0x80000000 | 18,   12,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, QMetaType::Int,   26,

       0        // eod
};

void class1_ros_qt_demo::QNode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QNode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loggingUpdated(); break;
        case 1: _t->rosShutdown(); break;
        case 2: _t->odom_update((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 3: _t->send_signelpose((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 4: _t->speed_update((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 5: _t->face_distance_update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->face_offset_update((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->object_zuobiao_udpate((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< std::string(*)>(_a[4]))); break;
        case 8: _t->yaw_update((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: _t->name_udpate((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 10: _t->mult_pose_update((*reinterpret_cast< std::map<int,std::vector<double> >(*)>(_a[1]))); break;
        case 11: _t->get_aimpoint((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::loggingUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::rosShutdown)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QNode::*)(double , double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::odom_update)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QNode::*)(double , double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::send_signelpose)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QNode::*)(double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::speed_update)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QNode::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::face_distance_update)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (QNode::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::face_offset_update)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (QNode::*)(double , double , double , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::object_zuobiao_udpate)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (QNode::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::yaw_update)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (QNode::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::name_udpate)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (QNode::*)(std::map<int,std::vector<double>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::mult_pose_update)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (QNode::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::get_aimpoint)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject class1_ros_qt_demo::QNode::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_class1_ros_qt_demo__QNode.data,
    qt_meta_data_class1_ros_qt_demo__QNode,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *class1_ros_qt_demo::QNode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *class1_ros_qt_demo::QNode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_class1_ros_qt_demo__QNode.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int class1_ros_qt_demo::QNode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void class1_ros_qt_demo::QNode::loggingUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void class1_ros_qt_demo::QNode::rosShutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void class1_ros_qt_demo::QNode::odom_update(double _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void class1_ros_qt_demo::QNode::send_signelpose(double _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void class1_ros_qt_demo::QNode::speed_update(double _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void class1_ros_qt_demo::QNode::face_distance_update(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void class1_ros_qt_demo::QNode::face_offset_update(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void class1_ros_qt_demo::QNode::object_zuobiao_udpate(double _t1, double _t2, double _t3, std::string _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void class1_ros_qt_demo::QNode::yaw_update(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void class1_ros_qt_demo::QNode::name_udpate(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void class1_ros_qt_demo::QNode::mult_pose_update(std::map<int,std::vector<double>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void class1_ros_qt_demo::QNode::get_aimpoint(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
