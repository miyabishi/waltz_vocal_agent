#-------------------------------------------------
#
# Project created by QtCreator 2017-03-24T22:16:05
#
#-------------------------------------------------

QT       -= gui
QT       += multimedia xml

MAKE_WALTZVOCALAGENT_DLL = true

TARGET = WaltzVocalAgent
TEMPLATE = lib

DEFINES += WALTZVOCALAGENT_LIBRARY
equals(MAKE_WALTZVOCALAGENT_DLL, true){
        DEFINES += WALTZVOCALAGENT_LIBRARY
        DEFINES += DEFINE_SHARED_EXPORT
}else{
        CONFIG += staticlib
}
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += src/waltzvocalagent.cpp \
    src/samephonemefragmentsets.cpp \
    src/fragmentdata.cpp \
    src/fragmentlist.cpp \
    src/Domain/ConfigurationParser/vocalinformationparser.cpp \
    src/Domain/ConfigurationParser/voicedictionaryparser.cpp \
    src/Domain/DictionaryComponent/fixedrange.cpp \
    src/Domain/DictionaryComponent/fragment.cpp \
    src/Domain/DictionaryComponent/fragments.cpp \
    src/Domain/DictionaryComponent/syllable.cpp \
    src/Domain/DictionaryComponent/syllables.cpp \
    src/Domain/DictionaryComponent/voicedictionary.cpp \
    src/Domain/VocalInformationComponent/vocalinformation.cpp \
    src/Domain/Wave/waveform.cpp \
    src/Domain/Wave/wavfile.cpp \
    src/Domain/DictionaryComponent/phonemessentence.cpp \
    src/Domain/DictionaryComponent/phonemes.cpp \
    src/Domain/DictionaryComponent/alias.cpp \
    src/Domain/DictionaryComponent/joinedphonemessentence.cpp \
    src/Domain/DictionaryComponent/wavfilepath.cpp \
    src/Domain/DictionaryComponent/milliseconds.cpp \
    src/length.cpp \
    src/Domain/VocalInformationComponent/dictionaryfilepath.cpp \
    src/Domain/VocalInformationComponent/characterdescription.cpp \
    src/Domain/VocalInformationComponent/characterimagefilepath.cpp \
    src/Domain/ConfigurationParser/parser.cpp

HEADERS +=\
        src/Domain/ConfigurationParser/vocalinformationparser.h \
        src/Domain/ConfigurationParser/voicedictionaryparser.h \
        src/Domain/DictionaryComponent/fixedrange.h \
        src/Domain/DictionaryComponent/fragment.h \
        src/Domain/DictionaryComponent/fragments.h \
        src/Domain/DictionaryComponent/syllable.h \
        src/Domain/DictionaryComponent/syllables.h \
        src/Domain/DictionaryComponent/voicedictionary.h \
        src/Domain/VocalInformationComponent/vocalinformation.h \
        src/Domain/Wave/waveform.h \
        src/Domain/Wave/wavfile.h \
        src/Domain/Wave/wavfileheaderstructure.h \
    src/Domain/DictionaryComponent/phonemessentence.h \
    src/Domain/DictionaryComponent/phonemes.h \
    src/Domain/DictionaryComponent/alias.h \
    src/Domain/DictionaryComponent/joinedphonemessentence.h \
    src/Domain/DictionaryComponent/wavfilepath.h \
    src/Domain/DictionaryComponent/milliseconds.h \
    src/fragmentdata.h \
    src/fragmentlist.h \
    src/ialias.h \
    src/iphrase.h \
    src/length.h \
    src/samephonemefragmentsets.h \
    src/waltzvocalagent.h \
    src/waltzvocalagent_global.h \
    include/fragmentdata.h \
    include/fragmentlist.h \
    include/ialias.h \
    include/iphrase.h \
    include/length.h \
    include/samephonemefragmentsets.h \
    include/waltzvocalagent.h \
    src/Domain/VocalInformationComponent/dictionaryfilepath.h \
    src/Domain/VocalInformationComponent/characterdescription.h \
    src/Domain/VocalInformationComponent/characterimagefilepath.h \
    src/Domain/ConfigurationParser/parser.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
