// eJzVVt1P2zAQl1_15KwxCKKFVSfrFCIOpVNoDa6FTi_1ZYhdYEr2kcJS6Fov7v80fSJrFTyrSXuS_129Xz3u_1PdLxeHfm1BsY_1pm_0N0FzElc2ADi_13q4KhWO6NvITq7QbfLqD8k9btucD96WN2P4tnLavky6FkkXP0e3Y2Gr7crr9PxVp0fnU7t_0Uhzd_1gwi4c_1l_1Zdd3Xbs4J_0d_0gPRkMrvPFuXOJ5Y5tfq4OYuhQd4wBT7Pp4haZgOOg5ziMhPnKD_1MEGDPex3U4uxXN3MpuSZaLl45h_0LeyimEY48OA1vAbAPhf3LZD9C0ibGlk971zIGhq9pkavJWU4oI26lLSlZJERnWuMfdEYu1CM2doYdEHYdfVyQxU1VVFLBWy3C_0jAGZ2HICAB4hXE6wiHJNqkeP9aAHMQiSp8P4Bs4SdoZD0Zh0qZmCYUqny9b3bqia8JCWIKS0vjBFI0D49JGLJAAgqvoOMIle_0LYEIxu8zOQtlxKJmhgPk3RCVVoUhLNY_1WFNVjXio4nkiUaGpgOI6AOcYURS5lmsxIBlIOYu0ReTgwzMuc0mFRCwXTgk6lYmryU8hRAukE4mkWwWnGjhqbPvN7vgBztCTRNN4v9RlY8gEaugdoah4gXaqTLvF9lB7cMGSp6xsFmqlucO4wPSXwHearfz8WFW_1HEvA3d40koDj0xxO3kN9qed550TF1YxOXzGeLFU28eJxjCg2OSkrbTLqGy2fsI8P6VHIf0g9OyPxS_0Z69wBA9dA4r8F_0hN0tQrRVpXpI_1KVTDHkVQ89a4vLClTF4Yc5dOnhPVC6m67Qdd55eFpLBA2hqFcsyRgNQ5VJW2HCBUVALY3Zon2d48Ta1cfkC4eiL4NP1xX8xtikAJmMe7_0TMfaDnRFWLOkl3iLw2zvMTLLX_0cUe5IUNlutouQh177vKYGKPKN5Lta8xAdT13qGqxVZQPZNuugBLzJtnI_0KGuFdG0KtnLF7HzAh3HCuhK2yWKQo4UJv8ldEzpy09jhVu1CvVSV_1O_0cmiZbS6t2awevrguUsz5YHwA2NfMSAOmgRwl1_1dESIRoDPq61m2IUI9pRbL_1gxTzGhvOURn7xSDYOLSDCAXI0tJizP_0kdJAv


#ifndef SPL_OPER_INSTANCE_MATCHES_H_
#define SPL_OPER_INSTANCE_MATCHES_H_

#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
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

#include "../type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA.h"
#include "../type/BeJwrMSo2SUksSQw1NCzJL0nMCSlPTS0pBgBaogg_1.h"

#include <bitset>

#define MY_OPERATOR Matches$OP
#define MY_BASE_OPERATOR Matches_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSo2SUksSQw1NCzJL0nMCSlPTS0pBgBaogg_1 IPort0Type;
    typedef SPL::BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple & tuple, uint32_t port);
    void processRaw(Tuple & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    
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
    SPL::boolean lit$2;
    SPL::rstring lit$3;
    SPL::boolean lit$4;
    SPL::int32 lit$5;
    SPL::uint32 lit$6;
    SPL::rstring lit$7;
    SPL::boolean lit$8;
    SPL::int32 lit$9;
    SPL::rstring lit$10;
    SPL::rstring lit$11;
    SPL::int32 lit$12;
    SPL::int32 lit$13;
    SPL::int32 lit$14;
    SPL::uint32 lit$15;
    SPL::boolean lit$16;
    
    SPL::boolean state$initialized;
    SPL::list<SPL::list<SPL::rstring > > state$smackdown;
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
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
   MY_OPERATOR() {}
   
       void getCheckpoint(NetworkByteBuffer & opstate) { checkpointStateVariables(opstate); }
       void restoreCheckpoint(NetworkByteBuffer & opstate) { restoreStateVariables(opstate); }
   
   
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_MATCHES_H_

