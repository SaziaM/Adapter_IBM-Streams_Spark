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

SPL_TYPES = build/type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTPTSxJzkgtBgCYfQra.o \
            build/type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA.o \
            build/type/BeJwrMSo2SUksSQw1NCzJL0nMCSlPTS0pBgBaogg_1.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/Matches.o \
                build/operator/MatchAggregate.o \
                build/operator/AggConsole.o 
SPL_SO_BINS = bin/Matches.so \
              bin/MatchAggregate.so \
              bin/AggConsole.so 

SPL_ADL_FILE = sample.Smackdown.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/streamsadmin/workspace/TwitterSmackdown/output/sample.Smackdown')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone sample.Smackdown.sab

bin:
	@mkdir -m 775 bin

types: $(SPL_TYPES)

build/type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTPTSxJzkgtBgCYfQra.o: \
	    src/type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTPTSxJzkgtBgCYfQra.h \
	    src/type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTPTSxJzkgtBgCYfQra.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring smackdownWords,int32 matches>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTPTSxJzkgtBgCYfQra.cpp

build/type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA.o: \
	    src/type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA.h \
	    src/type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring smackdownWords,int32 match>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA.cpp

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

-include build/operator/Matches.d
build/operator/Matches.o: \
	    src/operator/Matches.h \
	    src/operator/Matches.cpp\
	    build/dep/operator/Matches.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Matches'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.4.0/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"sample.Smackdown.adl\" -c $(SPL_CXXFLAGS) src/operator/Matches.cpp

-include build/operator/MatchAggregate.d
build/operator/MatchAggregate.o: \
	    src/operator/MatchAggregate.h \
	    src/operator/MatchAggregate.cpp\
	    build/dep/operator/MatchAggregate.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] MatchAggregate'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.4.0/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.2.4.0/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"sample.Smackdown.adl\" -c $(SPL_CXXFLAGS) src/operator/MatchAggregate.cpp

-include build/operator/AggConsole.d
build/operator/AggConsole.o: \
	    src/operator/AggConsole.h \
	    src/operator/AggConsole.cpp\
	    build/dep/operator/AggConsole.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] AggConsole'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.4.0/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"sample.Smackdown.adl\" -c $(SPL_CXXFLAGS) src/operator/AggConsole.cpp

build/operator:
	-@mkdir -m 775 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOMatches = \
	    build/operator/Matches.o \
	    build/type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA.o \
	    build/type/BeJwrMSo2SUksSQw1NCzJL0nMCSlPTS0pBgBaogg_1.o 

bin/Matches.so: \
	$(SOMatches) \
	build/dep/Matches.so \
	build/ldOptions
	@echo ' [LD-so] so Matches'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Matches.so -fPIC -shared $(SOMatches) $(SPL_LDFLAGS)

SOMatchAggregate = \
	    build/operator/MatchAggregate.o \
	    build/type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTPTSxJzkgtBgCYfQra.o \
	    build/type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA.o 

bin/MatchAggregate.so: \
	$(SOMatchAggregate) \
	build/dep/MatchAggregate.so \
	build/ldOptions
	@echo ' [LD-so] so MatchAggregate'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/MatchAggregate.so -fPIC -shared $(SOMatchAggregate) -lstreams-stdtk-runtime $(SPL_LDFLAGS)

SOAggConsole = \
	    build/operator/AggConsole.o \
	    build/type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTPTSxJzkgtBgCYfQra.o 

bin/AggConsole.so: \
	$(SOAggConsole) \
	build/dep/AggConsole.so \
	build/ldOptions
	@echo ' [LD-so] so AggConsole'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/AggConsole.so -fPIC -shared $(SOAggConsole) $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/sample.Smackdown
build/standalone:
	-@mkdir -m 775 build/standalone

sablink:

	@ln -sf ../sample.Smackdown.sab bin/sab

bundle: sample.Smackdown.sab

-include build/dep/sample.Smackdown.sab.d
sample.Smackdown.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/sample.Smackdown.sab.d bin/standalone.exe
	@echo ' [Bundle] sample.Smackdown.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) sample.Smackdown.sab

