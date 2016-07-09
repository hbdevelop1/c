QT += core
QT -= gui

CONFIG += c++14 -E

TARGET = p1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    ../../../assembla/c/tt_func_call.cpp

HEADERS += \
    ../algo/bt.h
