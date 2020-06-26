// eJzFVF1vmzAU1f0nFdpDskl8JDRteEuTddWUbWlJf4CBu8Qt2MjcNOXf1yEmEsyp8jbxxOEcfI6vj1NZuDwp3IoUsqJ6d7lAcrdEZRQ9rNerH0hx8wkC8PUTgOO6HtUlenf4c69_0xftR_1PxaxY_0Ps8Xy_03wh3K1z4IWQc_1riQ7xaRpHSv_0diAw0WWLCRBRtbsNCCXVuwiQW7sWC3Fmxq82yCJFLmyIQBTZK_1uWQ0CQ1oonBB45GB_0knAo6IEIQX6MIU0Z1X1mxUIvZ3pbt7ASc_1Oyj2M6jinJ2QZKmcIM9KyZEd4rxCPiyx5opiqYdRfZ9C83_09ESlyKKoqeiWvndRRtkNY68yunBVeYklT14AJXznB49e2qS_1R4UeZezhPPHuSFadt93_1_1FqCzJy_0Re6LlmmHlf_17W1U3l_1WoE58F0i29EWBfGUHQyvdW_1suuBT3UrJEhXVEPa1g6YpOkLTok93z5CvDTm8hHxjyJNLyFNDvu2TFZKq_14h5LqtT_1LZJQdsvi2SBOauh17Kg7V5XULD3J63hWLWCYwODtpVd_0lsxU5szoxjDXJ8tYoKaC88HWUp1usvOXHtQgNLkjBGD03n1PwBBGLfL


#include "./TwitterSource.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR TwitterSource_Base
#define MY_OPERATOR TwitterSource$OP





#include <dlfcn.h>

#include <SPL/Toolkit/JavaOp.h>
#include <SPL/Toolkit/RuntimeException.h>

MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
{
  /* Get a handle to the Java virtual machine */
  SPL::JNI::JVMControl *jvmControl = SPL::JNI::JVMControl::getJVM();
   
  /* Attach to the JVM  for the duration of the initialization */
  JNIEnv * env = jvmControl->attach();

  /* How we invoke methods against an OperatorSetup instance */
  SPL::JNI::OpSetupInvoker* osi = jvmControl->getOpSetupInvoker();

  /* OperatorSetup instance specific to this operator */
  jobject setup = osi->newSetup(env, this); 

  /**
     Pass the parameters into my OperatorSetup instance.
  */
     osi->setParameter(env, setup, "className", SPL::rstring("com.ibm.streamsx.inet.http.HTTPStreamReader"));
   osi->setParameter(env, setup, "classLibrary", (SPL::Functions::Utility::getToolkitDirectory(SPL::rstring("com.ibm.streamsx.inet")) + SPL::rstring("/impl/lib/com.ibm.streamsx.inet.jar")));
   osi->setParameter(env, setup, "classLibrary", (SPL::Functions::Utility::getToolkitDirectory(SPL::rstring("com.ibm.streamsx.inet")) + SPL::rstring("/opt/downloaded/*")));
   osi->setParameter(env, setup, "url", lit$0);
   osi->setParameter(env, setup, "authenticationType", lit$1);
   osi->setParameter(env, setup, "authenticationProperty", (lit$3 + lit$2));
   osi->setParameter(env, setup, "authenticationProperty", (lit$5 + lit$4));
   osi->setParameter(env, setup, "authenticationProperty", (lit$7 + lit$6));
   osi->setParameter(env, setup, "authenticationProperty", (lit$9 + lit$8));
   osi->setParameter(env, setup, "retryOnClose", lit$10);
   osi->setParameter(env, setup, "retryDelay", lit$11);
   osi->setParameter(env, setup, "maxRetries", lit$12);
   osi->setParameter(env, setup, "vmArg", lit$13);


  /**
    Pass input port information into the Java operator.
 
    Are logic clauses present.
   
    Pass the windowing information for each port as
    a list of values for the parameter '[window].N' where
    N is the index of the windowed input port.
  */
   hasTupleLogic = false;


  
  /* At this point all the initialization information has been
     passed to OperatorSetup. Create a JNIBridge instance object
     we use to communicate with the user's Operator implementation
     at runtime.
  */
  
  _bi = jvmControl->getBridgeInvoker();
  _bridge = _bi->newBridge(env, this, setup);
        
  /* Completed Java initialization, detach from the JVM */
  jvmControl->detach();

  setupStateHandler();

  void * handle = dlopen("libstreams-stdtk-javaop.so", RTLD_LAZY);
  if (!handle) {
    const FormattableMessage& m = SPL_APPLICATION_RUNTIME_EXCEPTION("libstreams-stdtk-javaop.so");
    THROW_STRING(SPLRuntimeJavaOperator, m);
  }
  _fp = (FP) dlsym(handle, "callProcessTupleWithNativeByteBuffer");
}

MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR() 
{
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::setupStateHandler()
{
    _stateHandler.reset(new SPL::JNI::JavaOpStateHandler(_bi, _bridge));
    getContext().registerStateHandler(*_stateHandler);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::allPortsReady() 
{
    _bi->allPortsReady(_bridge);
    createThreads(1);
}
 
void MY_OPERATOR_SCOPE::MY_OPERATOR::prepareToShutdown() 
{
   _bi->shutdown(_bridge);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(uint32_t idx)
{
   _bi->complete(_bridge);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple & tuple, uint32_t port)
{
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{
   _bi->processTuple(_bridge, tuple, port);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port)
{
   _bi->processPunctuation(_bridge, punct, port);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("TwitterSource",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator() {
    uint32_t index = getIndex();
    initRTC(*this, lit$0, "lit$0");
    initRTC(*this, lit$1, "lit$1");
    initRTC(*this, lit$2, "lit$2");
    initRTC(*this, lit$3, "lit$3");
    initRTC(*this, lit$4, "lit$4");
    initRTC(*this, lit$5, "lit$5");
    initRTC(*this, lit$6, "lit$6");
    initRTC(*this, lit$7, "lit$7");
    initRTC(*this, lit$8, "lit$8");
    initRTC(*this, lit$9, "lit$9");
    initRTC(*this, lit$10, "lit$10");
    initRTC(*this, lit$11, "lit$11");
    initRTC(*this, lit$12, "lit$12");
    initRTC(*this, lit$13, "lit$13");
    param$className$0 = SPL::rstring("com.ibm.streamsx.inet.http.HTTPStreamReader");
    addParameterValue ("className", SPL::ConstValueHandle(param$className$0));
    param$classLibrary$0 = (SPL::Functions::Utility::getToolkitDirectory(SPL::rstring("com.ibm.streamsx.inet")) + SPL::rstring("/impl/lib/com.ibm.streamsx.inet.jar"));
    addParameterValue ("classLibrary", SPL::ConstValueHandle(param$classLibrary$0));
    param$classLibrary$1 = (SPL::Functions::Utility::getToolkitDirectory(SPL::rstring("com.ibm.streamsx.inet")) + SPL::rstring("/opt/downloaded/*"));
    addParameterValue ("classLibrary", SPL::ConstValueHandle(param$classLibrary$1));
    addParameterValue ("url", SPL::ConstValueHandle(lit$0));
    addParameterValue ("authenticationType", SPL::ConstValueHandle(lit$1));
    param$authenticationProperty$0 = (lit$3 + lit$2);
    addParameterValue ("authenticationProperty", SPL::ConstValueHandle(param$authenticationProperty$0));
    param$authenticationProperty$1 = (lit$5 + lit$4);
    addParameterValue ("authenticationProperty", SPL::ConstValueHandle(param$authenticationProperty$1));
    param$authenticationProperty$2 = (lit$7 + lit$6);
    addParameterValue ("authenticationProperty", SPL::ConstValueHandle(param$authenticationProperty$2));
    param$authenticationProperty$3 = (lit$9 + lit$8);
    addParameterValue ("authenticationProperty", SPL::ConstValueHandle(param$authenticationProperty$3));
    addParameterValue ("retryOnClose", SPL::ConstValueHandle(lit$10));
    addParameterValue ("retryDelay", SPL::ConstValueHandle(lit$11));
    addParameterValue ("maxRetries", SPL::ConstValueHandle(lit$12));
    addParameterValue ("vmArg", SPL::ConstValueHandle(lit$13));
    (void) getParameters(); // ensure thread safety by initializing here
}
MY_BASE_OPERATOR::~MY_BASE_OPERATOR()
{
    for (ParameterMapType::const_iterator it = paramValues_.begin(); it != paramValues_.end(); it++) {
        const ParameterValueListType& pvl = it->second;
        for (ParameterValueListType::const_iterator it2 = pvl.begin(); it2 != pvl.end(); it2++) {
            delete *it2;
        }
    }
}



void MY_BASE_OPERATOR::checkpointStateVariables(NetworkByteBuffer & opstate) const {
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
}

bool MY_BASE_OPERATOR::hasStateVariables() const {
    return false;
}

void MY_BASE_OPERATOR::resetToInitialStateRaw() {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->resetToInitialState();
    }
    resetStateVariablesToInitialState();
}

void MY_BASE_OPERATOR::checkpointRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->checkpoint(ckpt);
    }
    checkpointStateVariables(ckpt);
}

void MY_BASE_OPERATOR::resetRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->reset(ckpt);
    }
    resetStateVariables(ckpt);
}




