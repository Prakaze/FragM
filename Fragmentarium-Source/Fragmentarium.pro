######################################################################
# Automatically generated by qmake (2.01a) ti 17. maj 23:39:14 2011
######################################################################
# Modifications by 3Dickulus                 Digilantism 2020/03/20
######################################################################

FRAGM_MAJOR_VERSION=2
FRAGM_MINOR_VERSION=5
FRAGM_REVISION=3
FRAGM_VERSION=$$FRAGM_MAJOR_VERSION"."$$FRAGM_MINOR_VERSION"."$$FRAGM_REVISION

PACKAGE_BUILD=meta

CONFIG += c++11
CONFIG += warn_off

win32 {
CONFIG += console
PACKAGE_BUILD=200321
}
else {
PACKAGE_BUILD=$$system("date -u +%y%m%d")
}

TEMPLATE = app

TARGET = "Fragmentarium-"$$FRAGM_VERSION"-"$$PACKAGE_BUILD

DEFINES += FRAGM_MAJOR_VERSION=$$FRAGM_MAJOR_VERSION \
           FRAGM_MINOR_VERSION=$$FRAGM_MINOR_VERSION \
           FRAGM_REVISION=$$FRAGM_REVISION \
           FRAGM_VERSION=$$FRAGM_VERSION \
           PACKAGE_BUILD=$$PACKAGE_BUILD \
           USE_OPENGL_4=ON \
           USE_OPEN_EXR=ON

CONFIG += lrelease

QT += gui widgets opengl openglextensions script scripttools xml

TRANSLATIONS += $$PWD/Translations/Fragmentarium_en.ts \
               $$PWD/Translations/Fragmentarium_de.ts \
               $$PWD/Translations/Fragmentarium_nl.ts \
               $$PWD/Translations/Fragmentarium_ru.ts

translations.path = $$PWD"/"
target.path = $$PWD"/"

DEPENDPATH += $$PWD/ \
              $$PWD/Fragmentarium \
              $$PWD/ThirdPartyCode \
              $$PWD/Fragmentarium/GUI \
              $$PWD/Fragmentarium/Parser \
              $$PWD/SyntopiaCore/Exceptions \
              $$PWD/SyntopiaCore/Logging \
              $$PWD/SyntopiaCore/Misc

INCLUDEPATH+= $$PWD/ \
              $$PWD/Fragmentarium \
              $$PWD/ThirdPartyCode \
              $$PWD/Fragmentarium/GUI \
              $$PWD/Fragmentarium/Parser \
              $$PWD/SyntopiaCore/Exceptions \
              $$PWD/SyntopiaCore/Logging \
              $$PWD/SyntopiaCore/Misc

HEADERS += $$PWD/Fragmentarium/GUI/CameraControl.h \
           $$PWD/ThirdPartyCode/asmbrowser.h \
           $$PWD/Fragmentarium/GUI/DisplayWidget.h \
           $$PWD/ThirdPartyCode/Highlighter.h \
           $$PWD/Fragmentarium/GUI/TextEdit.h \
           $$PWD/Fragmentarium/GUI/MainWindow.h \
           $$PWD/Fragmentarium/GUI/VariableEditor.h \
           $$PWD/Fragmentarium/GUI/VariableWidget.h \
           $$PWD/ThirdPartyCode/qrangeslider.h \
           $$PWD/ThirdPartyCode/qdoublerangeslider.h \
           $$PWD/ThirdPartyCode/EasingAnimation.h \
           $$PWD/ThirdPartyCode/EasingWindow.h \
           $$PWD/Fragmentarium/Parser/Preprocessor.h \
           $$PWD/SyntopiaCore/Exceptions/Exception.h \
           $$PWD/SyntopiaCore/Logging/ListWidgetLogger.h \
           $$PWD/SyntopiaCore/Logging/Logging.h \
           $$PWD/SyntopiaCore/Misc/MiniParser.h \
           $$PWD/SyntopiaCore/Misc/Misc.h \
           $$PWD/SyntopiaCore/Misc/Version.h \
           $$PWD/Fragmentarium/GUI/PreferencesDialog.h \
           $$PWD/Fragmentarium/GUI/OutputDialog.h \
           $$PWD/Fragmentarium/GUI/FileManager.h \
           $$PWD/ThirdPartyCode/hdrloader.h \
           $$PWD/ThirdPartyCode/QtSpline.h \
           $$PWD/ThirdPartyCode/Timeline.h \
           $$PWD/ThirdPartyCode/VideoDialog.h

SOURCES += $$PWD/Fragmentarium/Main.cpp \
           $$PWD/Fragmentarium/GUI/CameraControl.cpp \
           $$PWD/ThirdPartyCode/asmbrowser.cpp \
           $$PWD/Fragmentarium/GUI/DisplayWidget.cpp \
           $$PWD/Fragmentarium/GUI/TextEdit.cpp \
           $$PWD/Fragmentarium/GUI/MainWindow.cpp \
           $$PWD/Fragmentarium/GUI/VariableEditor.cpp \
           $$PWD/Fragmentarium/GUI/VariableWidget.cpp \
           $$PWD/ThirdPartyCode/EasingWindow.cpp \
           $$PWD/ThirdPartyCode/qrangeslider.cpp \
           $$PWD/ThirdPartyCode/qdoublerangeslider.cpp \
           $$PWD/Fragmentarium/Parser/Preprocessor.cpp \
           $$PWD/SyntopiaCore/Logging/ListWidgetLogger.cpp \
           $$PWD/SyntopiaCore/Logging/Logging.cpp \
           $$PWD/SyntopiaCore/Misc/MiniParser.cpp \
           $$PWD/SyntopiaCore/Misc/Misc.cpp \
           $$PWD/SyntopiaCore/Misc/Version.cpp \
           $$PWD/Fragmentarium/GUI/OutputDialog.cpp \
           $$PWD/Fragmentarium/GUI/FileManager.cpp \
           $$PWD/ThirdPartyCode/hdrloader.cpp \
           $$PWD/ThirdPartyCode/QtSpline.cpp \
           $$PWD/ThirdPartyCode/Timeline.cpp \
           $$PWD/ThirdPartyCode/VideoDialog.cpp

FORMS += $$PWD/ThirdPartyCode/EasingDialog.ui \
         $$PWD/Fragmentarium/GUI/OutputDialog.ui \
         $$PWD/Fragmentarium/GUI/PreferencesDialog.ui \
         $$PWD/ThirdPartyCode/TimeLineDialog.ui \
         $$PWD/ThirdPartyCode/VideoDialog.ui

RESOURCES += $$PWD/./Fragmentarium.qrc

OTHER_FILES += \
    $$PWD/Notes.txt \
    $$PWD/Changelog.txt \
    $$PWD/3Dickulus.changes \
    $$PWD/3Dickulus-HOW-TO.txt \
    $$PWD/EULA_ru.txt \
    $$PWD/EULA_de.txt \
    $$PWD/EULA_nl.txt \
    $$PWD/EULA.txt

LIBS += -fPIC

win32:CONFIG(release, debug|release) {
LIBS += -mthreads -lmingwthrd -lwinpthread
LIBS += -L$$PWD/../OpenEXR/lib/ -lIlmImf-2_4 -lHalf-2_4 -lIex-2_4 -lIexMath-2_4 -lImath-2_4 -lIlmThread-2_4
}
else:unix:CONFIG(release, debug|release) {
LIBS += -lz -lpthread
LIBS += -lIlmImf -lHalf -lIex -lIexMath -lImath -lIlmThread
}

win32:CONFIG(release, debug|release) {
LIBS += -LC:/Qt/Tools/mingw492_32/i686-w64-mingw32/lib -lz
INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$PWD/../OpenEXR/include/OpenEXR
INCLUDEPATH += $$PWD/../OpenEXR/include
DEPENDPATH += $$PWD/../OpenEXR/lib
DEPENDPATH += $$PWD/../OpenEXR
PRE_TARGETDEPS += $$PWD/../OpenEXR/lib/libIlmImf-2_4.a $$PWD/../OpenEXR/lib/libHalf-2_4.a $$PWD/../OpenEXR/lib/libIex-2_4.a  $$PWD/../OpenEXR/lib/libIexMath-2_4.a $$PWD/../OpenEXR/lib/libIlmThread-2_4.a $$PWD/../OpenEXR/lib/libImath-2_4.a
}
else:unix:CONFIG(release, debug|release) {
INCLUDEPATH += /usr/include/OpenEXR \
               /usr/include/glm
}

macx:CONFIG(release, debug|release) {
    ICON = $$PWD/./Icons/fileicons/Fragmentarium.icns
    RC_ICONS = $$PWD/./Icons/fileicons/Fragmentarium.icns
    MediaFiles.files = Examples
    MediaFiles.files += fqScript
    MediaFiles.files += Misc
    MediaFiles.path = Contents/MacOS
    QMAKE_BUNDLE_DATA += MediaFiles
}

target.files += Examples
target.files += fqScript
target.files += Misc
win32:CONFIG(release, debug|release) {
    target.files += ../OpenEXR/bin
}

target.files += $$OTHER_FILES

translations.files = $$PWD/Translations/Fragmentarium_en.qm \
                    $$PWD/Translations/Fragmentarium_de.qm \
                    $$PWD/Translations/Fragmentarium_nl.qm \
                    $$PWD/Translations/Fragmentarium_ru.qm
            
translations.command = lrelease

win32:CONFIG(release, debug|release) {
    target.path = $$PWD"/../Fragmentarium-"$$FRAGM_VERSION"-"$$PACKAGE_BUILD"-winex/"
    target.files += $$PWD"/build/release/Fragmentarium-"$$FRAGM_VERSION"-"$$PACKAGE_BUILD".exe"

    translations.path = $$PWD"/../Fragmentarium-"$$FRAGM_VERSION"-"$$PACKAGE_BUILD"-winex/Languages/"
} 

unix:CONFIG(release, debug|release) {
    target.path = $$PWD"/../Fragmentarium-"$$FRAGM_VERSION"-"$$PACKAGE_BUILD"/"
    target.files += $$PWD"/build/release/Fragmentarium-"$$FRAGM_VERSION"-"$$PACKAGE_BUILD

    translations.path = $$PWD"/../Fragmentarium-"$$FRAGM_VERSION"-"$$PACKAGE_BUILD"/Languages/"
} 

    INSTALLS += translations
    INSTALLS += target
