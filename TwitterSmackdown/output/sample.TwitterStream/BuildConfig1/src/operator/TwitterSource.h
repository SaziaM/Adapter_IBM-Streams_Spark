// eJzFVF1vmzAU1f0nFdpDskl8JDRteEuTddWUbWlJf4CBu8Qt2MjcNOXf1yEmEsyp8jbxxOEcfI6vj1NZuDwp3IoUsqJ6d7lAcrdEZRQ9rNerH0hx8wkC8PUTgOO6HtUlenf4c69_0xftR_1PxaxY_0Ps8Xy_03wh3K1z4IWQc_1riQ7xaRpHSv_0diAw0WWLCRBRtbsNCCXVuwiQW7sWC3Fmxq82yCJFLmyIQBTZK_1uWQ0CQ1oonBB45GB_0knAo6IEIQX6MIU0Z1X1mxUIvZ3pbt7ASc_1Oyj2M6jinJ2QZKmcIM9KyZEd4rxCPiyx5opiqYdRfZ9C83_09ESlyKKoqeiWvndRRtkNY68yunBVeYklT14AJXznB49e2qS_1R4UeZezhPPHuSFadt93_1_1FqCzJy_0Re6LlmmHlf_17W1U3l_1WoE58F0i29EWBfGUHQyvdW_1suuBT3UrJEhXVEPa1g6YpOkLTok93z5CvDTm8hHxjyJNLyFNDvu2TFZKq_14h5LqtT_1LZJQdsvi2SBOauh17Kg7V5XULD3J63hWLWCYwODtpVd_0lsxU5szoxjDXJ8tYoKaC88HWUp1usvOXHtQgNLkjBGD03n1PwBBGLfL

#include <SPL/Toolkit/JavaOp.h>


#ifndef SPL_OPER_INSTANCE_TWITTERSOURCE_H_
#define SPL_OPER_INSTANCE_TWITTERSOURCE_H_

#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMSw2SUksSQQADLECDn.h"


#define MY_OPERATOR TwitterSource$OP
#define MY_BASE_OPERATOR TwitterSource_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSw2SUksSQQADLECDn OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::rstring lit$0;
    SPL::rstring lit$1;
    SPL::rstring lit$2;
    SPL::rstring lit$3;
    SPL::rstring lit$4;
    SPL::rstring lit$5;
    SPL::rstring lit$6;
    SPL::rstring lit$7;
    SPL::rstring lit$8;
    SPL::rstring lit$9;
    SPL::boolean lit$10;
    SPL::float64 lit$11;
    SPL::int32 lit$12;
    SPL::rstring lit$13;
    
    
protected:
    Mutex $svMutex;
    SPL::rstring param$className$0;
    SPL::rstring param$classLibrary$0;
    SPL::rstring param$classLibrary$1;
    SPL::rstring param$authenticationProperty$0;
    SPL::rstring param$authenticationProperty$1;
    SPL::rstring param$authenticationProperty$2;
    SPL::rstring param$authenticationProperty$3;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const;
    void restoreStateVariables(NetworkByteBuffer & opstate);
    void checkpointStateVariables(Checkpoint & ckpt);
    void resetStateVariables(Checkpoint & ckpt);
    void resetStateVariablesToInitialState();
    bool hasStateVariables() const;
    void resetToInitialStateRaw();
    void checkpointRaw(Checkpoint & ckpt);
    void resetRaw(Checkpoint & ckpt);
private:
    static bool globalInit_;
    static bool globalIniter();
    ParameterMapType paramValues_;
    ParameterMapType& getParameters() { return paramValues_;}
    void addParameterValue(std::string const & param, ConstValueHandle const& value)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create(value));
    }
    void addParameterValue(std::string const & param)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create());
    }
};


class MY_OPERATOR : public MY_BASE_OPERATOR 
{
public:
  // constructor
  MY_OPERATOR();

  // destructor
  virtual ~MY_OPERATOR(); 

  // notify port readiness
  void allPortsReady(); 

  // notify termination
  void prepareToShutdown(); 

  // processing for source and threaded operators   
  void process(uint32_t idx);
    
  // tuple processing for mutating ports 
  void process(Tuple & tuple, uint32_t port);
    
  // tuple processing for non-mutating ports
  void process(Tuple const & tuple, uint32_t port);

  // punctuation processing
  void process(Punctuation const & punct, uint32_t port);
private:
  void setupStateHandler();

  // members
  
  /** How we invoke actions on the Java Operator implementation */
  SPL::JNI::JNIBridgeInvoker* _bi;
  
  /* The instance of the JNIBridge used to wrap the Java Operator implementation */
  jobject _bridge;

  typedef void (*FP)(SPL::JNI::JNIBridgeInvoker&, jobject, NativeByteBuffer &, uint32_t);
  FP _fp;
  
  bool hasTupleLogic;
  
  std::tr1::shared_ptr<SPL::StateHandler> _stateHandler;

public:
  virtual void javaopInternalAction(Punctuation const & punct, uint32_t port)
  {
     _bi->action(_bridge, punct, port);
  }
    
  // handle byte buffers being sent as is
  virtual void processRaw(NativeByteBuffer & buffer, uint32_t port)
  {
     (*_fp)(*_bi, _bridge, buffer, port);
  }
  
  //Java operators handle byte buffers directly
  virtual bool sendRawBufferData() { return !hasTupleLogic; }

  // Requests the blocking of a consistent region permit
  virtual void blockConsistentRegionPermit() {
      _bi->blockConsistentRegionPermit(_bridge);
  }
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_TWITTERSOURCE_H_

