TEMPLATE = subdirs

QMAKE_CXXFLAGS += -std=c++11

SUBDIRS += \
    core \
    network \
    test \
    test_client \
    server
