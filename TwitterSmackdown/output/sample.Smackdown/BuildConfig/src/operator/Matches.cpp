// eJzVVt1P2zAQl1_15KwxCKKFVSfrFCIOpVNoDa6FTi_1ZYhdYEr2kcJS6Fov7v80fSJrFTyrSXuS_129Xz3u_1PdLxeHfm1BsY_1pm_0N0FzElc2ADi_13q4KhWO6NvITq7QbfLqD8k9btucD96WN2P4tnLavky6FkkXP0e3Y2Gr7crr9PxVp0fnU7t_0Uhzd_1gwi4c_1l_1Zdd3Xbs4J_0d_0gPRkMrvPFuXOJ5Y5tfq4OYuhQd4wBT7Pp4haZgOOg5ziMhPnKD_1MEGDPex3U4uxXN3MpuSZaLl45h_0LeyimEY48OA1vAbAPhf3LZD9C0ibGlk971zIGhq9pkavJWU4oI26lLSlZJERnWuMfdEYu1CM2doYdEHYdfVyQxU1VVFLBWy3C_0jAGZ2HICAB4hXE6wiHJNqkeP9aAHMQiSp8P4Bs4SdoZD0Zh0qZmCYUqny9b3bqia8JCWIKS0vjBFI0D49JGLJAAgqvoOMIle_0LYEIxu8zOQtlxKJmhgPk3RCVVoUhLNY_1WFNVjXio4nkiUaGpgOI6AOcYURS5lmsxIBlIOYu0ReTgwzMuc0mFRCwXTgk6lYmryU8hRAukE4mkWwWnGjhqbPvN7vgBztCTRNN4v9RlY8gEaugdoah4gXaqTLvF9lB7cMGSp6xsFmqlucO4wPSXwHearfz8WFW_1HEvA3d40koDj0xxO3kN9qed550TF1YxOXzGeLFU28eJxjCg2OSkrbTLqGy2fsI8P6VHIf0g9OyPxS_0Z69wBA9dA4r8F_0hN0tQrRVpXpI_1KVTDHkVQ89a4vLClTF4Yc5dOnhPVC6m67Qdd55eFpLBA2hqFcsyRgNQ5VJW2HCBUVALY3Zon2d48Ta1cfkC4eiL4NP1xX8xtikAJmMe7_0TMfaDnRFWLOkl3iLw2zvMTLLX_0cUe5IUNlutouQh177vKYGKPKN5Lta8xAdT13qGqxVZQPZNuugBLzJtnI_0KGuFdG0KtnLF7HzAh3HCuhK2yWKQo4UJv8ldEzpy09jhVu1CvVSV_1O_0cmiZbS6t2awevrguUsz5YHwA2NfMSAOmgRwl1_1dESIRoDPq61m2IUI9pRbL_1gxTzGhvOURn7xSDYOLSDCAXI0tJizP_0kdJAv


#include "./Matches.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR Matches_Base
#define MY_OPERATOR Matches$OP



static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("Matches",&initer));
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
    initRTC(*this, lit$14, "lit$14");
    initRTC(*this, lit$15, "lit$15");
    initRTC(*this, lit$16, "lit$16");
    state$initialized = lit$16;
    SPLAPPTRC(L_DEBUG, "Variable: state$initialized Value: " << state$initialized,SPL_OPER_DBG);
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

void MY_BASE_OPERATOR::tupleLogic(Tuple & tuple, uint32_t port) {
    IPort0Type & iport$0 = static_cast<IPort0Type  &>(tuple);
    AutoPortMutex $apm($svMutex, *this);
    
{
    if (SPL::boolean(!state$initialized)) 
        {
            {
                const SPL::list<SPL::rstring > & temp$opponent = ::SPL::Functions::String::tokenize(lit$0, lit$1, (SPL::boolean)lit$2);
                for (SPL::list<SPL::rstring >::const_iterator it$opponent = temp$opponent.begin(); it$opponent != temp$opponent.end(); it$opponent++) {
                    const SPL::rstring& id$opponent = *it$opponent;
                    {
                        const SPL::list<SPL::rstring > id$words = ::SPL::Functions::String::tokenize(id$opponent, lit$3, (SPL::boolean)lit$4);
                        ::SPL::Functions::Collections::appendM(state$smackdown, id$words);
                        do { SPL::BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA temp = SPL::BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA(::SPL::spl_cast<SPL::rstring, SPL::list<SPL::rstring > >::cast(id$words), lit$5); submit (temp, lit$6); } while(0);
                        ::SPL::Functions::Utility::printStringLn((lit$7 + ::SPL::spl_cast<SPL::rstring, SPL::list<SPL::rstring > >::cast(id$words)));
                    }
                }
            }
            state$initialized = lit$8;
        }
    SPL::int32 id$match = lit$9;
    {
        for (SPL::list<SPL::list<SPL::rstring > >::const_iterator it$words = state$smackdown.begin(); it$words != state$smackdown.end(); it$words++) {
            const SPL::list<SPL::rstring >& id$words = *it$words;
            {
                {
                    for (SPL::list<SPL::rstring >::const_iterator it$word = id$words.begin(); it$word != id$words.end(); it$word++) {
                        const SPL::rstring& id$word = *it$word;
                        {
                            const SPL::list<SPL::rstring > id$tokens = ::SPL::Functions::String::regexMatchPerl(iport$0.get_data(), ((lit$11 + id$word) + lit$10));
                            id$match += ((::SPL::Functions::Collections::size(id$tokens) > lit$12) ? lit$14 : lit$13);
                        }
                    }
                }
                do { SPL::BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA temp = SPL::BeJwrMSo2NCnOTUzOTskvzwvPL0opzjTNTSxJzgAAgzAKAA(::SPL::spl_cast<SPL::rstring, SPL::list<SPL::rstring > >::cast(id$words), id$match); submit (temp, lit$15); } while(0);
            }
        }
    }
}

}


void MY_BASE_OPERATOR::processRaw(Tuple & tuple, uint32_t port) {
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
    opstate << state$initialized;
    opstate << state$smackdown;
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
    opstate >> state$initialized;
    opstate >> state$smackdown;
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
    ckpt << state$initialized;
    ckpt << state$smackdown;
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
    ckpt >> state$initialized;
    ckpt >> state$smackdown;
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
    state$initialized = lit$16;
    SPLAPPTRC(L_DEBUG, "Variable: state$initialized Value: " << state$initialized,SPL_OPER_DBG);
    state$smackdown = SPL::list<SPL::list<SPL::rstring > >();
}

bool MY_BASE_OPERATOR::hasStateVariables() const {
    return true;
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



