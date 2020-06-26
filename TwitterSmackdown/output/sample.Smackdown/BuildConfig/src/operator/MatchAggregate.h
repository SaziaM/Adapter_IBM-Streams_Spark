// eJylUstuwjAQ1P4K6gEuIYZbbgb1UEohVVKhnioXXOMSP2RveOTr66RENKqQiirfdmdmZ2ftbRE5XjCURrMiSagQjguGHAjE4Y2gF0VDPFk_0nPDZwT1lZrSY6mX_0Ui1zv9tXh306j42tPvNFnh1nlaBUVPSR0mjb_0zs3bbg7gRMxff14dqxm19MLiXcxZOk8SaTG8QiaCulUYIjKgjaaxzAG1m7woNdG2YIjX0m9MQcPZ9q7MQVnOuijKzlMjfbINIJwprSTUwtzHp3UIsCkNS7YiATHN6_1YehfU9Mq4je8P4P5oHfc_05AeWOZR1kv8RIRfst8SNuYMEFyQIQanCFX8ERc5phuaVXj0bQupdf9AuoRiut9ASYjC32Px1YlDB6NVZhOpbQ2zscd8azEoFnY_1SpTfo_1iDs8QW41vcu

#ifndef MatchAggregate$MyTuple_H
#define MatchAggregate$MyTuple_H
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Serialization/ByteBuffer.h>
#include "../type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA.h"
#include "../type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTPTSxJzkgtBgCYfQra.h"

class MatchAggregate$MyTuple {
public:
  MatchAggregate$MyTuple() {}


  MatchAggregate$MyTuple(const MatchAggregate$MyTuple & o) :
    field0_(o.field0_),
    field1_(o.field1_)
  {}

  MatchAggregate$MyTuple(
    const SPL::rstring & field0,
    const SPL::int32 & field1
  ) :
    field0_(field0),
    field1_(field1)
  {}

  SPL::rstring & get_field0() {
    return field0_;
  }

  SPL::rstring const & get_field0() const {
    return field0_;
  }

  SPL::int32 & get_field1() {
    return field1_;
  }

  SPL::int32 const & get_field1() const {
    return field1_;
  }

  const MatchAggregate$MyTuple & operator=(MatchAggregate$MyTuple const & o) {
    if(this==&o) return *this;
    field0_ = o.field0_;
    field1_ = o.field1_;
    return *this;
  }

  bool operator==(MatchAggregate$MyTuple const & o) const {
    if(field0_ != o.field0_) return false;
    if(field1_ != o.field1_) return false;
    return true;
  }

  bool operator!=(MatchAggregate$MyTuple const & o) const {
    return !(*this==o);
  }

  size_t hashCode() const {
    size_t r = 17;
    size_t c;
    c = std::tr1::hash<SPL::rstring >()(field0_);
    r = 37 * r + c;
    c = std::tr1::hash<SPL::int32 >()(field1_);
    r = 37 * r + c;
    return r;
  }

  template <class S>
  void serialize(SPL::ByteBuffer<S> & buf) const {
    buf << field0_;
    buf << field1_;
  }

  template <class S>
  void deserialize(SPL::ByteBuffer<S> & buf) {
    buf >> field0_;
    buf >> field1_;
  }

  SPL::rstring field0_;
  SPL::int32 field1_;
};
template <class S>
inline SPL::ByteBuffer<S> & operator<<(SPL::ByteBuffer<S> & buf, const MatchAggregate$MyTuple & v)
{
    v.serialize(buf); return buf;
}
template <class S>
inline SPL::ByteBuffer<S> & operator>>(SPL::ByteBuffer<S> & buf, MatchAggregate$MyTuple & v)
{
    v.deserialize(buf); return buf;
}

namespace std {
  namespace tr1 {
    template <>
    struct hash<MatchAggregate$MyTuple > {
      size_t operator()(MatchAggregate$MyTuple const & val) const {
        return val.hashCode();
      }
    };
  }
}

namespace SPL {
  std::ostream & operator<<(std::ostream & ostr, MatchAggregate$MyTuple const & x) {
    ostr << x.get_field0();
    ostr << x.get_field1();
    return ostr;
  }

}

#endif /* MatchAggregate$MyTuple_H */

#ifndef MatchAggregate$PartitionByType_H
#define MatchAggregate$PartitionByType_H
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Serialization/ByteBuffer.h>
#include "../type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA.h"
#include "../type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTPTSxJzkgtBgCYfQra.h"

class MatchAggregate$PartitionByType {
public:
  MatchAggregate$PartitionByType() {}


  MatchAggregate$PartitionByType(const MatchAggregate$PartitionByType & o) :
    field0_(o.field0_)
  {}

  MatchAggregate$PartitionByType(
    const SPL::rstring & field0
  ) :
    field0_(field0)
  {}

  SPL::rstring & get_field0() {
    return field0_;
  }

  SPL::rstring const & get_field0() const {
    return field0_;
  }

  const MatchAggregate$PartitionByType & operator=(MatchAggregate$PartitionByType const & o) {
    if(this==&o) return *this;
    field0_ = o.field0_;
    return *this;
  }

  bool operator==(MatchAggregate$PartitionByType const & o) const {
    if(field0_ != o.field0_) return false;
    return true;
  }

  bool operator!=(MatchAggregate$PartitionByType const & o) const {
    return !(*this==o);
  }

  size_t hashCode() const {
    size_t r = 17;
    size_t c;
    c = std::tr1::hash<SPL::rstring >()(field0_);
    r = 37 * r + c;
    return r;
  }

  template <class S>
  void serialize(SPL::ByteBuffer<S> & buf) const {
    buf << field0_;
  }

  template <class S>
  void deserialize(SPL::ByteBuffer<S> & buf) {
    buf >> field0_;
  }

  SPL::rstring field0_;
};
template <class S>
inline SPL::ByteBuffer<S> & operator<<(SPL::ByteBuffer<S> & buf, const MatchAggregate$PartitionByType & v)
{
    v.serialize(buf); return buf;
}
template <class S>
inline SPL::ByteBuffer<S> & operator>>(SPL::ByteBuffer<S> & buf, MatchAggregate$PartitionByType & v)
{
    v.deserialize(buf); return buf;
}

namespace std {
  namespace tr1 {
    template <>
    struct hash<MatchAggregate$PartitionByType > {
      size_t operator()(MatchAggregate$PartitionByType const & val) const {
        return val.hashCode();
      }
    };
  }
}

namespace SPL {
  std::ostream & operator<<(std::ostream & ostr, MatchAggregate$PartitionByType const & x) {
    ostr << x.get_field0();
    return ostr;
  }

}

#endif /* MatchAggregate$PartitionByType_H */

#ifndef MatchAggregate$GroupByType_H
#define MatchAggregate$GroupByType_H
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Serialization/ByteBuffer.h>
#include "../type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA.h"
#include "../type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTPTSxJzkgtBgCYfQra.h"

class MatchAggregate$GroupByType {
public:
  MatchAggregate$GroupByType() {}


  MatchAggregate$GroupByType(const MatchAggregate$GroupByType & o) :
    field0_(o.field0_)
  {}

  MatchAggregate$GroupByType(
    const SPL::rstring & field0
  ) :
    field0_(field0)
  {}

  SPL::rstring & get_field0() {
    return field0_;
  }

  SPL::rstring const & get_field0() const {
    return field0_;
  }

  const MatchAggregate$GroupByType & operator=(MatchAggregate$GroupByType const & o) {
    if(this==&o) return *this;
    field0_ = o.field0_;
    return *this;
  }

  bool operator==(MatchAggregate$GroupByType const & o) const {
    if(field0_ != o.field0_) return false;
    return true;
  }

  bool operator!=(MatchAggregate$GroupByType const & o) const {
    return !(*this==o);
  }

  size_t hashCode() const {
    size_t r = 17;
    size_t c;
    c = std::tr1::hash<SPL::rstring >()(field0_);
    r = 37 * r + c;
    return r;
  }

  template <class S>
  void serialize(SPL::ByteBuffer<S> & buf) const {
    buf << field0_;
  }

  template <class S>
  void deserialize(SPL::ByteBuffer<S> & buf) {
    buf >> field0_;
  }

  SPL::rstring field0_;
};
template <class S>
inline SPL::ByteBuffer<S> & operator<<(SPL::ByteBuffer<S> & buf, const MatchAggregate$GroupByType & v)
{
    v.serialize(buf); return buf;
}
template <class S>
inline SPL::ByteBuffer<S> & operator>>(SPL::ByteBuffer<S> & buf, MatchAggregate$GroupByType & v)
{
    v.deserialize(buf); return buf;
}

namespace std {
  namespace tr1 {
    template <>
    struct hash<MatchAggregate$GroupByType > {
      size_t operator()(MatchAggregate$GroupByType const & val) const {
        return val.hashCode();
      }
    };
  }
}

namespace SPL {
  std::ostream & operator<<(std::ostream & ostr, MatchAggregate$GroupByType const & x) {
    ostr << x.get_field0();
    return ostr;
  }

}

#endif /* MatchAggregate$GroupByType_H */




#ifndef SPL_OPER_INSTANCE_MATCHAGGREGATE_H_
#define SPL_OPER_INSTANCE_MATCHAGGREGATE_H_

#include <SPL/Runtime/Common/Metric.h>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Window/Window.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA.h"
#include "../type/BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTPTSxJzkgtBgCYfQra.h"

#include <bitset>

#define MY_OPERATOR MatchAggregate$OP
#define MY_BASE_OPERATOR MatchAggregate_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA IPort0Type;
    typedef SPL::BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTPTSxJzkgtBgCYfQra OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
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
    
    
    
    SPL::int32 lit$0;
    SPL::int32 lit$1;
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
    SPL::boolean param$aggregateIncompleteWindows$0;
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
 

class MY_OPERATOR : public MY_BASE_OPERATOR, 
                    public SPL::WindowEvent<MatchAggregate$MyTuple*, MatchAggregate$PartitionByType>,
                    public StateHandler
{
public:
    typedef MatchAggregate$GroupByType GroupByType; 
    
    typedef MatchAggregate$MyTuple ProjectedTupleType;
    
    typedef MatchAggregate$PartitionByType PartitionByType; 
    typedef SPL::SlidingWindow<ProjectedTupleType*, PartitionByType> WindowType;
    typedef SPL::WindowEvent<ProjectedTupleType*, PartitionByType> WindowEventType;
    MY_OPERATOR();
    ~MY_OPERATOR();
    void process(Tuple const & tuple, uint32_t port); 




    void onWindowTriggerEvent(WindowEventType::WindowType & window, 
                              WindowEventType::PartitionType const & partition);

    void beforeTupleEvictionEvent(WindowEventType::WindowType & window, 
                                  WindowEventType::TupleType & tuple, 
                                  WindowEventType::PartitionType const & partition);



    // StateHandler implementation
    void drain();
    void checkpoint(Checkpoint & ckpt);
    void reset(Checkpoint & ckpt);
    void resetToInitialState();

private:
    void aggregatePartition(WindowEventType::WindowType & window, 
                            WindowEventType::PartitionType const & partition);

    WindowType _window;
    Mutex    _mutex;

    Metric& _partitionCount;
    
}; 
 
} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_MATCHAGGREGATE_H_

