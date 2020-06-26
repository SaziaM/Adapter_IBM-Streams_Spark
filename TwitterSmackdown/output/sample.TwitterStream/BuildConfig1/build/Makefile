# NOTE: This makefile is designed to be run from one level up in the directory
# hierarchy compared to where it resides. For instance, if this makefile is
# located at 'output/build/Makefile', then it can be launched as:
# 'make -f build/Makefile' from the 'output' directory.

SHELL=/bin/bash
ifeq ($(CXX),)
  CXX=g++
endif
ifeq ($(CXX_LN),)
  CXX_LN=g++
endif
PKGCONFIG := /opt/ibm/InfoSphere_Streams/4.2.4.0/bin/dst-pe-pkg-config.sh
SPL_BUNDLE_BUILDER := /opt/ibm/InfoSphere_Streams/4.2.4.0/system/impl/bin/spl-bundle-builder
SO_INCLUDE := $(shell $(PKGCONFIG) --cflags dst-spl-pe-install)
SO_LIB := $(shell $(PKGCONFIG) --libs dst-spl-pe-install)
SO_STAND_LIB := $(shell $(PKGCONFIG) --libs dst-spl-pe-install-standalone)
SPL_CXXFLAGS = -Wall -Wno-unused -Wno-sign-compare
SPL_CXXFLAGS += -D_REENTRANT -fPIC -finline-functions -fmessage-length=0
SPL_CXXFLAGS += $(SO_INCLUDE) -O3 -DNDEBUG  -std=gnu++98 
SPL_LDFLAGS = $(SO_LIB)

SPL_TYPES = build/type/BeJwrMSw2SUksSQQADLECDn.o \
            build/type/BeJwrMSo2SUksSQw1NCzJL0nMCSlPTS0pBgBaogg_1.o \
            build/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/TwitterSource.o \
                build/operator/TwitterStatuses.o \
                build/operator/Tweets.o \
                build/operator/TweetsExport.o 
SPL_SO_BINS = bin/TwitterSource.so \
              bin/TwitterStatuses.so \
              bin/Tweets.so \
              bin/TweetsExport.so 

SPL_ADL_FILE = sample.TwitterStream.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/streamsadmin/workspace/TwitterSmackdown/output/sample.TwitterStream')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig1')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone sample.TwitterStream.sab

bin:
	@mkdir -m 775 bin

types: $(SPL_TYPES)

build/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.o: \
	    src/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.h \
	    src/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] enum{server,client}'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.cpp

build/type/BeJwrMSw2SUksSQQADLECDn.o: \
	    src/type/BeJwrMSw2SUksSQQADLECDn.h \
	    src/type/BeJwrMSw2SUksSQQADLECDn.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring data>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSw2SUksSQQADLECDn.cpp

build/type/BeJwrMSo2SUksSQw1NCzJL0nMCSlPTS0pBgBaogg_1.o: \
	    src/type/BeJwrMSo2SUksSQw1NCzJL0nMCSlPTS0pBgBaogg_1.h \
	    src/type/BeJwrMSo2SUksSQw1NCzJL0nMCSlPTS0pBgBaogg_1.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring data,uint64 totalTweets>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSo2SUksSQw1NCzJL0nMCSlPTS0pBgBaogg_1.cpp

build/type:
	-@mkdir -m 775 build/type

operators: $(SPL_OPERATORS)

-include build/operator/TwitterSource.d
build/operator/TwitterSource.o: \
	    src/operator/TwitterSource.h \
	    src/operator/TwitterSource.cpp\
	    build/dep/operator/TwitterSource.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] TwitterSource'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.4.0/toolkits/com.ibm.streamsx.inet/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.2.4.0/toolkits/spl/spl/utility/JavaOp/../../../impl/include -I /opt/ibm/InfoSphere_Streams/4.2.4.0/java/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"sample.TwitterStream.adl\" -c $(SPL_CXXFLAGS) src/operator/TwitterSource.cpp

-include build/operator/TwitterStatuses.d
build/operator/TwitterStatuses.o: \
	    src/operator/TwitterStatuses.h \
	    src/operator/TwitterStatuses.cpp\
	    build/dep/operator/TwitterStatuses.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] TwitterStatuses'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.4.0/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"sample.TwitterStream.adl\" -c $(SPL_CXXFLAGS) src/operator/TwitterStatuses.cpp

-include build/operator/Tweets.d
build/operator/Tweets.o: \
	    src/operator/Tweets.h \
	    src/operator/Tweets.cpp\
	    build/dep/operator/Tweets.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Tweets'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.4.0/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"sample.TwitterStream.adl\" -c $(SPL_CXXFLAGS) src/operator/Tweets.cpp

-include build/operator/TweetsExport.d
build/operator/TweetsExport.o: \
	    src/operator/TweetsExport.h \
	    src/operator/TweetsExport.cpp\
	    build/dep/operator/TweetsExport.dep \
	    src/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] TweetsExport'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.4.0/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.2.4.0/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"sample.TwitterStream.adl\" -c $(SPL_CXXFLAGS) src/operator/TweetsExport.cpp

build/operator:
	-@mkdir -m 775 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOTwitterSource = \
	    build/operator/TwitterSource.o \
	    build/type/BeJwrMSw2SUksSQQADLECDn.o 

bin/TwitterSource.so: \
	$(SOTwitterSource) \
	build/dep/TwitterSource.so \
	build/ldOptions
	@echo ' [LD-so] so TwitterSource'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/TwitterSource.so -fPIC -shared $(SOTwitterSource) -lstreams-stdtk-javaop -L /opt/ibm/InfoSphere_Streams/4.2.4.0/java/jre/lib/amd64/j9vm -Wl,-rpath -Wl,/opt/ibm/InfoSphere_Streams/4.2.4.0/java/jre/lib/amd64/j9vm -lpthread -ldl -lstreams-stdtk-runtime $(SPL_LDFLAGS)

SOTwitterStatuses = \
	    build/operator/TwitterStatuses.o \
	    build/type/BeJwrMSw2SUksSQQADLECDn.o 

bin/TwitterStatuses.so: \
	$(SOTwitterStatuses) \
	build/dep/TwitterStatuses.so \
	build/ldOptions
	@echo ' [LD-so] so TwitterStatuses'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/TwitterStatuses.so -fPIC -shared $(SOTwitterStatuses) $(SPL_LDFLAGS)

SOTweets = \
	    build/operator/Tweets.o \
	    build/type/BeJwrMSw2SUksSQQADLECDn.o \
	    build/type/BeJwrMSo2SUksSQw1NCzJL0nMCSlPTS0pBgBaogg_1.o 

bin/Tweets.so: \
	$(SOTweets) \
	build/dep/Tweets.so \
	build/ldOptions
	@echo ' [LD-so] so Tweets'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Tweets.so -fPIC -shared $(SOTweets) $(SPL_LDFLAGS)

SOTweetsExport = \
	    build/operator/TweetsExport.o \
	    build/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.o \
	    build/type/BeJwrMSo2SUksSQw1NCzJL0nMCSlPTS0pBgBaogg_1.o 

bin/TweetsExport.so: \
	$(SOTweetsExport) \
	build/dep/TweetsExport.so \
	build/ldOptions
	@echo ' [LD-so] so TweetsExport'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/TweetsExport.so -fPIC -shared $(SOTweetsExport) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_system $(SPL_LDFLAGS)

standalone: bin/standalone.exe

build/standalone/standalone.o: \
	    src/standalone/standalone.h \
	    src/standalone/standalone.cpp  \
	    build/cppOptions \
	    | build/standalone
	@echo ' [CXX-standalone] standalone'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/standalone/standalone.cpp

bin/standalone.exe: build/standalone/standalone.o build/ldOptions
	@echo ' [LD-standalone] standalone'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/standalone.exe build/standalone/standalone.o $(SO_STAND_LIB)
	@echo ' [LN-standalone] standalone '
	@ln -sf standalone bin/sample.TwitterStream
build/standalone:
	-@mkdir -m 775 build/standalone

sablink:

	@ln -sf ../sample.TwitterStream.sab bin/sab

bundle: sample.TwitterStream.sab

-include build/dep/sample.TwitterStream.sab.d
sample.TwitterStream.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/sample.TwitterStream.sab.d bin/standalone.exe
	@echo ' [Bundle] sample.TwitterStream.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) sample.TwitterStream.sab

