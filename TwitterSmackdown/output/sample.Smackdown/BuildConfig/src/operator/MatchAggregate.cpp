// eJylUstuwjAQ1P4K6gEuIYZbbgb1UEohVVKhnioXXOMSP2RveOTr66RENKqQiirfdmdmZ2ftbRE5XjCURrMiSagQjguGHAjE4Y2gF0VDPFk_0nPDZwT1lZrSY6mX_0Ui1zv9tXh306j42tPvNFnh1nlaBUVPSR0mjb_0zs3bbg7gRMxff14dqxm19MLiXcxZOk8SaTG8QiaCulUYIjKgjaaxzAG1m7woNdG2YIjX0m9MQcPZ9q7MQVnOuijKzlMjfbINIJwprSTUwtzHp3UIsCkNS7YiATHN6_1YehfU9Mq4je8P4P5oHfc_05AeWOZR1kv8RIRfst8SNuYMEFyQIQanCFX8ERc5phuaVXj0bQupdf9AuoRiut9ASYjC32Px1YlDB6NVZhOpbQ2zscd8azEoFnY_1SpTfo_1iDs8QW41vcu




#include "./MatchAggregate.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR MatchAggregate_Base
#define MY_OPERATOR MatchAggregate$OP


#include <SPL/Toolkit/Aggregate.h>

#include <SPL/Runtime/Operator/OperatorMetrics.h>

#include <memory>



MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
  : MY_BASE_OPERATOR(), _window(*this, 0, ::SPL::TimeWindowPolicy(lit$0), ::SPL::TimeWindowPolicy(lit$1)),
  _partitionCount(getContext().getMetrics().getCustomMetricByName("nCurrentPartitions")) 
{

    _window.registerOnWindowTriggerHandler(this);
    
    _window.registerBeforeTupleEvictionHandler(this);

    
    _partitionCount.setValueNoLock(0);
}

MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR()
{
    // Delete any remaining tuples in the window
    _window.deleteWindowObjects();
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::drain() 
{
    SPLAPPTRC(L_DEBUG, "Before draining window", SPL_OPER_DBG);
    _window.drain();
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::checkpoint(Checkpoint & ckpt) 
{
    AutoMutex am(_mutex);

    SPLAPPTRC(L_TRACE, "Before checkpoint window is: " << _window.toString(), SPL_OPER_DBG);
    _window.checkpoint(ckpt);

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::reset(Checkpoint & ckpt)
{
    AutoMutex am(_mutex);

    _window.reset(ckpt);
    SPLAPPTRC(L_TRACE, "After reset window is: " << _window.toString(), SPL_OPER_DBG);

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::resetToInitialState()
{
    AutoMutex am(_mutex);

    SPLAPPTRC(L_DEBUG, "Resetting window to initial state", SPL_OPER_DBG);
    _window.resetToInitialState();

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) 
{

    AutoPortMutex apm(_mutex, *this);

    IPort0Type const & iport$0 = static_cast<IPort0Type const&>(tuple);


PartitionByType partition(iport$0.get_smackdownWords());

    ProjectedTupleType *projected = NULL;
    projected = new ProjectedTupleType(iport$0.get_smackdownWords(),
iport$0.get_match());
    _window.insert(projected, partition);

    _partitionCount.setValueNoLock(_window.getWindowStorage().size());
}



void MY_OPERATOR_SCOPE::MY_OPERATOR::onWindowTriggerEvent(
        WindowEventType::WindowType & window, 
        WindowEventType::PartitionType const & partition) 
{
    aggregatePartition(window, partition);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::aggregatePartition(
        WindowEventType::WindowType & window, 
        WindowEventType::PartitionType const & partition) 
{
    



    
        WindowType::DataType & data = window.getWindowData(partition);
        if (data.size() == 0) {
    
            submit(Punctuation::WindowMarker, 0);
            return;
        }


    
      
        typedef std::vector<ProjectedTupleType const*> GroupMapDataType;
        typedef std::tr1::unordered_map<GroupByType, GroupMapDataType> GroupMapType;
        GroupMapType _groupMap;
        // Walk the data, adding to the right groups
        WindowType::DataType::const_iterator it;
        for (it = data.begin(); it != data.end(); it++) {
          
            ProjectedTupleType const & projTuple = **it;
          
            GroupByType key(projTuple.get_field0());
            GroupMapType::iterator git = _groupMap.find (key);
            if (git == _groupMap.end())
                git = _groupMap.insert (GroupMapType::value_type (key,
                                                    GroupMapDataType())).first;
            git->second.push_back (*it);
        }

        // Now walk the groups
        GroupMapType::const_iterator git;
        for (git = _groupMap.begin(); git != _groupMap.end(); git++) {
            const GroupMapDataType & data = git->second;
    


    

            SPL::Aggregate::Any<WindowEventType::WindowType,
                                  GroupMapDataType, SPL::rstring,
                                  ProjectedTupleType, SPL::rstring, GroupMapType> Any$smackdownWords(window, data, _groupMap);
            
                if (Any$smackdownWords.needsSeedValue()) {
                    
                    ProjectedTupleType const & projTuple = *Any$smackdownWords.getSeedRecord();
                    
                    Any$smackdownWords.setSeedValue (projTuple.get_field0());
                }
            
        

            SPL::Aggregate::Sum<WindowEventType::WindowType,
                                  GroupMapDataType, SPL::int32,
                                  ProjectedTupleType, SPL::int32, GroupMapType> Sum$matches(window, data, _groupMap);
            
                if (Sum$matches.needsSeedValue()) {
                    
                    ProjectedTupleType const & projTuple = *Sum$matches.getSeedRecord();
                    
                    Sum$matches.setSeedValue (projTuple.get_field1());
                }
            
        
        
    
    
        GroupMapDataType::const_iterator it;
        for (it = data.begin(); it != data.end(); it++) {
          
            ProjectedTupleType const & projTuple = **it;
          
            
                Sum$matches.process(projTuple.get_field1());
            
          }
    

        // Populate the tuple
        
          
            ProjectedTupleType const & projTuple = **data.rbegin();
          
        
        
        SPL::BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTPTSxJzkgtBgCYfQra otuple(Any$smackdownWords(), Sum$matches());
        submit (otuple, 0);

    }



    submit(Punctuation::WindowMarker, 0);
}




    

void MY_OPERATOR_SCOPE::MY_OPERATOR::beforeTupleEvictionEvent(WindowEventType::WindowType & window, 
                                           WindowEventType::TupleType & tuple, 
                                           WindowEventType::PartitionType const & partition)
{
    delete tuple;
    _partitionCount.setValueNoLock (_window.getWindowStorage().size());
}


static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("MatchAggregate",&initer));
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
    param$aggregateIncompleteWindows$0 = true;
    addParameterValue ("aggregateIncompleteWindows", SPL::ConstValueHandle(param$aggregateIncompleteWindows$0));
    addParameterValue ("groupBy");
    addParameterValue ("partitionBy");
    (void) getParameters(); // ensure thread safety by initializing here
    $oportBitset = OPortBitsetType(std::string("01"));
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

void MY_BASE_OPERATOR::tupleLogic(Tuple const & tuple, uint32_t port) {
}


void MY_BASE_OPERATOR::processRaw(Tuple const & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
}

void MY_BASE_OPERATOR::punctPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    {
        punctNoPermitProcessRaw(punct, port);
    }
}

void MY_BASE_OPERATOR::punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    switch(punct) {
    case Punctuation::WindowMarker:
        punctLogic(punct, port);
        process(punct, port);
        break;
    case Punctuation::FinalMarker:
        punctLogic(punct, port);
        
        if (punct == Punctuation::FinalMarker) {
            process(punct, port);
            bool forward = false;
            {
                AutoPortMutex $apm($fpMutex, *this);
                $oportBitset.reset(port);
                if ($oportBitset.none()) {
                    $oportBitset.set(1);
                    forward=true;
                }
            }
            if(forward)
                submit(punct, 0);
            return;
        }
        process(punct, port);
        break;
    case Punctuation::DrainMarker:
    case Punctuation::ResetMarker:
    case Punctuation::ResumeMarker:
        break;
    case Punctuation::SwitchMarker:
        break;
    default:
        break;
    }
}

void MY_BASE_OPERATOR::processRaw(Punctuation const & punct, uint32_t port) {
    switch(port) {
    case 0:
        punctNoPermitProcessRaw(punct, port);
        break;
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



